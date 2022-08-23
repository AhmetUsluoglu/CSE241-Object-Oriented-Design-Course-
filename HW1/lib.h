#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

enum class pegType : char {empty = '.', peg = 'P', free = ' '};
typedef std :: vector<std :: vector<pegType>> pegBoard ;

int setGame();
void printBoard(int boardSize, pegBoard *board);
int check (int row, int column, int boardSize, char direction, pegBoard *board);
int move(int row, int column, int boardSize, char direction, pegBoard *board);
int pcmove(pegBoard *board, int boardSize);
int checkAll(pegBoard *board, int boardSize);
int controlInput(string movement);
