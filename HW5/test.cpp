#include "Puzzle.h"
#include "Klotski.h"
#include "Peg.h"

using namespace game;

/*Test all functions*/

int main()
{
    srand(time(NULL));

    cout << "PegSolitaire Board 1 \n";
    PegSolitaire peg1;
    cout << "Eight Puzzle Board 1 \n";
    EightPuzzle puzzle1;
    cout << "Klotski Board 1 \n";
    Klotski klotski1;

    cout << "PegSolitaire Board 2 \n";
    PegSolitaire peg2;
    cout << "Eight Puzzle Board 2 \n";
    EightPuzzle puzzle2;
    cout << "Klotski Board 2 \n";
    Klotski klotski2;

    cout << "\t\t Solving All Board Games\n\n";
    vector<BoardGame2D*> games = {&peg1,&puzzle1,&klotski1,&peg2,&puzzle2,&klotski2};
    BoardGame2D :: playVector(games);


    cout << "PegSolitaire Board 3 \n";
    PegSolitaire peg3;

    cout << "Making The B4-R Move\n";
    peg3.playUser("b4-r");
    cout << "\tMove is Made\n";
    cout << peg3 << endl;

    cout << "Eight Puzzle Board 3 \n";
    EightPuzzle puzzle3;
    cout << puzzle3 << endl;

    cout << "Making The 4-R Move\n";
    puzzle3.playUser("4-r");

    cout << "Klotski Board 3 \n";
    Klotski klotski3;
    cout << "Making The 8-d Move\n";
    klotski3.playUser("8-d");
    cout << "\tMove is Made\n";

    cout << "\n\tGOODBYE :)\n";
    return 0;
}