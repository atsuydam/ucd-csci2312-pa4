
#include <iostream>
#include <iomanip>
#include "Game.h"
#include "Piece.h"
#include "Resource.h"
#include "Agent.h"
#include "Advantage.h"

namespace Gaming {

    const char  Advantage::ADVANTAGE_ID = 'D';
    const double Advantage::ADVANTAGE_MULT_FACTOR = 2.0;

    Advantage::Advantage(const Game &g, const Position &p, double capacity)
            : Resource (g, p, capacity)
    {
       // make it
    }

    Advantage::~Advantage()
    {
        // break it
    }

    // more of those buggering over ridden virtual functions
    // Look at that! I was missing const, have to go check all the others.
    void Advantage::print(std::ostream &os) const
    {
        os << "D" << std::setw(4) << std::left << __id;
    }

    double Advantage::getCapacity() const
    {

    }

    double Advantage::consume()
    {


    }
}
