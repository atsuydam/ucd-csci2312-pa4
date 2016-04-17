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
        // this is ugly, this is long, and this doesn't use the random function but how to assign grid coordinates to
        // directions?
        return(*__strategy)(s);

//        ActionType action;
//        for (int i=0 ; i < 9; i++)
//        {
//            if (i == 0)
//                action = NW;
//            if (i == 1)
//                action = N;
//            if (i == 2)
//                action = NE;
//            if (i == 3)
//                action = W;
//            if (i == 5)
//                action = E;
//            if (i == 6)
//                action = SW;
//            if (i == 7)
//                action = S;
//            if (i == 8)
//                action = SE;
//            if (s.array[i] == ADVANTAGE) {
//                return action;
//            }
//        }
//        for (int i=0 ; i < 9; i++)
//        {
//            if (i == 0)
//                action = NW;
//            if (i == 1)
//                action = N;
//            if (i == 2)
//                action = NE;
//            if (i == 3)
//                action = W;
//            if (i == 5)
//                action = E;
//            if (i == 6)
//                action = SW;
//            if (i == 7)
//                action = S;
//            if (i == 8)
//                action = SE;
//            if (s.array[i] == FOOD) {
//                return action;
//            }
//        }
//        for (int i=0 ; i < 9; i++)
//        {
//            if (i == 0)
//                action = NW;
//            if (i == 1)
//                action = N;
//            if (i == 2)
//                action = NE;
//            if (i == 3)
//                action = W;
//            if (i == 5)
//                action = E;
//            if (i == 6)
//                action = SW;
//            if (i == 7)
//                action = S;
//            if (i == 8)
//                action = SE;
//            if (s.array[i] == EMPTY) {
//                return action;
//            }
//        }
//        for (int i=0 ; i < 9; i++)
//        {
//            if (i == 0)
//                action = NW;
//            if (i == 1)
//                action = N;
//            if (i == 2)
//                action = NE;
//            if (i == 3)
//                action = W;
//            if (i == 5)
//                action = E;
//            if (i == 6)
//                action = SW;
//            if (i == 7)
//                action = S;
//            if (i == 8)
//                action = SE;
//            if (s.array[i] == SIMPLE)
//            {
//                return action;
//            }
//        }
//        return STAY;
    }

}

