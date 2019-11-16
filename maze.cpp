//
// Name Bisrat Asefaw
// 10/30/2019
// CSS 342
//
// clcass that contains the methods for the maze with overloaded << method that used to display the
// maze in consule , the class also contains the helper methods IsEmpty if the cell is empty, Ispath
// if it is a path IsVisited if the specific cell is visited that used to define the maze cell content
// some extra helper methods that store the exit co-ordinate in the matrix


#include <iostream>
#include "maze.h"

/// Maze constructor that creates a 2D array and fills it with the file contents to form the appropriate maze
/// \param filename Name of the file to be readed and creat a 2D array
maze::maze(const string filename) {
    ifstream infile;
    infile.open(filename.c_str());
    length = 0;
    width = 0;
    rowExit = 0;
    columnExit = 0;
    if (infile.is_open()) {
        infile >> width;
        infile >> length;
        infile >> rowExit;
        infile >> columnExit;
        string my;

        int i = 0;
        getline(infile, my);
        while (getline(infile, my)) {


            for (int j = 0; j < width; j++) {

                field[i][j] = my[j];

            }
            i++;

        }
        infile.close();
    } else {
        cout << "file is not opened";
    }

}

/// overloaded << cout method that used to dispaly the maze in consule
/// \param out the ostream that contais the string representation of the maze
/// \param maze this maze
/// \return ostream that contains the string representation of the maze
ostream &operator<<(ostream &out, const maze &maze) {
    if (maze.getWidth() != 0 && maze.getLength() != 0) {
        for (int i = 0; i < maze.length; i++) {
            for (int j = 0; j < maze.width; j++) {
                out << maze.field[i][j];
            }
            out << endl;
        }
    } else {
        out << "maze is empety" << endl;
    }
    return out;
}

/// helper method to return the width of this maze
/// \return the width of the maze
int maze::getWidth() const {
    return width;
}

///helper method that used to get the length of the maze
/// \return length of the  maze
int maze::getLength() const {
    return length;
}

///IsWall that checks the specific cell of the 2D matrix maze is it is wall
/// \param row the row of maze
/// \param col column of the maze
/// \return true if the specific cell is wall and false otherwise
bool maze::IsWall(int row, int col) const {
    return field[row][col] == 'x' || field[row][col] == '#';
}

/// IsPath that checks the specific cell of the maze if it is path or not
/// \param row the row representation of the maze
/// \param col the column representation of the maze
/// \return true this cell is path and false otherwise
bool maze::IsPath(int row, int col) const {
    return field[row][col] == '*';
}

///IsClear that checks if the specific cell in the maze is clear or not
/// \param row the row representation of the cell
/// \param column the column representation of the cell
/// \return true if the cell is clear and false otherwise
bool maze::IsClear(int row, int column) const {
    if (!IsWall(row, column) && !IsPath(row, column)) {
        return true;
    } else {
        return false;
    }
}


///IsVisited that checks if the cell in the maze is visited or not
/// \param row row representation of the maze
/// \param col column representation of the maze
/// \return true if it is visited otherwise false
bool maze::IsVisited(int row, int col) const {
    if (field[row][col] == '+') {
        return true;
    }
    return false;
}

///MarkAsPath method that marks the specific cell of the maze as path
/// \param row row representation of the maze
/// \param col column representation of the maze
void maze::MarkAsPath(int row, int col) {
    field[row][col] = '*';
}

/// MarkAsVisited that marks the specific call of the maze as a visited
/// \param row row representation of the maze
/// \param col column representation of the maze
void maze::MarkAsVisited(int row, int col) {
    field[row][col] = '+';
}

/// helper method that return the exit column of the maze
/// \return column exit of the maze
int maze::ExitCol() const {
    return columnExit;
}

/// helper method that return the exit row of the maze
/// \return the exit row of the maze
int maze::ExitRow() const {
    return rowExit;
}




