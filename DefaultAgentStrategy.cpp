#include <iostream>
#include "Game.h"


namespace Gaming {

    DefaultAgentStrategy::DefaultAgentStrategy()
    {

    }

    DefaultAgentStrategy::~DefaultAgentStrategy()
    {

    }

    // Look, another action type that needs a header/ title/whatever
    ActionType DefaultAgentStrategy::operator()(const Surroundings &s) const
    {

        // this still needs the position randomizer function
        ActionType action;
        for (int i=0 ; i < 9; i++)
        {
            if (i == 0)
                action = NW;
            if (i == 1)
                action = N;
            if (i == 2)
                action = NE;
            if (i == 3)
                action = W;
            if (i == 5)
                action = E;
            if (i == 6)
                action = SW;
            if (i == 7)
                action = S;
            if (i == 8)
                action = SE;
            if (s.array[i] == ADVANTAGE) {
                return action;
            }
        }
        for (int i=0 ; i < 9; i++)
        {
            if (i == 0)
                action = NW;
            if (i == 1)
                action = N;
            if (i == 2)
                action = NE;
            if (i == 3)
                action = W;
            if (i == 5)
                action = E;
            if (i == 6)
                action = SW;
            if (i == 7)
                action = S;
            if (i == 8)
                action = SE;
            if (s.array[i] == FOOD) {
                return action;
            }
        }
        for (int i=0 ; i < 9; i++)
        {
            if (i == 0)
                action = NW;
            if (i == 1)
                action = N;
            if (i == 2)
                action = NE;
            if (i == 3)
                action = W;
            if (i == 5)
                action = E;
            if (i == 6)
                action = SW;
            if (i == 7)
                action = S;
            if (i == 8)
                action = SE;
            if (s.array[i] == EMPTY) {
                return action;
            }
        }
        for (int i=0 ; i < 9; i++)
        {
            if (i == 0)
                action = NW;
            if (i == 1)
                action = N;
            if (i == 2)
                action = NE;
            if (i == 3)
                action = W;
            if (i == 5)
                action = E;
            if (i == 6)
                action = SW;
            if (i == 7)
                action = S;
            if (i == 8)
                action = SE;
            if (s.array[i] == SIMPLE)
            {
                return action;
            }
        }
        return STAY;
    }
}


