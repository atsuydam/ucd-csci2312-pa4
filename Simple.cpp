#include <iostream>
#include <iomanip>
#include "Agent.h"
#include "Simple.h"


namespace Gaming {

    const char Simple::SIMPLE_ID = 'S';
    // constructor and de-constructor
    Simple::Simple(const Game &g, const Position &p, double energy)
            : Agent(g, p, energy)
    {
        // The only thing this adds is the simple ID. Everything was initialized with Agent
    }

    Simple::~Simple()
    {
        // delete something
    }

    void Simple::print(std::ostream &os) const
    {
        // print something out
        os << "S" << std::setw(4) << std::left << __id;
    }

    ActionType Simple::takeTurn(const Surroundings &s) const
    {
        // take in the surroundings and make a decision
    }
}

