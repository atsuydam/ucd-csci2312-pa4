#include <iostream>
#include <iomanip>
#include "Game.h"
#include "Piece.h"
#include "Resource.h"
#include "Agent.h"
#include "Food.h"

namespace Gaming {

    const char Food::FOOD_ID = 'F';

    // constructor and deconstuctors
    Food::Food(const Game &g, const Position &p, double capacity)
            : Resource(g, p, capacity)
    {

        // construct something, probably the food. OR has it been constructed through the resource?
    }

    Food::~Food()
    {
        // delete something. probably the food
    }

    // one of those overridden functions
    void Food::print(std::ostream &os) const
    {
        os << FOOD_ID << std::setw(4) << std::left << __id;
    }
}