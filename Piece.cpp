#include <iostream>
#include "Game.h"
#include "Piece.h"


namespace Gaming {

    unsigned int __id = 0;
    // these look to be the only functions that need defined in the Piece.h file.
    Piece::Piece(const Game &g, const Position &p)
                    : __game(g)
    {
        // games, the parent class to piece, is initialized above which leaves
        __position = p;
        // I have two bools that are not global; whether the piece is finished or turned.
        __finished = false;
        __turned = false;
        // and protected ID It would make more sense for this to be initialized outside the constructor and
        // incremented inside.
        __id++;
    }

    Piece::~Piece()
    {
        // de-constructor so something is going to need to de-allocated
    }

    std::ostream &operator<<(std::ostream &os, const Piece &piece)
    {
        // and we have an out stream operator.
        os << __id;

        return os;
    }

}