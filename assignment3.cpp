/*!
 *  Bisrat Asefaw
 *  10/30/2019
 *  CSS 342
 *
 *  test classes for Maze and creature classes that checkes for possible test
 *  classes
 */

#include <iostream>
#include <string>

#include "maze.h"
#include "creature.h"


/// test1 that checks for successful with a 100 by 100 matrix
void test1() {
    cout << "---*******----***--tets1 that has a maze matrix 100 rows by 100 columns----******" << endl;
    maze my("maze3.txt");

    // my creature constructor accepts row and column specification of the creature
    creature crt(1, 1);

    string info = crt.Solve(my);
    cout << info << endl;
    cout << my << endl;
}

// test2 for that checks for successful path in 5x20 maze
void test2() {
    cout << "---*******----***--tets2 that has a maze matrix 5 rows by 20 columns----******" << endl;
    maze my("maze1.txt");
    // my creature constructor accepts row and column specification of the creature
    creature crt(2, 14);

    string info = crt.Solve(my);
    cout << info << endl;
    cout << my << endl;



}

// this test3 has unsucessful path test ----- when there is no path
void test3() {
    cout << "---*******----***--tets3 that has a maze matrix 5 rows by 20 columns----******" << endl;
    maze my("maze1.txt");
    // my creature constructor accepts row and column specification of the creature
    creature crt(4, 4);
    string info = crt.Solve(my);
    cout << info << endl;
    cout << my << endl;


}

//maze 2 test method
void test5(){
    cout << "---*******----***--tets5 that has a maze matrix 5 rows by 10 columns----******" << endl;
    maze mm("maze2.txt");
    // my creature constructor accepts row and column specification of the creature
    creature crt2(2, 7);

    string info2 = crt2.Solve(mm);
    cout << info2 << endl;
    cout << mm << endl;
}
int main() {
    cout << "-----NOTE: the creature constructor accepts a row and column as (row, col)-----" << endl;
    test2();
    test3();
    test5();
    test1();

    return 0;
}

