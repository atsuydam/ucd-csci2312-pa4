#include <iostream>
#include "Agent.h"
#include "Simple.h"


namespace Gaming {

    // everything must be numbered and accounted for
    const char SIMPLE_ID = 0;

    // constructor and de-constructor
    Simple::Simple(const Game &g, const Position &p, double energy)
            : Agent(g, p, energy)
    {

    }

    Simple::~Simple()
    {
        // delete something
    }

    void Simple::print(std::ostream &os) const
    {
        // print something out
    }

    ActionType Simple::takeTurn(const Surroundings &s) const
    {
        // take in the surroundings and make a decision
    }
}

