#include <iostream>
#include "Game.h"
#include "AggressiveAgentStrategy.h"

namespace Gaming {

    const double AggressiveAgentStrategy::DEFAULT_AGGRESSION_THRESHOLD = Game::STARTING_AGENT_ENERGY * 0.75;

    AggressiveAgentStrategy::AggressiveAgentStrategy(double agentEnergy)
    {
        //Constructor
        __agentEnergy = agentEnergy;
    }

    AggressiveAgentStrategy::~AggressiveAgentStrategy()
    {
        // Deconstructor
    }

    ActionType AggressiveAgentStrategy::operator()(const Surroundings &s) const //override
    {
        // another function I'm not sure how to head/declare/whatever. It returns an action type
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

            if (s.array[i] == SIMPLE && __agentEnergy >= DEFAULT_AGGRESSION_THRESHOLD) {
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
            if (s.array[i] == ADVANTAGE)
            {
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
            if (s.array[i] == FOOD)
            {
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
            if (s.array[i] == EMPTY)
            {
                return action;
            }
        }
        return STAY;
    }



}
