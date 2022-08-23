#include <iostream>
#include <vector>
#include <time.h>
#include <fstream>
#include <string>

using namespace std;

enum class pegType : char {empty = '.', peg = 'P', free = ' '};
typedef std :: vector<std :: vector<pegType>> pegBoard ;

int setGame();
void printBoard(const pegBoard *board, int boardSize = 0);
int check (int row, int column, int boardSize, char direction, pegBoard *board);
int move(int row, int column, int boardSize, char direction, pegBoard *board);
int pcmove(pegBoard *board, int boardSize);
int checkAll(pegBoard *board, int boardSize);
int controlInput(string movement, pegBoard *board);
int controlFilename(string filename, pegBoard *board);
