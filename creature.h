/*
 * Name Bisrat Asefaw
 * 10/30/2019
 * CSS 342
 *
 * Creature file compilation unit for the cretaure.h file that contians
 * the real source code for the class creature it contains the creature constructor
 * overloaded << operator and solve maze methods that specifiy the conditon of the creature
 * in the maze
 * */


#ifndef HW_3_CREATURE_H
#define HW_3_CREATURE_H

#include <list>
#include <iterator>
#include <iostream>
#include <string>

#include "maze.h"

using namespace std;


class creature {
public:
    /// Creature constructor that instantiate the position of the creature in the maze
    /// \param row row position of the creature
    /// \param col  columen position of the creature
    creature(int row, int col);

/*!
 * overLoaded ostream operator for displaying the information about the creature
 * @param out meaning full explanation of the creature
 * @param crt  the creature
 * @return ostream object that displays the creature to consule
 */
    friend ostream &operator<<(ostream &out, const creature &crt);

/*!
 * Solve method that uses recursion methods to solve the direction of the maze
 * @param Maze maze object that contains information about the structure of maze
 * @return the string representation of the direction the maze take to exit
 */
    string Solve(maze &Maze);


private:

    /// moveNorth method that takes the creature north side of the maze
/// \param m maze the maze
/// \param creature1 the creature inside the maze
/// \return  true if there is a way north direction and returns false otherwise
    bool moveNorth(maze &m, creature creature1);

    ///  moveEast method that takes the creature east side side of the maze
/// \param m  Maze that the informaztion about the maze
/// \param creature1  creatuer that is inside the maze
/// \return return true if there is a way through east side of the ,aze
    bool moveEast(maze &m, creature creature1);

///moveWest that accepts as parameter the maze and creature and recursively finds its way to exit
/// \param m Maze that contains information about the maze 2x2 matrix
/// \param creature1  the creature inside the maze
/// \return true for successful path through west otherwise false
    bool moveWest(maze &m, creature creature1);

/// MoveSouth that accepts maze and creature and recursively finds its way to the exit
/// \param m Maze that contains information 2x2
/// \param creature1 the creature inside the maze
/// \return true if reaches the exit otherwise false
    bool moveSouth(maze &m, creature creature1);

/// list that used to store the path string
    list<string> l;

    //row and column specification of this creature
    int row;
    int col;

};


#endif //HW_3_CREATURE_H
