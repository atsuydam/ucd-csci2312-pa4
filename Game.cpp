#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <set>
#include <bits/stl_set.h>
#include "Game.h"
#include "Piece.h"
#include "Resource.h"
#include "Simple.h"
#include "Strategic.h"
#include "Food.h"
#include "Advantage.h"

namespace Gaming {

    // Totally making up numbers, fix these
    const unsigned int Game::NUM_INIT_AGENT_FACTOR = 4;
    const unsigned int Game::NUM_INIT_RESOURCE_FACTOR = 2;

    const unsigned Game::MIN_WIDTH = 3;
    const unsigned Game::MIN_HEIGHT = 3;
    const double Game::STARTING_AGENT_ENERGY = 20;
    const double Game::STARTING_RESOURCE_CAPACITY = 10;

    PositionRandomizer Game::__posRandomizer = PositionRandomizer();

// constructors and de-constructor
    Game::Game()
    {
        //default constructor. All the members of this class as below
        // These, if something is breaking check out these values;
        __numInitAgents = 0;
        __numInitResources = 0;
        __width = MIN_WIDTH;
        __height = MIN_HEIGHT;

        for (int i=0; i < (__width*__height); i++)
        {
            __grid.push_back(nullptr);
        }

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

        // I have a 1-d array of Piece pointers. I'll have to use conversion for 2-d to (x,y)
        for (int i=0; i < (__width * __height); i++)
        {
            __grid.push_back(nullptr);
        }
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
        __width = another.__width;
        __height = another.__height;
        __grid = another.__grid;

        populate();
        __round = 0;
        __status = NOT_STARTED;
    }

    // Destroy it! Wreck all the things!!
    Game::~Game()
    {
        // delete all the things. ok, delete the creation of vector<Piece *> grid
        for (auto position = __grid.begin(); position != __grid.end(); ++position) {
            if (*position != nullptr) {
                delete *position;
            }
        }
    }

    void Game::populate() // populate the grid (used in automatic random initialization of a Game)
    {
        // these numbers are need for the the populate function, not the constructor
        __numInitAgents = (__width * __height) / NUM_INIT_AGENT_FACTOR;
        __numInitResources = (__width * __height) / NUM_INIT_RESOURCE_FACTOR;
        // We have many agents and resources we need. Will the function choose the type at
        // random?
        // simple pseudo-random number generator
// sufficient for our casual purposes
        std::default_random_engine gen;
        std::uniform_int_distribution<int> d(0, __width * __height);

        int numStrategic = __numInitAgents / 2;
        if (__numInitAgents % 2 == 1)
            numStrategic++;
// populate Strategic agents
        while (numStrategic > 0)
        {
            int i = d(gen); // random index in the grid vector
            if (__grid[i] == nullptr)
            { // is position empty
                Position pos(i / __width, i % __width);
                __grid[i] = new Strategic(*this, pos, Game::STARTING_AGENT_ENERGY);
                numStrategic--;
            }
        }

        int numSimple = __numInitAgents / 2;
// populate simple agents
        while (numSimple > 0)
        {
            int i = d(gen); // random index in the grid vector
            if (__grid[i] == nullptr)
            { // is position empty
                Position pos(i / __width, i % __width);
                __grid[i] = new Simple(*this, pos, Game::STARTING_AGENT_ENERGY);
                numSimple--;
            }
        }

        int numAdvantages = __numInitResources / 2;
// populate Advantage resources
        while (numAdvantages > 0)
        {
            int i = d(gen); // random index in the grid vector
            if (__grid[i] == nullptr)
            { // is position empty
                Position pos(i / __width, i % __width);
                __grid[i] = new Advantage(*this, pos, Game::STARTING_RESOURCE_CAPACITY);
                numAdvantages--;
            }
        }

        int numFood = __numInitResources / 2;
        if (__numInitResources % 2 == 1)
            numFood++;
        if (__width > 8)
            numFood++;
// populate food resources
        while (numFood > 0)
        {
            int i = d(gen); // random index in the grid vector
            if (__grid[i] == nullptr)
            { // is position empty
                Position pos(i / __width, i % __width);
                __grid[i] = new Food(*this, pos, Game::STARTING_RESOURCE_CAPACITY);
                numFood--;
            }
        }
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
        unsigned int numResource = 0;

        for (auto it = __grid.begin(); it != __grid.end(); ++it)
        {
            Resource *resource = dynamic_cast<Resource*>(*it);
            if (resource) numResource++;
        }
        return numResource;
    }

    const Piece *  Game::getPiece(unsigned int x, unsigned int y) const
    {
        // alright, returning a piece, taking in x and y, which are usually coordinates
        // Convert the x and y into position (x*height)+ y = position, allows __grid[position]
        unsigned int pos = (x *__width) + y;
        if (__grid[pos] == nullptr)
            throw PositionEmptyEx(x, y);
        return __grid[pos];
    }

    // grid population methods
    void Game::addSimple(const Position &position)
    {
        // not sure what energy to pass to the new character so I'm giving it a default value
        // position is a class with x and y.
        addSimple(position, STARTING_AGENT_ENERGY);
    }

    void Game::addSimple(const Position &position, double energy) // used for testing only
    {
        // call the constructor for the simple agent piece. Will the *this point work? No errors
        int spot = (position.x * __width) + position.y;
        if (spot >__grid.size()-1)
        {
            throw OutOfBoundsEx(__width, __height, position.x, position.y);
        }
        // is the spot open?
        if (__grid[spot] == nullptr)
        {
            Position p (position.x, position.y);
            Simple *s = new Simple(*this, p, energy);
            __grid[spot] = s;
        }
        else
        {
            throw PositionNonemptyEx(position.x, position.y);
        }
    }

    void Game::addSimple(unsigned x, unsigned y)
    {
        // look at that, coordinates to set a simple piece
       addSimple(x, y, STARTING_AGENT_ENERGY);
    }

    void Game::addSimple(unsigned x, unsigned y, double energy)
    {
        // okay, now we're setting a simple piece that has energy.
        // this is stating it's never used so he never calls it. when will i?

        int spot = (x * __width) + y;
        if (spot >__grid.size()-1)
        {
            throw OutOfBoundsEx(__width, __height, x, y);
        }
        // is the spot open?
        if (__grid[spot] == nullptr)
        {
            Position p (x, y);
            Simple *s = new Simple(*this, p, energy);
            __grid[spot] = s;
        }
        else
        {
            throw PositionNonemptyEx(x, y);
        }
    }

    void Game::addStrategic(const Position &position, Strategy *s)
    {
        // add a strategic piece using the position class, I think
        int array_spot = (position.x * __width) + position.y;
        if (array_spot >__grid.size()-1)
        {
            throw OutOfBoundsEx(__width, __height, position.x, position.y);
        }
        // is the spot you want to put it open?
        if (__grid[array_spot] == nullptr)
        {
            Strategic *strat = new Strategic(*this, position, STARTING_AGENT_ENERGY, s);
            __grid[array_spot] = strat;
        }
        else
        {
            throw PositionNonemptyEx(position.x, position.y);
        }
    }

    void Game::addStrategic(unsigned x, unsigned y, Strategy *s)
    {
        // add a new strategic piece using cordinates. Not sure what to do with strategy pointer being passed
        Position p (x, y);
        addStrategic(p, s);
    }

    void Game::addFood(const Position &position)
    {
        // add food to the board using the position class
        int array_spot = (position.x * __width) + position.y;
        if (array_spot >__grid.size()-1)
        {
            throw OutOfBoundsEx(__width, __height, position.x, position.y);
        }
        // make sure the spot is open
        if (__grid[array_spot] == nullptr)
        {
            Food *food = new Food(*this, position, STARTING_RESOURCE_CAPACITY);
            __grid[array_spot] = food;
        }
        else
        {
            throw PositionNonemptyEx(position.x, position.y);
        }
    }

    void Game::addFood(unsigned x, unsigned y)
    {
        // add food to the board using the given coordinates
        Position p (x, y);
        addFood(p);
    }

    void Game::addAdvantage(const Position &position)
    {
        // add an advantage to the board using the position class
        int array_spot = (position.x * __width) + position.y;
        if (array_spot >__grid.size()-1)
        {
            throw OutOfBoundsEx(__width, __height, position.x, position.y);
        }
        // make sure the spot is available, not sitting agents on resources and the like
        if (__grid[array_spot] != nullptr)
        {
            throw PositionNonemptyEx(position.x, position.y);
        }
        else
        {
            Advantage *loot = new Advantage(*this, position, STARTING_RESOURCE_CAPACITY);
            __grid[array_spot] = loot;
        }
    }

    void Game::addAdvantage(unsigned x, unsigned y)
    {
        // add an advantage to the board using the coordinates
        Position  p (x, y);
        addAdvantage(p);
    }

    const Surroundings Game::getSurroundings(const Position &pos) const
    {
        // return the surroundings for the passed position in an array of the Surroundings class
        Surroundings *around = new Surroundings;
        // a variable to count through the array for surroundings
        int i = 0;
        // a for loop to go through the three x position rows
        for (int j = -1; j <= 1; j++)
        {
            // a nested loop for the y positions of the x row
            for (int k = -1; k <= 1; k++)
            {
                int position = (((pos.x + j) * __width) + (pos.y + k));
                if (pos.x+j < 0 || pos.x+j >= __height || pos.y+k <0 || pos.y+k >= __width)
                {
                    around->array[i] = INACCESSIBLE;
                    i++;
                }
                else if (i == 4) {
                    around->array[i] = SELF;
                    i++;
                }
                else if (__grid[position] ==  nullptr)
                {
                    around->array[i] = EMPTY;
                    i++;
                }
                else
                {
                    around->array[i] = __grid[position]->getType();
                    i++;
                }

            }
        }

        around->array[4] = SELF;
        return *around;
    }

    // gameplay methods
    const ActionType Game::reachSurroundings(const Position &from, const Position &to)
    {
        // reach surroundings? we're passing a previous location and a next location.
        ActionType do_it;
        if (from.x > to.x && from.y > to.y)
            do_it = NW;
        if (from.x > to.x && from.y == to.y)
            do_it = N;
        if (from.x > to.x && from.y < to.y)
            do_it = NE;
        if (from.x == to.x && from.y > to.y)
            do_it = W;
        if (from.x == to.x && from.y == to.y)
            do_it = STAY;
        if (from.x == to.x && from.y < to.y)
            do_it = E;
        if (from.x < to.x && from.y > to.y)
            do_it = SW;
        if (from.x < to.x && from.y == to.y)
            do_it = S;
        if (from.x < to.x && from.y < to.y)
            do_it = SE;

        return do_it;

    }

    bool Game::isLegal(const ActionType &ac, const Position &pos) const
    {
        bool legal_move = true;
        Surroundings survey = getSurroundings(pos);
        // every fucking switch I've written come back with an error. Every fucking if statement the same. What the FUCK do you want?!
        if (ac == NE)
        {
            if (survey.array[2] == INACCESSIBLE)
                legal_move = false;
        }
        if (ac == NW)
        {
            if (survey.array[0] == INACCESSIBLE)
                legal_move = false;
        }
        if (ac == N)
        {
            if (survey.array[1] == INACCESSIBLE)
                legal_move = false;
        }
        if (ac == W)
        {
            if (survey.array[3] == INACCESSIBLE)
                legal_move = false;
        }
        if (ac == STAY)
        {
            if (survey.array[4] == INACCESSIBLE)
                legal_move = false;
        }
        if (ac == E)
        {
            if (survey.array[5] == INACCESSIBLE)
                legal_move = false;
        }
        if (ac == SE)
        {
            if (survey.array[8] == INACCESSIBLE)
                legal_move = false;
        }
        if (ac == S)
        {
            if (survey.array[7] == INACCESSIBLE)
                legal_move = false;
        }
        if (ac == SW)
        {
            if (survey.array[6] == INACCESSIBLE)
                legal_move = false;
        }
        return legal_move;
    }

    const Position Game::move(const Position &pos, const ActionType &ac) const // note: assumes legal, use with isLegal()
    {
        // action based on location is the most logical assumption
       if (isLegal(ac, pos)) {
           //int oldPos = (pos.x * __width) + pos.y;
           if (ac == NE) {
               Position newP(pos.x - 1, pos.y + 1);
               return newP;
           }
           if (ac == N) {
               Position newP(pos.x - 1, pos.y);
               return newP;
           }
           if (ac == NW) {
               Position newP(pos.x - 1, pos.y - 1);
               return newP;
           }
           if (ac == E) {
               Position newP(pos.x, pos.y + 1);
               return newP;
           }
           if (ac == W) {
               Position newP(pos.x, pos.y - 1);
               return newP;
           }
           if (ac == SE) {
               Position newP(pos.x + 1, pos.y + 1);
               return newP;
           }
           if (ac == S) {
               Position newP(pos.x + 1, pos.y);
               return newP;
           }
           if (ac == SW) {
               Position newP(pos.x + 1, pos.y - 1);
               return newP;
           }
       }
    }

    void Game::round()   // play a single round
    {
        // play a round, like the man said std::set is supposed to help with this instead of going through the grid.
        std::set<Piece *> pawns;
        ActionType my_turn;
        // collect all the pieces that need a turn, anything without a null ptr.
        for (auto it = __grid.begin(); it != __grid.end(); ++it) {
            if (*it) {
                pawns.insert(pawns.end(), *it);
                std::cout << pawns.size() << std::endl;
            }
        }

        for (auto gameTime = pawns.begin(); gameTime != pawns.end(); gameTime++) {
            std::cout << "I entered the play round " << std::endl;
            if (!(*gameTime)->getTurned()) {
                std::cout << " And I got passed the first turn test" << std::endl;
                // grab a piece at a time, change their turn status to true
                (*gameTime)->setTurned(true);
                Position curr_pos, move_pos;
                my_turn = (*gameTime)->takeTurn(getSurroundings((*gameTime)->getPosition()));
                move_pos = move(curr_pos, my_turn);

                // have that item take a turn. Call interact if something is there?
                if (move_pos.x != curr_pos.x || move_pos.y != curr_pos.y) {
                    std::cout << "I want to move!" << std::endl;
                    Piece *enemy = __grid[(move_pos.x * __width) + move_pos.y];
                    if (enemy) {
                        std::cout << "I made a friend " << std::endl;
                        (*enemy) * *(*gameTime);
                        //make them trade places, I suppose. if the other lost it'll be gone soon anyway
                        __grid[(move_pos.x * __width) + move_pos.y] = (*gameTime);
                        __grid[(curr_pos.x * __width) + curr_pos.y] = enemy;
                    }
                    else {
                        std::cout << "There was nothing there" << std::endl;
                        (*gameTime)->setPosition(move_pos);
                        std::cout << "position set" << std::endl;
                        __grid[(move_pos.x * __width) + move_pos.y] = (*gameTime);
                        std::cout << "moved grid position" << std::endl;
                        __grid[(curr_pos.x * __width) + curr_pos.y] = nullptr;
                        std::cout << "set null ptr" << std::endl;
                    }
                }
                std::cout << "I'm still here" << std::endl;
            }
            std::cout << "yep, I'm still here" << std::endl;
        }

        // age objects, delete if no longer viable
        // set turn to false for all remaining pieces.
        for (auto gameTime = pawns.begin(); gameTime != pawns.end(); gameTime++) {
            std::cout << " I don't want to get older." << std::endl;
            (*gameTime)->setTurned(false);
            std::cout << "I'm still here and now false" << std::endl;
            (*gameTime)->age();
            std::cout << "I'm still here but older" << std::endl;
        }
        // delete anything that has been interacted with and became nonviable
        for (int i = 0; i < __grid.size(); i++) {
            if (__grid[i] && !__grid[i]->isViable()) {
                delete __grid[i];
                __grid[i] = nullptr;
                std::cout << "clean up" << std::endl;
            }
        }
        std::cout << "clean up" << std::endl;
        // increment round
        __round++;

    }

    void Game::play(bool verbose)
    {
        __verbose = verbose;
        // verbose it what prints the game play to the screen. If changed in the tests
        // source pages to change it will display every round of the board.

    }

    // And a friend function
    std::ostream &operator<<(std::ostream &os, const Game &game)
    {
        // make it visible, return os
        // print out the grid pattern
        int c=0; // a variable to go through the vectors, the other two are formatting
        int count = 0;

        // it's looking for the round number
        os << "Round " << game.getRound() << std::endl;

        for (int i=0; i < game.__height; i++)
        {
            for (int j=0; j < game.__width; j++)
            {
                if (game.__grid[count] == nullptr)
                {
                    os << "[     ]";
                }
                else
                {
                    // this is going to cause issues later when the game is producing 4 digit ids
                    os << "[" << *game.__grid[count] << " ]";
                }
                count++;
            }
            os << std::endl;
        }
        // and the status of the game
        os << "Status:" << game.getStatus() << std::endl;
        return os;
    }

}

