#include <iostream>
#include <iomanip>
#include "Agent.h"
#include "Strategic.h"
#include "AggressiveAgentStrategy.h"
#include "DefaultAgentStrategy.h"

namespace Gaming{

    const char Strategic::STRATEGIC_ID = 'T';
    Strategic::Strategic(const Game &g, const Position &p, double energy, Strategy *s)
            : Agent(g, p, energy)
    {
        // constructor. This adds a strategy pointer to a virtual class.
        __strategy = s;


    }

    Strategic::~Strategic()
    {
        // de-constructor. Destroy the strategy, the only obvious pointer
        delete __strategy;
    }

    void Strategic::print(std::ostream &os) const // does override need to go back?
    {
        // print it out, grab an out stream, something like that.
        os << STRATEGIC_ID << std::left << __id;
    }

    ActionType Strategic::takeTurn(const Surroundings &s) const
    {
        // now the ugly is in other files I can't see from here. THey need the randomize thing done though
        return(*__strategy)(s);
    }

}

