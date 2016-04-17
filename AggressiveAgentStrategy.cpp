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
        std::vector<int> potential_pos;
        // reset the position to the center of the grid.
        Position curr_pos(1, 1);
        Position new_pos;
        PositionRandomizer position;

        // look for someone to pummel
        for (int i = 0; i < 9; i++) {
            if (__agentEnergy >= DEFAULT_AGGRESSION_THRESHOLD && (s.array[i] == SIMPLE || s.array[i] == STRATEGIC)) {
                potential_pos.push_back(i);
            }
        }

        if (potential_pos.size() > 0)
        {
            new_pos = Game::randomPosition(potential_pos);
            return Game::reachSurroundings(curr_pos, new_pos);
        }
        // look for something to pummel someone with
        for (int i = 0; i < 9; i++) {
            if (s.array[i] == ADVANTAGE)
            {
                potential_pos.push_back(i);
            }
        }

        if (potential_pos.size() > 0)
        {
            new_pos = Game::randomPosition(potential_pos);
            return Game::reachSurroundings(curr_pos, new_pos);
        }

        // look for food so we have energy for pummeling
        for (int i = 0; i < 9; i++) {
            if (s.array[i] == FOOD)
            {
                potential_pos.push_back(i);
            }
        }
        if (potential_pos.size() > 0)
        {
            new_pos = Game::randomPosition(potential_pos);
            return Game::reachSurroundings(curr_pos, new_pos);
        }
        // now we look for some where to rest
        for (int i = 0; i < 9; i++) {
            if (s.array[i] == EMPTY)
            {
                potential_pos.push_back(i);
            }
        }

        if (potential_pos.size() > 0) {
            new_pos = Game::randomPosition(potential_pos);
            return Game::reachSurroundings(curr_pos, new_pos);
        }
        // if none are available, or we don't have the energy for pummeling
        return STAY;
    }



}
