<h1> CSCI 2313: Programming Assignment 4 </h1>
<h2> A simplistic board game* </h2>

The program plays a simplistic game of beating down other agents and collecting resources. It uses a variety of functions and a heirarchy of classes to accomplish this. 

<h2> Source Files</h2>
There's a lot of these. 
Main.cpp: calls the tests for the games.
GameTesting.cpp holds the tests to test the game.
I did not write either of these and you know what they do.

Piece.cpp holds the definitions for the abstract class piece which has two children:
1. Resource.cpp: holding the definition for another abstract class and it's two children
    a. Food.cpp
    b. Advantage.cpp
2. Agent.cpp: holds the abstract class agent and the definitions for it's two children
    a. Simple: an agent type with no courage
    b. Strategic: the agent that got the brains and the brawn.
Strategiic.cpp calls up two other files; AgressiveAgentStrategy.cpp and DefaultAgentStrategy, which are passed as a variable in 
a functor to the Strategic Agent so he can decide what he wants to do. 
Game.cpp is the source file the runs the game. It makes the board, calls to the other files to create pieces for the board, 
moves the pieces while incrementing rounds, and cleans up.

<h2> Circumstances of the program </h2>
It runs! It compiles! And it passes most of it tests. It was written using CLion in a virtual machine Ubuntu environment. 
The program passes 146/153 tests. Not perfect considering I spent nearly 40 hours on it.  <- Not exxagerating. Hopefully I can study enough for my calc II exam Tuesday



* The computer is playing with itself. There's other names for that.

