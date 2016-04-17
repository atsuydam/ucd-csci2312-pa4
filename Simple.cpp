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
        // __posRandom takes in a vector of int (position) so make a vector of prioritized positions
        std::vector<int> potential_pos;
        // reset the position to the center of the grid.
        Position curr_pos(1, 1);
        Position new_pos;
        PositionRandomizer position;

        // look for food and loot first
        for (int i=0; i < 9; i++)
        {
            if (s.array[i] == FOOD || s.array[i] == ADVANTAGE)
            {
                potential_pos.push_back(i);
            }
        }

        if (potential_pos.size() > 0) {
            new_pos = Game::randomPosition(potential_pos);
            return Game::reachSurroundings(curr_pos, new_pos);
        }
        // look for somewhere safe to hide
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
        // if neither are available stay put
        return STAY;
    }
}

