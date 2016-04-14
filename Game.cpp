#include <iostream>
#include "Game.h"
#include "Piece.h"
#include "Resource.h"
#include "Simple.h"
#include "Strategic.h"

namespace Gaming {

    // Totally making up numbers, fix these
    const unsigned int Game::NUM_INIT_AGENT_FACTOR = 4;
    const unsigned int Game::NUM_INIT_RESOURCE_FACTOR = 2;

    const unsigned Game::MIN_WIDTH = 3;
    const unsigned Game::MIN_HEIGHT = 3;
    const double Game::STARTING_AGENT_ENERGY = 20;
    const double Game::STARTING_RESOURCE_CAPACITY = 10;
//somehow this needs initialized. It's a functor but...
    PositionRandomizer __posRandomizer;  // this may not go here

// Why is this here? it's private and listed above all the other stuff in the class but... it's all by itself
    void Game::populate() // populate the grid (used in automatic random initialization of a Game)
    {
        // these numbers are need for the the populate function, not the constructor
        __numInitAgents = (__width * __height) / NUM_INIT_AGENT_FACTOR;
        __numInitResources = (__width * __height) / NUM_INIT_RESOURCE_FACTOR;
    }

// constructors and de-constructor
    Game::Game()
    {
        //default constructor. All the members of this class as below
        // These, if something is breaking check out these values;
        __numInitAgents = 0;
        __numInitResources = 0;
        __width = MIN_WIDTH;
        __height = MIN_HEIGHT;

//        std::vector<Piece *> __grid = ; // if a position is empty, nullptr

        __round = 0;
        __status = NOT_STARTED;
        __verbose = false;
    }
    Game::Game(unsigned width, unsigned height, bool manual) // note: manual population by default
            : __width(width),
              __height(height)
    {
        // need an exception for too small a board
        if (width < MIN_HEIGHT || height < MIN_HEIGHT)
            throw InsufficientDimensionsEx(MIN_WIDTH, MIN_HEIGHT, width, height);

        __numInitAgents = 0;
        __numInitResources = 0;

        std::vector<Piece *> __grid; // if a position is empty, nullptr

        // need to populate the grid if not manual
        if (!manual)
        {
            populate();
        }

        __round = 0;
        __status = NOT_STARTED;
        __verbose = false;

    }

    Game::Game(const Game &another)
            : Game()
    {
        // Make another game with the same values but it will have random population
        this->__width = another.__width;
        this->__height = another.__height;

        populate();
        __round = 0;
        __status = NOT_STARTED;
    }

    // Destroy it! Wreck all the things!!
    Game::~Game()
    {
        // delete all the things. ok, delete the creation of vector<Piece *> grid
    }

    // Getters. If these were as simple as the first two with only a return he would have implemented them so...
    unsigned int Game::getNumPieces() const
    {
        // oh.. we need to add up agents and resources
        return getNumAgents() + getNumResources();
    }

    unsigned int Game::getNumAgents() const
    {
        // number of agents? Add simple and strategic
        return getNumSimple() + getNumStrategic();
    }

    unsigned int Game::getNumSimple() const
    {
        // simple, calculation on the readme file
        unsigned int numSimple = 0;

        for (auto it = __grid.begin(); it != __grid.end(); ++it)
        {
            Simple *simple = dynamic_cast<Simple*>(*it);
            if (simple) numSimple++;
        }
        return numSimple;
    }

    unsigned int Game::getNumStrategic() const
    {
        // yeah, return the number of strategic agents
        unsigned int numStrategic = 0;

        for (auto it = __grid.begin(); it != __grid.end(); ++it)
        {
            Strategic *strategic = dynamic_cast<Strategic*>(*it);
            if (strategic) numStrategic++;
        }
        return numStrategic;

    }

    unsigned int Game::getNumResources() const
    {
        // How many resources are on the board? Return that number. You have to do some adding
        unsigned int resource = 0;
        // an algorthim to count food and advantages.
        return resource;
    }

    const Piece *  Game::getPiece(unsigned int x, unsigned int y) const
    {
        // alright, returning a piece, taking in x and y, which are usually coordinates
        // there's a pointer star too so keep that bugger in mind
    }

    // grid population methods
    void Game::addSimple(const Position &position)
    {

    }

    void Game::addSimple(const Position &position, double energy) // used for testing only
    {
        // call the constructor for the simple agent piece. Will the *this point work? No errors
        Simple(*this, position, energy);
    }

    void Game::addSimple(unsigned x, unsigned y)
    {
        // look at that, coordinates to set a simple piece
        Position p(x, y);
        Simple(*this, p, STARTING_AGENT_ENERGY);

    }

    void Game::addSimple(unsigned x, unsigned y, double energy)
    {
        // okay, now we're setting a simple piece that has energy.
        // this is stating it's never used so he never calls it. when will i?
        Position p (x, y);
        Simple(*this, p, energy);
    }

    void Game::addStrategic(const Position &position, Strategy *s)
    {
        // add a strategic piece using the position class, I think
    }

    void Game::addStrategic(unsigned x, unsigned y, Strategy *s)
    {
        // add a new strategic piece using cordinates
    }

    void Game::addFood(const Position &position)
    {
        // add food to the board using the position class
    }

    void Game::addFood(unsigned x, unsigned y)
    {
        // add food to the board using the given coordinates
    }

    void Game::addAdvantage(const Position &position)
    {
        // add an advantage to the board using the position class
    }

    void Game::addAdvantage(unsigned x, unsigned y)
    {
        // add an advantage to the board using the coordinates
    }

    const Surroundings Game::getSurroundings(const Position &pos) const
    {
        // return the surroundings for the passed position
    }

    // gameplay methods
    const ActionType Game::reachSurroundings(const Position &from, const Position &to)
    {
        // reach surroundings? we're passing a previous location adn a next location.
    }

    bool Game::isLegal(const ActionType &ac, const Position &pos) const
    {
        // now we're taking in an action type. Eventually I wall come across this elusive function and
        // learn what it does.
    }

    const Position Game::move(const Position &pos, const ActionType &ac) const // note: assumes legal, use with isLegal()
    {
        // action based on location is the most logical assumption
    }

    void Game::round()   // play a single round
    {
        // play a round, like the man said
        // this may be the most difficult function to write and will call many, many others.
    }

    void Game::play(bool verbose)
    {
        // verbose it what prints the game play to the screen. If changed in the tests
        // source pages to change it will display every round of the board.
    }

    // And a friend function
    std::ostream &operator<<(std::ostream &os, const Game &game)
    {
        // make it visible, return os
        // print out the grid pattern

        return os;
    }

}

