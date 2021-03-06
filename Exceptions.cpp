#include <iostream>
#include "Game.h"


namespace Gaming {

    // functions from the Gaming Exception class
    void GamingException::setName(std::string name)
    {
        __name = name;
    }

    std::ostream &operator<<(std::ostream &os, const GamingException &ex)
    {
        // obviously he wants something outputted here
        os << ex.__name;
    }

    // Functions from the Dimensions Ex
    DimensionEx::DimensionEx(unsigned expWidth, unsigned expHeight, unsigned width, unsigned height)
            : __exp_width(expWidth),
              __exp_height(expHeight),
              __width(width),
              __height(height)
    {}

    unsigned DimensionEx::getExpWidth() const
    {
        // I think these may be the only one line functions he didn't do. Or I'm missing something.
        return __exp_width;
    }

    unsigned DimensionEx::getExpHeight() const
    {
        return __exp_height;
    }

    unsigned DimensionEx::getWidth() const
    {
        return __width;
    }

    unsigned DimensionEx::getHeight() const
    {
        return __height;
    }

    // Functions for Insufficient Dimensions Exception, a sub class of the Dimension Exception above
    void InsufficientDimensionsEx::__print_args(std::ostream &os) const
    {
        os << "Minimum height " << __exp_height << ", requested height " << __height << "\n Minimum width "
                << __exp_width << ", requested width " << __width << "\n";
    }

    InsufficientDimensionsEx::InsufficientDimensionsEx(unsigned minWidth, unsigned minHeight, unsigned width, unsigned height)
                : DimensionEx (minWidth, minHeight, width, height) // this is a best guess as to what to goes in these.
    {
        // Best guess? Those variables needs compared to each other
        // OR it's a constructor for a class to compare to?
        __name = "InsufficientDimensionsEx";

    }

    // Functions for the Out of Bounds exceptions
    void OutOfBoundsEx:: __print_args(std::ostream &os) const
    {
        os << __name;
    }

    // Function for the Out of Bounds exception
    OutOfBoundsEx::OutOfBoundsEx(unsigned maxWidth, unsigned maxHeight, unsigned width, unsigned height)
            : DimensionEx (maxWidth, maxHeight, width, height)
    {
        // much like insufficient dimensions, this took a dimensionsEx constructor and the order of variables may
        // be wrong. Need to figure out what is expected of this constructor.
        __name = "OutOfBoundsEx";
    }

    // Functions for Position Ex
    void PositionEx::__print_args(std::ostream &os) const
    {
        os << __name;
    }

    PositionEx::PositionEx(unsigned x, unsigned y)
            : __x(x),
              __y(y)
    {}

    // Functions for Position nonempty Ex
    PositionNonemptyEx::PositionNonemptyEx(unsigned x, unsigned y)
            : PositionEx(x, y)
    {
        // something goes in here. Something you see
        __name = "PositionNonemptyEx";
    }

    // Functions for Position empty ex
    PositionEmptyEx::PositionEmptyEx(unsigned x, unsigned y)
            : PositionEx(x, y)
    {
            __name = "PositionEmptyEx";
    }

    // Function for pos (position?) vector empty
    void PosVectorEmptyEx::__print_args(std::ostream &os) const
    {
        os << __name;
    }

    PosVectorEmptyEx::PosVectorEmptyEx()
    {
        // I do know what this is. give it a name. Name have power
        __name = "PosVectorEmptyEx";
    }
}
