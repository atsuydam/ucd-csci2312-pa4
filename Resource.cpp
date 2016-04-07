#include <iostream>
#include "Game.h"
#include "Piece.h"
#include "Resource.h"

namespace Gaming {
    const double RESOURCE_SPOIL_FACTOR = 4;     // This is a random number, look for instructions for correct value

    Resource::Resource(const Game &g, const Position &p, double capacity)
            : Piece (g, p)
    {
        // Resource constructor. It's telling me piece doesn't have a default constructor.
    }

    Resource::~Resource()
    {
        // Something's gonna have to be deleted
    }

    virtual double Resource::consume()
    {
        //Nom nom nom... Find the parent to this function.
    }

    void Resource::age() override final
    {
        // set the age?
    }

    ActionType Resource::takeTurn(const Surroundings &s) const override
    {
        // Action type? Surroundings? Resources don't give a shit about their surroundings and do nothing until picked up
    }


    // note: these won't be called  resources don't move
    // How do I title these???
    Piece &operator*(Piece &other) override final
    {
        // Figure out what to do with that override bit that he talked about for .2 secs
    }

    Piece &interact(Agent *) override final
    {
        // agent grabs resource, it either adds to health or strength. Done.
    }

    Piece &interact(Resource *) override final // note: no interaction between resources
    {
        // "Yo, apple, what up?"
        // "Nothing axe. You?"
        // These do nothing but make inanimate faces at each other.
    }
}
