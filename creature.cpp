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

#include "creature.h"

//! creature constructore that creates instatiates the creature instance variables
//! \param row the row position of the creature in the maze
//! \param col the column position of the creature in the maze.
creature::creature(int row, int col) {
    this->row = row;
    this->col = col;

}


/// operator<< method that overloads the out stream
/// \param out the information of the creature to be displayed
/// \param crt the creature1 the input creature information
/// \return understandible string representation of the creature.
ostream &operator<<(ostream &out, const creature &crt) {
    out << "(" << crt.row << ", ";
    out << crt.col << ")";
    return out;

}

//! method solve that acepts a maze parameter and returns the string representation of the path
//! \param Maze
//! \return the string representation of the way the reature takes to get to exit
string creature::Solve(maze &Maze) {
    bool success=false;
    string info = "";
    if (!Maze.IsWall(this->row, this->col)) {

        success = moveNorth(Maze, *this);
        if (!success)
            success = moveEast(Maze, *this);
        if (!success)
            success = moveWest(Maze, *this);
        if (!success)
            success = moveSouth(Maze, *this);
        if(!success){
            Maze.MarkAsVisited(row, col);
        }
        if (success && l.size() != 0) {
            Maze.MarkAsPath(row, col);
            list<string>::iterator it;
            for (it = l.begin(); it != l.end(); it++) {
                info += *it;
            }
        }
        return info;
    } else {
        cout << "Putting the creature in wall: " << endl;
        return info;
    }
}

/*!
 * Method moveNorth that takes the creature to north from the position and finds a way through
 * @param m Maze the maze to be solved
 * @param creature1 the creature inside the maze
 * @return success true is there is a way through and false otherwise.
 */
bool creature::moveNorth(maze &m, creature creature1) {
    bool success= false;
    int z = creature1.row;
    int i = creature1.row - 1;
    creature1.row = z;
    if (m.IsClear(i, creature1.col) && creature1.col < m.getWidth() && i < m.getLength() &&
        i >= 0 && creature1.col >= 0 && !m.IsVisited(i, creature1.col)) {
        creature1.row -= 1;
        m.MarkAsPath(creature1.row, creature1.col);
        l.push_back("N");
        if (m.ExitRow() == creature1.row && m.ExitCol() == creature1.col)
            success = true;

        else {
            if (!m.IsPath(creature1.row - 1, creature1.col)) {
                success = moveNorth(m, creature1);
            }
            if (!success) {
                success = moveWest(m, creature1);

                if (!success) {
                    success = moveEast(m, creature1);

                    if (!success) {
                        m.MarkAsVisited(creature1.row, creature1.col);
                        l.pop_back();
                        creature1.row = z;
                    }
                }
            }

        }
    }
    return success;
}

/*! method moveEast that takes the cretaure to east and searches for path through
 * @param m maze the maze to be solved
 * @param creature1 the creature in the maze
 * @return success true if there is way in this direction and false otherwise
 */
bool creature::moveEast(maze &m, creature creature1) {
    bool success= false;
    int z = creature1.col;
    int i = z + 1;
    creature1.col = z;

    if (m.IsClear(creature1.row, i) && i < m.getWidth() && creature1.row < m.getLength() &&
        !m.IsVisited(creature1.row, i)) {
        creature1.col += 1;
        l.push_back("E");
        m.MarkAsPath(creature1.row, creature1.col);
        if (m.ExitRow() == row && m.ExitCol() == col)
            success = true;
        else {
            if (!m.IsPath(creature1.row, creature1.col + 1)) {
                success = moveEast(m, creature1);
            }
            if (!success) {
                success = moveNorth(m, creature1);
                if (!success) {
                    success = moveSouth(m, creature1);
                    if (!success) {
                        m.MarkAsVisited(creature1.row, creature1.col);
                        l.pop_back();
                        creature1.col = z;
                    }
                }
            }

        }

    }

    return success;
}


//! method moveWest that moves the creature to the west and checkes all the
//possible pathes from that postion
//! \param m the maze that neeeds to be solved
//! \param creature1 creature thats placed in the maze
//! \return success true if the path is found and false other wise
bool creature::moveWest(maze &m, creature creature1) {
    bool success= false;
    int z = creature1.col;
    int i = creature1.col - 1;
    creature1.col = z;
    if (m.IsClear(creature1.row, i) && creature1.row < m.getLength() && i < m.getWidth() && i >= 0 && creature1.row >= 0 &&
        !m.IsVisited(creature1.row, i)) {
        creature1.col -= 1;
        l.push_back("W");
        m.MarkAsPath(creature1.row, creature1.col);
        if (m.ExitRow() == row && m.ExitCol() == col)
            success = true;
        else {
            if (!m.IsPath(creature1.row, creature1.col - 1)) {
                success = moveWest(m, creature1);
            }
            if (!success) {
                success = moveNorth(m, creature1);
                if (!success) {
                    success = moveSouth(m, creature1);
                    if (!success) {
                        m.MarkAsVisited(creature1.row, creature1.col);
                        l.pop_back();
                        creature1.col = z;
                    }
                }
            }

        }


    }


    return success;
}

/// method that takes the creature to south and keep searching for path in that cell
/// \param m maze that needs to be solved
/// \param creature1 the creature in the maze
/// \return sucess true if the maze is solved else false
bool creature::moveSouth(maze &m, creature creature1) {
    bool success= false;
    int z = creature1.row;
    int i = creature1.row + 1;
    creature1.row = z;
    if (m.IsClear(i, creature1.col) && creature1.col <= m.getWidth() && i <= m.getLength() && creature1.col >= 0 && i >= 0 &&
        !m.IsVisited(i, creature1.col)) {
        creature1.row += 1;
        l.push_back("S");
        m.MarkAsPath(creature1.row, creature1.col);
        if (m.ExitRow() == creature1.row && m.ExitCol() == creature1.col)
            success = true;

        else {
            if (!m.IsPath(creature1.row + 1, creature1.col)) {
                success = moveSouth(m, creature1);
            }

            if (!success) {
                success = moveWest(m, creature1);

                if (!success) {
                    success = moveEast(m, creature1);

                    if (!success) {
                        m.MarkAsVisited(creature1.row, creature1.col);
                        l.pop_back();
                        creature1.row = z;
                    }
                }
            }

        }

    }

    return success;
}

