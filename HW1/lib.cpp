#include "lib.h"

int setGame()
{
    cout << "   Welcome to solo test    \n";
    cout << "   Please Enter The Board Type:";
    int boardType, boardSize, playerType, count = 0;
    string movement;
    cin >> boardType;
    pegBoard *board;

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
            break;

        case 7:/*Board Arbitrary*/
            cout << "Not Implemented :(\n";
            break;
        default:
            break;
    }

    printBoard(boardSize, board);

    /*Gets player type*/
    while(!(playerType == 1 || playerType == 2))
    {
        cout << "Please Enter The Player Type (1 (Player) -  2 (Computer):";
        cin >> playerType;
        switch(playerType)
        {
            case 1:/*Human plays*/
                while(1)
                {   
                    /*Gets input and cheks if it's correct*/
                    do{
                        cout << "Please Enter a Valid Move (Sample: B4-L):";
                        cin >> movement;
                    }while(controlInput(movement) == 0);
                    
                    int row = movement[1] - '0' - 1;
                    int column = toupper(movement[0]) - 'A';
                    char direction = toupper(movement[3]);
                    
                    if(move(row, column, boardSize - 1, direction, board) == 1)
                    {
                        printBoard(boardSize, board);
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
                break;
            
            default:
                cout << "Invalid Player Type, Try Again\n";
                break;
        }
    }
    return 0;
}
/*Prints The Board*/
void printBoard(int boardSize, pegBoard *board)
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
                    printBoard(boardSize, board);
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
int controlInput(string movement)
{
    int flag = 1;
    cout << movement[0]<< movement[1]<< movement[2]<< movement[3]<<endl;
    if(movement.size() != 4) flag = 0;
    if(toupper(movement[0]) < 'A' || toupper(movement[0]) > 'Z') flag = 0;
    if(movement[1] < '0' || movement[1] > '9') flag = 0;
    if(movement[2] != '-') flag = 0;
    if(!(toupper(movement[3]) == 'U' || toupper(movement[3]) == 'D'|| toupper(movement[3]) == 'R'|| toupper(movement[3]) == 'L')) flag = 0;
    if(flag == 0) cout << "Invalid Movement, Try Again\n";
    return flag;
}
