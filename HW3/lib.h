#include <iostream>
#include <vector>
#include <time.h>
#include <fstream>
#include <string>

using namespace std;

enum class pegType : char {empty = '.', peg = 'P', free = ' '};
typedef std :: vector<std :: vector<pegType>> pegBoard ;

int setGame();
int controlFilename(string filename);
int controlInput(string movement);


class PegSolitaire
{
    private:
        int select, row, column, size;
        static int peg_Count;
        /* data */
    
    
    public:
        class Cell
        {
            private:
                int cellRow, cellColumn;
                char cellDirection;
                pegType peg;
                /* data */
            public:
                Cell(/* args */);
                Cell(pegType pegValue){peg = pegValue;};
                pegType getPegType(){return peg;};
                void setPegType(pegType pegValue){peg = pegValue;};

                void setCellRow(int rowValue){cellRow = rowValue;};
                void setCellColumn(int columnValue){cellColumn = columnValue;};
                void setCellDirection(char directionValue){cellDirection = directionValue;};

                inline int getCellRow(){return cellRow;};
                inline int getCellColumn(){return cellColumn;};
                inline int getCellDirection(){return cellDirection;};

        };
        
        vector<vector<pegType>> *initialBoard;
        vector<vector<Cell>> board;     
        Cell chosen;

        
        const int getBoardtype(){return select;};
        const int getRow(){return row;};
        const int getColumn(){return column;};

        void setRow(int rowValue){row = rowValue;};
        void setColumn(int columnValue){column = columnValue;};
        void setSize(int sizeValue){size = sizeValue;};

        
        void printBoard();
        void select_InitialBoard();
        void setBoard();
        
        void play();
        void play(string input);

        int randomRow(){return rand() % size;};
        int randomColumn(){return rand() % size;};
        char randomDirection();

        int check();
        int move();

        int checkAll();
        void playAll();

        
        int File(string filename);

        
        PegSolitaire(/* NO Argument */);
        PegSolitaire(int selectValue);

};
