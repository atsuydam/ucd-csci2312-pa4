#include <iostream>
#include "Game.h"

namespace Gaming {

    // Totally making up numbers, fix these
    const unsigned int Game::NUM_INIT_AGENT_FACTOR = 0;
    const unsigned int Game::NUM_INIT_RESOURCE_FACTOR = 0;

    const unsigned Game::MIN_WIDTH = 0;
    const unsigned Game::MIN_HEIGHT = 0;
    const double Game::STARTING_AGENT_ENERGY = 0;
    const double Game::STARTING_RESOURCE_CAPACITY = 0;

    static PositionRandomizer __posRandomizer;  // this may not go here

// Why is this here? it's private and listed above all the other stuff in the class but... it's all by itself
    void Game::populate() // populate the grid (used in automatic random initialization of a Game)
    {

    }

// constructors and de-constructor
    Game::Game()
    {
        //default constructor. ALl the members of this class as below

        unsigned __numInitAgents, __numInitResources;

        unsigned __width, __height;
        std::vector<Piece *> __grid; // if a position is empty, nullptr

        unsigned int __round;

        Status __status;

        bool __verbose;
    }
    Game::Game(unsigned width, unsigned height, bool manual) // note: manual population by default
            : __width(width),
              __height(height)
    {
        // will I need anything else in here
    }

    Game::Game(const Game &another)
            : Game()
    {
        // ooh.. i have no idea.
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
    }

    unsigned int Game::getNumAgents() const
    {
        // number of agents?
    }

    unsigned int Game::getNumSimple() const
    {
        // simple? oh simple pieces from simple.cpp/h
    }

    unsigned int Game::getNumStrategic() const
    {
        // yeah, return the number of strategic something or other
    }

    unsigned int Game::getNumResources() const
    {
        // How many resources are on the board? Return that number. You have to do some adding
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

    }

    void Game::addSimple(unsigned x, unsigned y)
    {
        // look at that, coordinates to set a simple piece
    }

    void Game::addSimple(unsigned x, unsigned y, double energy)
    {
        // okay, now we're setting a simple piece that has energy.
        // this is stating it's never used so he never calls it. when will i?
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
    }

}
