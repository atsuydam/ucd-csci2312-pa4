#include <iostream>
#include "Game.h"
#include "Piece.h"
#include "Resource.h"
#include "Agent.h"

namespace Gaming {

// Look into the documentation as to what this should be
    const double AGENT_FATIGUE_RATE = 0;

    Agent::Agent(const Game &g, const Position &p, double energy)
            : Piece(g, p)
    {

    }

    Agent::~Agent()
    {
        // a de-constructor file means something is going to need to be de-allocated
    }


    void Agent::age()
    {

    }


    Piece & Agent::operator*(Piece &other)
    {

    }

    Piece & Agent::interact(Agent *)
    {

    }

    Piece & Agent::interact(Resource *)
    {

    }
}
