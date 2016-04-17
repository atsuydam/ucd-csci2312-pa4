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
        // Like simple but with different priorities
        std::vector<int> potential_pos;
        // reset the position to the center of the grid.
        Position curr_pos(1, 1);
        Position new_pos;
        PositionRandomizer position;

        // look for loot first
        for (int i = 0; i < 9; i++)
        {
            if (s.array[i] == ADVANTAGE) {
                potential_pos.push_back(i);
            }
        }

        if (potential_pos.size() > 0)
        {
            new_pos = Game::randomPosition(potential_pos);
            return Game::reachSurroundings(curr_pos, new_pos);
        }
        // look for food to boost energy next
        for (int i = 0; i < 9; i++) {
            if (s.array[i] == FOOD) {
                potential_pos.push_back(i);
            }
        }

        if (potential_pos.size() > 0)
        {
            new_pos = Game::randomPosition(potential_pos);
            return Game::reachSurroundings(curr_pos, new_pos);
        }

        // look for somewhere safe to hide
        for (int i = 0; i < 9; i++) {
            if (s.array[i] == EMPTY) {
                potential_pos.push_back(i);
            }
        }
        if (potential_pos.size() > 0)
        {
            new_pos = Game::randomPosition(potential_pos);
            return Game::reachSurroundings(curr_pos, new_pos);
        }
        // now we look for a simple to beat up
        for (int i = 0; i < 9; i++) {
            if (s.array[i] == SIMPLE)
            {
                potential_pos.push_back(i);
            }
        }

        if (potential_pos.size() > 0) {
            new_pos = Game::randomPosition(potential_pos);
            return Game::reachSurroundings(curr_pos, new_pos);
        }
        // if none are available stay put
        return STAY;
    }
}


