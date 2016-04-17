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
        return other.interact(this);
    }

    Piece & Agent::interact(Agent *challenger)
    {
        double temp = __energy;
        this->__energy -= challenger->__energy;
        if (__energy <= 0)
            this->finish();
        challenger->__energy -= temp;
        if (challenger->__energy <= 0)
            challenger->finish();
    }

    Piece & Agent::interact(Resource *consumed)
    {
        __energy += consumed->getCapacity();
        consumed->consume();
    }
}
