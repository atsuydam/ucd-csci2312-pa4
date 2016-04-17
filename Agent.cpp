#include <iostream>
#include "Game.h"
#include "Piece.h"
#include "Resource.h"
#include "Agent.h"

namespace Gaming {


    const double Agent::AGENT_FATIGUE_RATE = 0.3;

    Agent::Agent(const Game &g, const Position &p, double energy)
            : Piece(g, p)
    {
        __energy = energy;
    }

    Agent::~Agent()
    {
        // a de-constructor file means something is going to need to be de-allocated
    }


    void Agent::age()
    {
        __energy -= AGENT_FATIGUE_RATE;
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
