#include <iostream>
#include "Game.h"
#include "Piece.h"
#include "Resource.h"

namespace Gaming {
    const double Resource::RESOURCE_SPOIL_FACTOR = 1.2;

    Resource::Resource(const Game &g, const Position &p, double capacity)
            : Piece (g, p)
    {
        // The rest of the resource was constructed with piece
        __capacity = capacity;
    }

    Resource::~Resource()
    {
        // Something's gonna have to be deleted
    }

    double Resource::consume()
    {
        //Nom nom nom... Find the parent to this function.
        __capacity = 0;
        finish();
    }

    void Resource::age()
    {
        __capacity = __capacity / RESOURCE_SPOIL_FACTOR;
        if (__capacity < 0.1)
            finish();
    }

    ActionType Resource::takeTurn(const Surroundings &s) const
    {
        // Action type? Surroundings? Resources don't give a shit about their surroundings and do nothing until picked up
        ActionType stay = STAY;
        return stay;
    }


    // note: these won't be called  resources don't move
    // How do I title these???
    Piece & Resource::operator*(Piece &other)
    {
        std::cout << "a\n";
        return other.interact(this);
    }

    Piece &Resource::interact(Agent *greedy)
    {
        std::cout << "2\n";
        __capacity = 0;
        finish();
    }

    Piece & Resource::interact(Resource *) // note: no interaction between resources
    {
        std::cout << "b\n";
        // "Yo, apple, what up?"
        // "Nothing axe. You?"
        // These do nothing but make inanimate faces at each other.
    }
}
