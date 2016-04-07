#include <iostream>
#include "Game.h"
#include "Piece.h"


namespace Gaming {

    // these look to be the only functions that need defined in the Pieace.h file.
    Piece::Piece(const Game &g, const Position &p)
                    : __game(g)
    {
        // constructor for the piece object. It needs __game initialized.
    }

    virtual Piece::~Piece()
    {
        // de-constructor so something is going to need to de-allocated
    }

    std::ostream &operator<<(std::ostream &os, const Piece &piece)
    {
        // and we have an out stream operator.
    }

}