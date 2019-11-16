
// Name Bisrat Asefaw
// 10/30/2019
// CSS 342
//
// clcass that contains the methods for the maze with overloaded << method that used to display the
// maze in consule , the class also contains the helper methods IsEmpty if the cell is empty, Ispath
// if it is a path IsVisited if the specific cell is visited that used to define the maze cell content
// some extra helper methods that store the exit co-ordinate in the matrix


#ifndef HW_3_MAZE_H
#define HW_3_MAZE_H


#include <fstream>
#include <ostream>
#include <string>

using namespace std;

class maze {
    static const int MAX_SIZE = 100;
public:

    /// Maze constructor that creates a 2D array and fills it with the file contents to form the appropriate maze
    /// \param filename Name of the file to be readed and creat a 2D array
    explicit maze(const string filename);


/// overloaded << cout method that used to dispaly the maze in consule
/// \param out the ostream that contais the string representation of the maze
/// \param maze this maze
/// \return ostream that contains the string representation of the maze
    friend ostream &operator<<(ostream &out, const maze &maze);

///IsClear that checks if the specific cell in the maze is clear or not
/// \param row the row representation of the cell
/// \param column the column representation of the cell
/// \return true if the cell is clear and false otherwise
    bool IsClear(int row, int column) const;

/*!
 *
 * @param row
 * @param col
 * @return
 */
    bool IsWall(int row, int col) const;

///
/// \param row
/// \param col
/// \return
    bool IsPath(int row, int col) const;

///IsVisited that checks if the cell in the maze is visited or not
/// \param row row representation of the maze
/// \param col column representation of the maze
/// \return true if it is visited otherwise false
    bool IsVisited(int row, int col) const;

    ///MarkAsPath method that marks the specific cell of the maze as path
    /// \param row row representation of the maze
    /// \param col column representation of the maze
    void MarkAsPath(int row, int col);

    /// MarkAsVisited that marks the specific call of the maze as a visited
    /// \param row row representation of the maze
    /// \param col column representation of the maze
    void MarkAsVisited(int row, int col);

/*!
 * helper method that return the exit column of the maze
 * @return row exit of the maze
 */
    int ExitRow() const;

/// helper method that return the exit column of the maze
/// \return column exit of the maze
    int ExitCol() const;

/// helper method to return the width of this maze
/// \return the width of the maze
    int getWidth() const;

    ///helper method that used to get the length of the maze
/// \return length of the  maze
    int getLength() const;

/*!
 * private memeber variables of the class maze
 */
private:
    char field[MAX_SIZE][MAX_SIZE];
    int width;
    int length;
    int rowExit;
    int columnExit;
};


#endif //HW_3_MAZE_H
