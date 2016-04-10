#include <iostream>
#include "Game.h"
#include "AggressiveAgentStrategy.h"

namespace Gaming {

// FINd actual intializing value in paper work
    const double DEFAULT_AGGRESSION_THRESHOLD = Game::STARTING_AGENT_ENERGY * 0.75;

    AggressiveAgentStrategy::AggressiveAgentStrategy(double agentEnergy)
    {
        //Constructor
    }

    AggressiveAgentStrategy::~AggressiveAgentStrategy()
    {
        // Deconstructor
    }

    ActionType AggressiveAgentStrategy::operator()(const Surroundings &s) const //override
    {
        // another function I'm not sure how to head/declare/whatever. It returns an action type
    }



}
