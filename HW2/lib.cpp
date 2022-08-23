#include "lib.h"

int setGame()
{
    /*Some of the necessary variables declared at the start of the program.*/
    cout << "   Welcome to solo test    \n";
    int boardType, boardSize, playerType = 3, count = 0, flag = 0, row, column, direction , flagBoard = 0;
    
    string movement, boardType_str;
    pegBoard *board = NULL;
    /*Allocated memory to our soon to be game map.*/
    board = new pegBoard;
    decltype(flagBoard) flagPlayer = 0;
    
    /*Gets player type and starts the game loop*/
    while(!(playerType == 1 || playerType == 2))
    {
        /*Gets board type
        It can get load and save commands.*/
        do{
            cout << "   Please Enter The Board Type:";
            getline(cin,boardType_str); 
            if(controlFilename(boardType_str, board) != 1)/*Control filename function determines if the input is load - save command.*/
            {
                boardType = boardType_str[0] - 48;
            }
            else 
            {
                flagBoard = 1;
                boardType = 7;
            } 
        }while ((boardType_str[0] - 48 < 1 || boardType_str[0] - 48  > 6) && flagBoard == 0);/*Loops until input is between 1-6 or load-save command*/
        
        
        /*Selects Board type based on user input*/
        switch (boardType)
        {
        case 1:/*Board 1*/
            boardSize = 7;
            board = new pegBoard
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
                boardSize = 9;
                board = new pegBoard
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
                boardSize = 8;
                board = new pegBoard
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
                boardSize = 7;
                board = new pegBoard
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
                boardSize = 9;
                board = new pegBoard
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
                boardSize = 9;
                board = new pegBoard
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
        /*Sets row count as board's size (row * row)-- Row is the longest value here*/
        boardSize = (*board).size();
        if(boardType <=6 && boardType >=1)  printBoard(board, boardSize);

        do{ /*Gets Player Type*/
            cout << "Please Enter The Player Type (1 (Player) -  2 (Computer) - 3 (End Game):";
            cin >> playerType;
            cin.ignore();
            if(playerType < 1 || playerType >3) cout << "Invalid Player Type, Try Again\n";
        }while(playerType < 1 || playerType >3);
        switch(playerType)
        {
            case 1:/*Human plays*/
                while(1)
                {   
                    /*Gets input and cheks if it's correct*/
                    do{
                        boardSize = (*board).size();
                        cout << "\n\tEnter 1 to end the game.\n";
                        cout << "\tEnter 2 to solve it automatically.\n";
                        cout << "\tEnter a Move to play (Sample: B4-L):";
                        getline(cin,movement);
                        if(movement[0] == '1')
                        {
                            cout << "\n\t\tGOODBYE!\n";
                            return 0;
                        }
                        else if(movement[0] == '2')
                        {
                            pcmove(board, board->size());
                            flag = 0;
                        }
                        else flag = controlInput(movement, board);/*Cheks if input is movement or a load -save command*/

                    }while(flag != 1);
                    
                    if(flag == 1)/*Input is Movement*/
                    {
                        cout << movement << endl;
                        row = movement[1] - '0' - 1;
                        column = toupper(movement[0]) - 'A';
                        direction = toupper(movement[3]);
                    }
                    
                    if(move(row, column, boardSize - 1, direction, board) == 1)/*Checks teh move if possible executes it.*/
                    {
                        printBoard(board, boardSize);
                        if (checkAll(board, boardSize) == 0) /*Game is ended, Print The Score*/ 
                        {
                            for(int i = 0; i < boardSize; ++i)
                            {
                                for(int j = 0; j < boardSize; ++j)
                                {
                                    if((*board)[i][j] == pegType :: peg) count++;
                                }
                            }
                            cout << count << " pegs left\n";
                            break;
                        }
                    }   
                    else cout << "Try Again\n";
                }
                break;
            
            case 2: /*Computer plays until the end*/
                pcmove(board, boardSize);
                flagPlayer = 1;
                break;
            
            case 3:
                cout << "\n\t\tGOODBYE!\n";
                return 0;
                break;
            default:
                cout << "Invalid Player Type, Try Again\n";
                break;
        }

        if(flagPlayer == 1) playerType = 0;    
    }
    return 0;
}
/*Prints The Board*/
void printBoard(const pegBoard *board, int boardSize)
{
    int rownum = 0;
    char columnletter = 'a';
    cout << "    ";
    for(int k = 0; k < boardSize; k++)
        {
           cout << char(columnletter) << ' ';
            columnletter++;
        }
        cout << endl;
    for(int i = 0; i < boardSize; i++)
    {
        cout << rownum + 1<< "   ";
        
        for(int j = 0; j < boardSize; j++)
        {
            cout << (char)(*board)[i][j]<<' ';
        }
        cout << endl;
        rownum++;
    }
    cout << endl;
}

/*Cheks the current move is possible or not. If possible returns 1 else 0.*/
int check (int row, int column, int boardSize, char direction,pegBoard *board)
{
    int flag = 0;
    switch (direction)
    {
        case 'U':/*Up*/
            if((*board)[row][column] == pegType :: peg && (row != 0 && row != 1))
            {
                if((*board)[row - 1][column] == pegType :: peg && (*board)[row - 2][column] == pegType :: empty)
                {
                   flag = 1;
                }
            }
            break;
        case 'D':/*Down*/
            if((*board)[row][column] == pegType :: peg && (row != boardSize && row != boardSize -1))
            {
                if((*board)[row + 1][column] == pegType :: peg && (*board)[row + 2][column] == pegType :: empty)
                {
                   flag = 1;
                }
            }
            break;
        case 'R':/*Right*/
            if((*board)[row][column] == pegType :: peg && (column != boardSize && column != boardSize -1))
            {
                if((*board)[row][column + 1] == pegType :: peg && (*board)[row][column + 2] == pegType :: empty)
                {
                   flag = 1;
                }
            }
            break;
        case 'L':/*Left*/
            if((*board)[row][column] == pegType :: peg && (column != 0 && column != 1))
            {
                if((*board)[row][column - 1] == pegType :: peg && (*board)[row][column - 2] == pegType :: empty)
                {
                   flag = 1;
                }
            }
            break;
        
        default:
            break;
    }
    return flag;
};

/*If the checked move is possible, executes the move. If move Succesful returns 1 else 0.*/
int move(int row, int column, int boardSize, char direction, pegBoard *board)
{ 
    int flag = 1;
    switch (direction)
    {
        case 'U':/*Up*/
            if(check(row, column, boardSize - 1, direction, board) == 1)
            {
                (*board)[row][column] = pegType :: empty;
                (*board)[row - 1][column] = pegType :: empty;
                (*board)[row - 2][column] = pegType :: peg;
            }
            else flag = 0;
            break;
        case 'D':/*Down*/
            if(check(row, column, boardSize - 1, direction, board) == 1)
            {
                (*board)[row][column] = pegType :: empty;
                (*board)[row + 1][column] = pegType :: empty;
                (*board)[row + 2][column] = pegType :: peg;
            }
            else flag = 0;
            break;
        case 'R':/*Right*/
            if(check(row, column, boardSize - 1, direction, board) == 1)
            {
                (*board)[row][column] = pegType :: empty;
                (*board)[row][column + 1] = pegType :: empty;
                (*board)[row][column + 2] = pegType :: peg;
            }
            else flag = 0;
            break;
        case 'L':/*Left*/
            if(check(row, column, boardSize - 1, direction, board) == 1)
            {
                (*board)[row][column] = pegType :: empty;
                (*board)[row][column - 1] = pegType :: empty;
                (*board)[row][column - 2] = pegType :: peg;
            }
            else flag = 0;
            break;
        default:
            break;
    }
    return flag;
};

/*Computer automatically plays the game until the end.*/
int pcmove(pegBoard *board, int boardSize)
{
    int count = 0, flag = 0, row, column;
    vector<char> directionArray {'U','D','R','L'};
    char direction;
    
    while(1)
    {
        flag = 0;
        if (checkAll(board, boardSize) == 0) /*Game is ended, Print The Score*/ 
        {
            for(int i = 0; i < boardSize; ++i)
            {
                for(int j = 0; j < boardSize; ++j)
                {
                    if((*board)[i][j] == pegType :: peg) count++;
                }
            }
            break;
        }
        else /*Game Continues, Randomly find a peg to move*/
        {
            while(flag == 0)
            {
                /*Find A new Random Move*/
                row = rand() % boardSize;
                column = rand() % boardSize;
                direction = directionArray[rand() % 4];
                
                if(check(row, column, boardSize - 1, direction, board) == 1) /*Make The Move*/
                {
                    move(row, column, boardSize - 1, direction, board);
                    cout << (char)(column + 'A') << row + 1 <<  '-' << direction << endl;
                    printBoard(board, boardSize);
                    flag = 1;
                }
            }
        }
    }
    cout << count << " pegs left\n";
    return 0;
};

int checkAll(pegBoard *board, int boardSize)
{
    int endGame = 0; 
    vector<char> directionArray {'U','D','R','L'};
    char direction;
    
    for(int i = 0; i < boardSize; ++i)
    {
        for(int j = 0; j < boardSize; ++j)
        {
            for(int k = 0;k < 4; ++k)
            {
                /*If ther is a possible move Check returns 1 game is not ended, else endGame equals 0*/
                endGame = check(i , j, boardSize - 1, direction = directionArray[k], board);
                /*If there is any valid move Game is not ended*/
                if(endGame == 1)
                {
                    endGame = 1;
                    i = boardSize;
                    j = boardSize;
                    k = 4;
                } 
            }
        }
    }
    /*If no valid move is possible endGame returns 0 by default*/
    return endGame;
};

/*Controls user input for each move.*/
int controlInput(string movement, pegBoard *board)
{
    int flag = 1;
    if(movement.size() != 4) flag = 0;
    if(toupper(movement[0]) < 'A' || toupper(movement[0]) > 'Z') flag = 0;
    if(movement[1] < '0' || movement[1] > '9') flag = 0;
    if(movement[2] != '-') flag = 0;
    if(!(toupper(movement[3]) == 'U' || toupper(movement[3]) == 'D'|| toupper(movement[3]) == 'R'|| toupper(movement[3]) == 'L')) flag = 0;
    if(flag == 0)/*If input is not movement*/
    {
        if(controlFilename(movement, board) == 1)/*if input not movement but a command*/
        {
            flag = 2;
        }
        else cout << "  Invalid Input, Try Again\n";/*Completely wrong input*/
    } 
    return flag;
}

/*Cheks the input if it's save - load command and executes the command*/
/*if it has load in it loads the game , if it has save in it saves the game*/
int controlFilename(string filename, pegBoard *board)
{
    int flag = 1, row = 0, col = 0, rowmax = 0 ,max = 0;
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
                    row++;
                }
                else 
                {
                    if(row > rowmax) rowmax= row;
                    col++;
                    row = 0;
                }
            }
            if(rowmax >= col) max = rowmax;
            else max = col;/*Max value of row or column is assigned to max variable*/
            
            /*refreshes the cursor to the start of the file*/
            my_file.clear();
            my_file.seekg(0, ios_base::beg);
            
            int i = 0;
            /*Resizes the 2D vector */
            board->resize(max,vector <pegType> (max));

            int j = 0;
            /*Loads values from file to the map vector one by one*/
            while(my_file.get(input))
            {
                if(input !='\n' && input != EOF)
                {
                    (*board)[i][j] = (pegType)input;
                    j++;
                }
                else if(input == EOF) break;
                else 
                {
                    i++;
                    j = 0;
                }
            }
            printBoard(board, max);
            cout << endl;
            my_file.close();
            cout << "   " << filename << " is loaded.\n";
        } 
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
            for(auto &row : *board)
            {
                for(auto &column : row)
                {
                    my_file << (char)column;
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

