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
        os << SIMPLE_ID << std::left << __id;
    }

    ActionType Simple::takeTurn(const Surroundings &s) const
    {
        // this ugly but suffices for the test. I'll have to add the randomizer and can clean it up then
        ActionType action;
        for (int i=0; i < 9; i++)
        {
            if (i == 0)
                action = NW;
            if (i == 1)
                action = N;
            if (i == 2)
                action = NE;
            if (i == 3)
                action = W;
            if (i == 4)
                action = STAY;
            if (i == 5)
                action = E;
            if (i == 6)
                action = SW;
            if (i == 7)
                action = S;
            if (i == 8)
                action = SE;

            if (s.array[i] == FOOD || s.array[i] == ADVANTAGE)
            {
                return action;
            }
            else if (s.array[i] == EMPTY)
            {
                return action;
            }
        }
        return STAY;
    }
}

