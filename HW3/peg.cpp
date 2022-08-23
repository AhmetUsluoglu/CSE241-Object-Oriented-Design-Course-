#include "lib.h"

PegSolitaire :: PegSolitaire() : select(1),row(5),column(5),size(5) {select_InitialBoard();}

PegSolitaire :: PegSolitaire(int selectValue)
{
    if(selectValue < 1 || selectValue > 7) select = 1;
    else select = selectValue;
    select_InitialBoard();
}

PegSolitaire :: Cell :: Cell(){}



void PegSolitaire :: printBoard()
{
    int rownum = 0;
    char columnletter = 'a';
    cout << "    ";
    for(int k = 0; k < size; k++)
        {
           cout << char(columnletter) << ' ';
            columnletter++;
        }
        cout << endl;
    for(int i = 0; i < size; i++)
    {
        cout << rownum + 1<< "   ";
        
        for(int j = 0; j < size; j++)
        {
            cout << (char)(board[i][j].getPegType())<<' ';
        }
        cout << endl;
        rownum++;
    }
    cout << endl;

}

void PegSolitaire :: select_InitialBoard()
{
    switch (select)
        {
        case 1:/*Board 1*/
            size = 7, row = 7, column = 7;
            static int pegCount = 38;
            initialBoard = new pegBoard
            {
                {pegType :: free,pegType :: free,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: free,pegType :: free},
                {pegType :: free,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: free},
                {pegType :: peg,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: peg},
                {pegType :: peg,pegType :: peg,pegType :: peg,pegType :: empty,pegType :: peg,pegType :: peg,pegType :: peg},
                {pegType :: peg,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: peg},
                {pegType :: free,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: free},
                {pegType :: free,pegType :: free,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: free,pegType :: free},
            };
            break;

        case 2:/*Board 2*/
            size = 9, row = 9, column = 9;
            static int pegCount1 = 45;
            initialBoard = new pegBoard
            {
                {pegType :: free,pegType :: free,pegType :: free,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: free,pegType :: free,pegType :: free},
                {pegType :: free,pegType :: free,pegType :: free,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: free,pegType :: free,pegType :: free},
                {pegType :: free,pegType :: free,pegType :: free,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: free,pegType :: free,pegType :: free},
                {pegType :: peg,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: peg},
                {pegType :: peg,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: empty,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: peg},
                {pegType :: peg,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: peg},
                {pegType :: free,pegType :: free,pegType :: free,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: free,pegType :: free,pegType :: free},
                {pegType :: free,pegType :: free,pegType :: free,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: free,pegType :: free,pegType :: free},
                {pegType :: free,pegType :: free,pegType :: free,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: free,pegType :: free,pegType :: free},                
            };
            break;
        case 3:/*Board 3*/
            size = 8, row = 8, column = 8;
            static int pegCount2 = 38;
            initialBoard = new pegBoard
            {
                {pegType :: free,pegType :: free,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: free,pegType :: free,pegType :: free},
                {pegType :: free,pegType :: free,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: free,pegType :: free,pegType :: free},
                {pegType :: free,pegType :: free,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: free,pegType :: free,pegType :: free},
                {pegType :: peg,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: peg},
                {pegType :: peg,pegType :: peg,pegType :: peg,pegType :: empty,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: peg},
                {pegType :: peg,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: peg},
                {pegType :: free,pegType :: free,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: free,pegType :: free,pegType :: free},
                {pegType :: free,pegType :: free,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: free,pegType :: free,pegType :: free},
            };
            break;
        case 4:/*Board 4*/
            size = 7, row = 7, column = 7;
            static int pegCount3 = 32;
            initialBoard = new pegBoard
            {
                {pegType :: free,pegType :: free,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: free,pegType :: free},
                {pegType :: free,pegType :: free,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: free,pegType :: free},
                {pegType :: peg,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: peg},
                {pegType :: peg,pegType :: peg,pegType :: peg,pegType :: empty,pegType :: peg,pegType :: peg,pegType :: peg},
                {pegType :: peg,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: peg},
                {pegType :: free,pegType :: free,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: free,pegType :: free},
                {pegType :: free,pegType :: free,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: free,pegType :: free},
            };
            break;
        case 5:/*Board 5*/
            size = 9, row = 9, column = 9;
            static int pegCount4 = 40;

            initialBoard = new pegBoard
            {
                {pegType :: free,pegType :: free,pegType :: free,pegType :: free,pegType :: peg,pegType :: free,pegType :: free,pegType :: free,pegType :: free},
                {pegType :: free,pegType :: free,pegType :: free,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: free,pegType :: free,pegType :: free},
                {pegType :: free,pegType :: free,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: free,pegType :: free},
                {pegType :: free,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: free},
                {pegType :: peg,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: empty,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: peg},
                {pegType :: free,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: free},
                {pegType :: free,pegType :: free,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: free,pegType :: free},
                {pegType :: free,pegType :: free,pegType :: free,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: free,pegType :: free,pegType :: free},
                {pegType :: free,pegType :: free,pegType :: free,pegType :: free,pegType :: peg,pegType :: free,pegType :: free,pegType :: free,pegType :: free},
            };
            break;
        case 6:/*Board 6*/
            cout << "Not Implemented :(\n";
            size = 9, row = 9, column = 9;
            initialBoard = new pegBoard
            {
                {pegType :: free,pegType :: free,pegType :: free,pegType :: free,pegType :: empty,pegType :: free,pegType :: free,pegType :: free,pegType :: free},
                {pegType :: free,pegType :: free,pegType :: free,pegType :: peg,pegType :: free,pegType :: peg,pegType :: free,pegType :: free,pegType :: free},
                {pegType :: free,pegType :: free,pegType :: peg,pegType :: free,pegType :: peg,pegType :: free,pegType :: peg,pegType :: free,pegType :: free},
                {pegType :: free,pegType :: peg,pegType :: free,pegType :: peg,pegType :: free,pegType :: peg,pegType :: free,pegType :: peg,pegType :: free},
                {pegType :: peg,pegType :: free,pegType :: peg,pegType :: free,pegType :: peg,pegType :: free,pegType :: peg,pegType :: free,pegType :: peg},
                {pegType :: free,pegType :: free,pegType :: free,pegType :: free,pegType :: free,pegType :: free,pegType :: free,pegType :: free,pegType :: free},
                {pegType :: free,pegType :: free,pegType :: free,pegType :: free,pegType :: free,pegType :: free,pegType :: free,pegType :: free,pegType :: free},
                {pegType :: free,pegType :: free,pegType :: free,pegType :: free,pegType :: free,pegType :: free,pegType :: free,pegType :: free,pegType :: free},
                {pegType :: free,pegType :: free,pegType :: free,pegType :: free,pegType :: free,pegType :: free,pegType :: free,pegType :: free,pegType :: free},
            };
            break;
        case 7:/*Caution case*/
            break;
        default:
            /**/cout << "Invalid Board Type.\n";
            break;
    }
    board.resize(row , vector<Cell>(column));
    setBoard();
    delete initialBoard;
}

void PegSolitaire :: setBoard()
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
        {
            Cell cell((*initialBoard)[i][j]);
            board[i][j] = cell;
        }
    }
}


void PegSolitaire :: play()
{
    int row, column, flag = 1;
    char direction;
    
    while (flag)
    {
        chosen.setCellRow(randomRow());
        chosen.setCellColumn(randomColumn());
        chosen.setCellDirection(randomDirection());

        if(check())
        {
            cout << (char)('A' + (char)chosen.getCellColumn()) <<endl << chosen.getCellRow() + 1 <<endl<< (char)chosen.getCellDirection()<<endl;
            move();
            flag = 0;
        }   
    }
}

void PegSolitaire :: play(string input)
{
    chosen.setCellRow(input[1] - '0' - 1);
    chosen.setCellColumn(input[0] - 'A');
    chosen.setCellDirection(input[3]);

    if(check())
    {
        cout << (char)('A' + (char)chosen.getCellColumn()) <<endl << chosen.getCellRow() + 1 <<endl<< (char)chosen.getCellDirection()<<endl;
        move();
    }   
    
}

char PegSolitaire :: randomDirection()
{
    vector<char> directionArray {'U','D','R','L'};
    return directionArray[rand() % 4];
}

int PegSolitaire :: check()
{
    int flag = 0;
    row = chosen.getCellRow();
    column = chosen.getCellColumn();
    switch (chosen.getCellDirection())
    {
        case 'U':/*Up*/
            if(board[row][column].getPegType() == pegType :: peg && (row != 0 && row != 1))
            {
                if(board[row - 1][column].getPegType() == pegType :: peg && board[row - 2][column].getPegType() == pegType :: empty)
                {
                   flag = 1;
                }
            }
            break;
        case 'D':/*Down*/
            if(board[row][column].getPegType() == pegType :: peg && (row != size -1 && row != size -2))
            {
                if(board[row + 1][column].getPegType() == pegType :: peg && board[row + 2][column].getPegType() == pegType :: empty)
                {
                   flag = 1;
                }
            }
            break;
        case 'R':/*Right*/
            if(board[row][column].getPegType() == pegType :: peg && (column != size-1 && column != size -2))
            {
                if(board[row][column + 1].getPegType() == pegType :: peg && board[row][column + 2].getPegType() == pegType :: empty)
                {
                   flag = 1;
                }
            }
            break;
        case 'L':/*Left*/
            if(board[row][column].getPegType() == pegType :: peg && (column != 0 && column != 1))
            {
                if(board[row][column - 1].getPegType() == pegType :: peg && board[row][column - 2].getPegType() == pegType :: empty)
                {
                   flag = 1;
                }
            }
            break;
        
        default:
            break;
    }
    return flag;
}

int PegSolitaire :: move()
{
    int flag = 1;
    row = chosen.getCellRow();
    column = chosen.getCellColumn();
    switch (chosen.getCellDirection())
    {
        case 'U':/*Up*/
            board[row][column].setPegType(pegType :: empty);
            board[row - 1][column].setPegType(pegType :: empty);
            board[row - 2][column].setPegType(pegType :: peg);
            flag = 0;
            break;
        case 'D':/*Down*/
            board[row][column].setPegType(pegType :: empty);
            board[row + 1][column].setPegType(pegType :: empty);
            board[row + 2][column].setPegType(pegType :: peg);
            flag = 0;
            break;
        case 'R':/*Right*/
            board[row][column].setPegType(pegType :: empty);
            board[row][column + 1].setPegType(pegType :: empty);
            board[row][column + 2].setPegType(pegType :: peg);
            flag = 0;
            break;
        case 'L':/*Left*/
            board[row][column].setPegType(pegType :: empty);
            board[row][column - 1].setPegType(pegType :: empty);
            board[row][column - 2].setPegType(pegType :: peg);
            flag = 0;
            break;
        default:
            break;
    }
    return flag;
}

void PegSolitaire :: playAll()
{
    while(checkAll())
    {
        play();
        printBoard();
    }
}

int PegSolitaire :: checkAll()
{
    int endGame = 0; 
    vector<char> directionArray {'U','D','R','L'};
    char direction;
    
    for(int i = 0; i < size; ++i)
    {
        for(int j = 0; j < size; ++j)
        {
            for(int k = 0;k < 4; ++k)
            {
                chosen.setCellRow(i);
                chosen.setCellColumn(j);
                chosen.setCellDirection(directionArray[k]);
                /*If ther is a possible move Check returns 1 game is not ended, else endGame equals 0*/
                endGame = check();
                /*If there is any valid move Game is not ended*/
                if(endGame == 1)
                {
                    endGame = 1;
                    i = size;
                    j = size;
                    k = 4;
                } 
            }
        }
    }
    /*If no valid move is possible endGame returns 0 by default*/
    return endGame;
};
/*File Functions*/

int PegSolitaire :: File(string filename)
{
    int flag = 1, line = 0, col = 0, linemax = 0 ,max = 0, min = 0;
    char input;
    string load = "load", save = "save";

    if(filename.find(load) != string::npos)/*Checks load statement*/
    {
        /*skips load part in the string*/
        filename.erase(0, 5);
        fstream my_file;
        /*Opens and checks the file*/
        my_file.open(filename, ios::in);
        if (!my_file)
        {
            cerr << "No such file\n";
            flag = 0;
        }   
        else/*Counting the max length of the lines*/
        {
            while(my_file.get(input))
            {
                if(input != '\n')
                {
                    line++;
                }
                else 
                {
                    if(line > linemax) linemax= line;
                    col++;
                    line = 0;
                }
            }
            if(linemax >= col) min = col;
            else min = linemax;/*Max value of line or column is assigned to max variable*/
            min--;
            /*refreshes the cursor to the start of the file*/
            my_file.clear();
            my_file.seekg(0, ios_base::beg);
            
            int i = 0;

            /*Resizes the 2D vector */
            initialBoard = new pegBoard;
            initialBoard->resize(min,vector <pegType> (min));


            int j = 0;
            /*Loads values from file to the map vector one by one*/
            while(my_file.get(input))
            {
                if(input !='\n' && input != EOF)
                {
                    if(i < min && j < min)
                    {
                        (*initialBoard)[i][j] = (pegType)input;
                    }    
                    j++;
                }
                else if(input == EOF) break;
                else 
                {
                    i++;
                    j = 0;
                }
            }
            cout << endl;
            my_file.close();
            cout << "   " << filename << " is loaded.\n";
        }
        setRow(min), setColumn(min), setSize(min);
        board.resize(min , vector<Cell>(min));

        setBoard();
        return flag;
    }
    else if(filename.find(save) != string::npos)/*Checks save statement*/
    {
        /*Saves current board to txt file*/
        /*skips the save part*/
        filename.erase(0, 5);
        fstream my_file;
        my_file.open(filename, ios::out);
        if (!my_file)
        {
            cerr << "File is not created\n";
            flag = 0;
        }   
        else /*writes the map in to the file*/
        {
            for(int i = 0 ; i < size;i++ )
            {
                for(int j = 0 ; j < size;j++ )
                {
                    my_file << (char)board[i][j].getPegType();
                }
                my_file << endl;
            }
            my_file.close();
            cout << "   " << filename << " is saved.\n";
        }
    }
    else flag = 0;
    return flag; /*returns 1 if the input is save and load command, else returns 0.*/
}

