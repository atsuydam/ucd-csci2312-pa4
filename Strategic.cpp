#include <iostream>
#include "Agent.h"
#include "Strategic.h"

namespace Gaming{

    // maybe not 0, but it makes it happy for now.
    const char STRATEGIC_ID = 0;

    Strategic::Strategic(const Game &g, const Position &p, double energy, Strategy *s = new DefaultAgentStrategy())
            : Agent(g, p, energy)
    {
        // constructor
    }

    Strategic::~Strategic()
    {
        // de-constructor. Destroy the strategy, the only obvious pointer
    }

    void Strategic::print(std::ostream &os) const // does override need to go back?
    {
        // print it out, grab an out stream, something like that.
    }

    ActionType Strategic::takeTurn(const Surroundings &s) const
    {
        // look at the surroundings and decide what to do.
    }

}

