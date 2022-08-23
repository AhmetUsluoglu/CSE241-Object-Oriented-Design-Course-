#include "Puzzle.h"
#include "Klotski.h"
#include "Peg.h"

namespace game{

BoardGame2D :: BoardGame2D(/* args */){};

//Plays the game until it's finish 
void BoardGame2D :: playAutoAll()
{
    while (endGame()) {playAuto();}
    printBoard(cout);
    cout << "Your Score is " << boardScore() << endl << endl;
}
//Plays The game for one move 
void BoardGame2D ::playAuto()
{
    while (1)
    {
        randomMove();
        if(check())
        {
            move();
            //printBoard(cout);
            break; 
        }   
    }
}
//plays the Game according to user input until it's finishes
void BoardGame2D ::playUser()
{
    string input = "";
    while (endGame())
    {
        getline(cin,input);
        playUser(input);
    }
    cout << "Game is ended. Your Score is " << boardScore() << endl;
}
//Plays the for one move based on user input
void BoardGame2D ::playUser(string input)
{
    if (controlInput(input))
    {
        assignInput(input);
        if(check() == 1)
        {
            move();
            printBoard(cout);
        }
        else cout << "Invalid Move! Try Again. \n";
    }
    else cout << "Invalid Input! Try Again. \n";
}
// Plays all games inside the vector
void BoardGame2D :: playVector(vector<BoardGame2D*> games)
{
    for(auto game : games) game->playAutoAll();
}
// Stream insertion operator overload
ostream & operator<<(ostream& out, BoardGame2D &board)
{
    board.printBoard(out);
    return out;
}




///////////////////////////////////////// KLOTSKI ////////////////////////////////////////////////////////////////////

//Constructor
Klotski :: Klotski(){initialize();printBoard(cout);};

// initializes the board
void Klotski :: initialize()
{
    Board = 
    {
        {'1','2','2','3'}, 
        {'1','2','2','3'}, 
        {'4','5','5','6'},
        {'4','7','8','6'},
        {'9',' ',' ','0'}
    };
}

// prints the board
void Klotski :: printBoard(ostream& out)
{
    out << endl;
    for(int i = 0; i < sizeX; i++)
    {
        out << "   ";
        
        for(int j = 0; j < sizeY; j++)
        {
            out <<(char)Board[i][j]<<' ';
        }
        out << endl;
    }
    out << endl;
}

// Checks all pegs if there is any valid move or not, returns true if there is valid move
bool Klotski :: endGame()
{
    if(Board[3][1] == '2' && Board[3][2] == '2' && Board[4][1] == '2' && Board[4][2] == '2') return false;
    else return true;
}

// Returns the number of pegs reamined
int Klotski :: boardScore() const{return movecount;}

// Gets random move
void Klotski :: randomMove()
{
    vector<char> directionArray {'U','D','R','L'};
    Direction =  directionArray[rand() % 4];
    num = '0' + rand() % 10;
    find();
}

// Finds the index of the selected number
int Klotski :: find()
{
    int flag = 0;
    for (int i = 0; i < sizeX; i++)
    {
        for (int j = 0; j < sizeY; j++)
        {
            if (Board[i][j] == num)
            {
                row = i, column = j, flag = 1;
                j = sizeY, i = sizeX;
            } 
        }
    }
    return flag;
}

// Finds the same num value after the current index if it there is one
int Klotski :: findSame()
{
    int flag = 0;
    
    for (int i = row; i < sizeX; i++)
    {
        for (int j = column + 1; j < sizeY; j++)
        {
            if (Board[i][j] == num) 
            {
                row = i, column = j, flag = 1;
                j = sizeY, i = sizeX;
            } 
        }
        if(flag != 1) column = -1;
    }
    return flag;
}

// Checks the move
int Klotski :: check()
{
    int flag = 0;

    do
    {   
        flag = 0;
        switch (Direction)
        {
            case 'U':/*Up*/
                if(row != 0 && (Board[row - 1][column] == ' ' || Board[row - 1][column] == num)) flag = 1;
                break;

            case 'D':/*Down*/
                if(row != sizeX -1 && (Board[row + 1][column] == ' ' || Board[row + 1][column] == num)) flag = 1;
                break;

            case 'R':/*Right*/
                if(column != sizeY-1 && (Board[row][column + 1] == ' ' || Board[row][column + 1] == num)) flag = 1;
                break;

            case 'L':/*Left*/
                if(column != 0 && (Board[row][column - 1] == ' ' || Board[row][column - 1] == num)) flag = 1;
                break;
            
            default:
                break;
        }
        if(flag == 0) break;
    }while (findSame());
    
    find();
    return flag;
}

/*Moves the pegs according to directions*/
int Klotski :: move()
{
    //cout <<"    "<<num << '-' << Direction<<endl;
    if (Direction == 'U') 
    {
        if(num == '1' || num == '3' || num == '4' || num == '6') Board[row -1][column] = Board[row+1][column], Board[row+1][column] = ' ';
        else if(num == '7' || num == '8' || num == '9' || num == '0') Board[row -1][column] = Board[row][column], Board[row][column] = ' ';
        else if(num == '2') 
        {
            Board[row -1][column] = Board[row + 1][column], Board[row -1][column+1] = Board[row+1][column+1];
            Board[row+1][column] = ' ',Board[row+1][column+1] = ' ';
        }
        else if(num == '5') 
        {
            Board[row -1][column] = Board[row][column], Board[row -1][column+1] = Board[row][column+1];
            Board[row][column] = ' ',Board[row][column+1] = ' ';
        }
    }
    else if (Direction == 'D')
    {
        if(num == '1' || num == '3' || num == '4' || num == '6') Board[row +2][column] = Board[row][column], Board[row][column] = ' ';
        else if(num == '7' || num == '8' || num == '9' || num == '0') Board[row +1][column] = Board[row][column], Board[row][column] = ' ';
        else if(num == '2') 
        {
            Board[row +2][column] = Board[row][column], Board[row+2][column+1] = Board[row][column+1];
            Board[row][column] = ' ',Board[row][column+1] = ' ';
        }
        else if(num == '5') 
        {
            Board[row +1][column] = Board[row][column], Board[row +1][column+1] = Board[row][column+1];
            Board[row][column] = ' ',Board[row][column+1] = ' ';
        }
    } 
    else if (Direction == 'R')
    {
        if(num == '1' || num == '3' || num == '4' || num == '6')
        {
            Board[row][column+1] = Board[row][column], Board[row+1][column+1] = Board[row+1][column];
            Board[row][column] = ' ', Board[row+1][column] = ' ';
        } 
        else if(num == '7' || num == '8' || num == '9' || num == '0') Board[row][column+1] = Board[row][column], Board[row][column] = ' ';
        else if(num == '2') 
        {
            Board[row][column+2] = Board[row][column], Board[row+1][column+2] = Board[row+1][column];
            Board[row][column] = ' ',Board[row+1][column] = ' ';
        }
        else if(num == '5') Board[row][column+2] = Board[row][column], Board[row][column] = ' ';
    } 
    else if (Direction == 'L') 
    {
        if(num == '1' || num == '3' || num == '4' || num == '6')
        {
            Board[row][column-1] = Board[row][column], Board[row+1][column-1] = Board[row+1][column];
            Board[row][column] = ' ', Board[row+1][column] = ' ';
        } 
        else if(num == '7' || num == '8' || num == '9' || num == '0') Board[row][column-1] = Board[row][column], Board[row][column] = ' ';
        else if(num == '2') 
        {
            Board[row][column-1] = Board[row][column+1], Board[row+1][column-1] = Board[row+1][column+1];
            Board[row][column+1] = ' ',Board[row+1][column+1] = ' ';
        }
        else if(num == '5') Board[row][column-1] = Board[row][column+1], Board[row][column+1] = ' ';
    }
    movecount++; 
    return 1;
}

// Divides the input and assigns the values to variables
void Klotski :: assignInput(string input)
{
    num = toupper(input[0]);
    Direction = toupper(input[2]);
    find();
}

// Contols string input ,if it's valid or not
int Klotski :: controlInput(string movement)
{
    int flag = 1;
    if(movement.size() != 3) flag = 0;
    if(toupper(movement[0]) < '0' || toupper(movement[0]) > '9') flag = 0;
    if(movement[1] != '-') flag = 0;
    if(!(toupper(movement[2]) == 'U' || toupper(movement[2]) == 'D'|| toupper(movement[2]) == 'R'|| toupper(movement[2]) == 'L')) flag = 0;
    return flag;
}




/////////////////////////////////////////// EIGHT PUZZLE ///////////////////////////////////////////////////////////////
 
EightPuzzle :: EightPuzzle(){initialize();printBoard(cout);};

// initializes the board
void EightPuzzle :: initialize()
{
    int x , y, xnew, ynew;
    char temp;
    Board = {{'1','2','3'}, {'4','5','6'}, {'7','8',' '}};

    for (int i = 0; i < size*size; ++i)
    {
        x = rand() % size;
        y = rand() % size;
        temp = Board[x][y];

        xnew = rand() % size;
        ynew = rand() % size;

        Board[x][y] = Board[xnew][ynew];

        Board[xnew][ynew] = temp;
    }
    possibile();
}

// prints the board
void EightPuzzle :: printBoard(ostream& out)
{
    out << endl;
    for(int i = 0; i < size; i++)
    {
        out << "   ";
        
        for(int j = 0; j < size; j++)
        {
            out <<(char)Board[i][j]<<' ';
        }
        out << endl;
    }
    out << endl;
}

// Checks if the order of the numbers is solveable or not.
int EightPuzzle :: possibile()
{
    int counter = 0;
    vector<int> vec;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if(Board[i][j] != ' ') vec.push_back(Board[i][j]);
        }
    }

    for (int i = 0; i < size * size -1; i++)
    {
        for (int j = i+1; j < size * size ; j++)
        {
            if((vec[i] != ' ' || vec[j] != ' ' ) && vec[i]>vec[j]) counter++;
        }
    }
    if(counter % 2 == 0) return 1;
    else initialize();
    return 0; 
}  

// Checks all pegs if there is any valid move or not, returns true if there is valid move
bool EightPuzzle :: endGame()
{
    bool flag = false;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if((i + j != 4) && Board[i][j] != '0' + ((i*3) + (j+1))) flag = true;
        } 
    }
    return flag;
}

// Returns the number of pegs reamined
int EightPuzzle :: boardScore() const
{ return movecount;}

// Gets random move
void EightPuzzle :: randomMove()
{
    vector<char> directionArray {'U','D','R','L'};
    Direction =  directionArray[rand() % 4];
    num = '1' + rand() % ((size*size)-1);
}

// Finds the index of the selected number
int EightPuzzle :: find()
{
    int flag = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (Board[i][j] == num) row = i, column = j, flag = 1;
        }
    }
    return flag;
}

// Checks the move
int EightPuzzle :: check()
{
    int flag = 0;
    find();

    switch (Direction)
    {
        case 'U':/*Up*/
            if(row != 0 && Board[row - 1][column] == ' ') flag = 1;
            break;

        case 'D':/*Down*/
            if(row != size -1 && Board[row + 1][column] == ' ') flag = 1;
            break;

        case 'R':/*Right*/
            if(column != size-1 && Board[row][column + 1] == ' ') flag = 1;
            break;

        case 'L':/*Left*/
            if(column != 0 && Board[row][column - 1] == ' ') flag = 1;
            break;
        
        default:
            break;
    }
    return flag;
}

/*Moves the pegs according to directions*/
int EightPuzzle :: move()
{
    if (Direction == 'U') Board[row -1][column] = Board[row][column];
    if (Direction == 'D') Board[row +1][column] = Board[row][column];
    if (Direction == 'R') Board[row][column +1] = Board[row][column];
    if (Direction == 'L') Board[row][column -1] = Board[row][column];
    Board[row][column] = ' ';
    movecount++;
    return 1;
}

// Divides the input and assigns the values to variables
void EightPuzzle :: assignInput(string input)
{
    num = toupper(input[0]);
    Direction = toupper(input[2]);
}

// Contols string input ,if it's valid or not
int EightPuzzle :: controlInput(string movement)
{
    int flag = 1;
    if(movement.size() != 3) flag = 0;
    if(toupper(movement[0]) < '1' || toupper(movement[0]) > '8') flag = 0;
    if(movement[1] != '-') flag = 0;
    if(!(toupper(movement[2]) == 'U' || toupper(movement[2]) == 'D'|| toupper(movement[2]) == 'R'|| toupper(movement[2]) == 'L')) flag = 0;
    return flag;
}




/////////////////////////////////////////// PEGSOLITAIRE ////////////////////////////////////////////////////////////

PegSolitaire :: PegSolitaire(){initialize();printBoard(cout);};

// Returns the number of pegs reamined
int PegSolitaire :: boardScore() const
{
    int counter = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if(Board[i][j] == pegType :: peg) counter++;
        }
    }
    return counter;
}

// Divides the input and assigns the values to variables
void PegSolitaire :: assignInput(string input)
{
    row = input[1] - '0' - 1;
    column = toupper(input[0]) - 'A';
    Direction = toupper(input[3]);
}

// Gets random move
void PegSolitaire :: randomMove()
{
    vector<char> directionArray {'U','D','R','L'};
    Direction =  directionArray[rand() % 4];
    row = rand() % size;
    column = rand() % size;
}

/*Moves the pegs according to directions*/
int PegSolitaire :: move()
{
    int flag = 1;
    switch (Direction)
    {
        case 'U':/*Up*/
            Board[row][column] = pegType :: empty ;
            Board[row - 1][column] = pegType :: empty;
            Board[row - 2][column] = pegType :: peg;
            flag = 0;
            break;
        case 'D':/*Down*/
            Board[row][column] = pegType :: empty;
            Board[row + 1][column] = pegType :: empty;
            Board[row + 2][column] = pegType :: peg;
            flag = 0;
            break;
        case 'R':/*Right*/
            Board[row][column] = pegType :: empty;
            Board[row][column + 1] = pegType :: empty;
            Board[row][column + 2] = pegType :: peg;
            flag = 0;
            break;
        case 'L':/*Left*/
            Board[row][column] = pegType :: empty;
            Board[row][column - 1] = pegType :: empty;
            Board[row][column - 2] = pegType :: peg;
            flag = 0;
            break;
        default:
            break;
    }
    //cout << (char)('A' + column) << row + 1 << '-' << Direction << endl;
    return flag;
}

// Checks all pegs if there is any valid move or not, returns true if there is valid move
bool PegSolitaire :: endGame()
{
    int end = 0; 
    vector<char> directionArray {'U','D','R','L'};
    char direction;
    
    for(int i = 0; i < size; ++i)
    {
        for(int j = 0; j < size; ++j)
        {
            for(int k = 0;k < 4; ++k)
            {
                row = i, column = j, Direction = directionArray[k];
                /*If ther is a possible move Check returns 1 game is not ended, else endGame equals 0*/
                end = check();
                /*If there is any valid move Game is not ended*/
                if(end == 1)
                {
                    end = 1;
                    i = size;
                    j = size;
                    k = 4;
                } 
            }
        }
    }
    /*If no valid move is possible endGame returns 0 by default*/
    return end;
};

// Checks the move
int PegSolitaire :: check()
{
    int flag = 0;

    switch (Direction)
    {
        case 'U':/*Up*/
            if(Board[row][column] == pegType :: peg && (row != 0 && row != 1))
            {
                if(Board[row - 1][column] == pegType :: peg && Board[row - 2][column] == pegType :: empty)
                {
                   flag = 1;
                }
            }
            break;
        case 'D':/*Down*/
            if(Board[row][column] == pegType :: peg && (row != size -1 && row != size -2))
            {
                if(Board[row + 1][column] == pegType :: peg && Board[row + 2][column] == pegType :: empty)
                {
                   flag = 1;
                }
            }
            break;
        case 'R':/*Right*/
            if(Board[row][column] == pegType :: peg && (column != size-1 && column != size -2))
            {
                if(Board[row][column + 1] == pegType :: peg && Board[row][column + 2] == pegType :: empty)
                {
                   flag = 1;
                }
            }
            break;
        case 'L':/*Left*/
            if(Board[row][column] == pegType :: peg && (column != 0 && column != 1))
            {
                if(Board[row][column - 1] == pegType :: peg && Board[row][column - 2] == pegType :: empty)
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

// initializes the board
void PegSolitaire :: initialize()
{
    Board = 
    {
        {pegType :: free,pegType :: free,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: free,pegType :: free},
        {pegType :: free,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: free},
        {pegType :: peg,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: peg},
        {pegType :: peg,pegType :: peg,pegType :: peg,pegType :: empty,pegType :: peg,pegType :: peg,pegType :: peg},
        {pegType :: peg,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: peg},
        {pegType :: free,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: free},
        {pegType :: free,pegType :: free,pegType :: peg,pegType :: peg,pegType :: peg,pegType :: free,pegType :: free},
    };
}

// prints the board
void PegSolitaire :: printBoard(ostream& out)
{
    int rownum = 0;
    char columnletter = 'a';
    out << "    ";
    for(int k = 0; k < size; k++)
        {
           out << char(columnletter) << ' ';
            columnletter++;
        }
        out << endl;
    for(int i = 0; i < size; i++)
    {
        out << rownum + 1<< "   ";
        
        for(int j = 0; j < size; j++)
        {
            out <<(char)Board[i][j]<<' ';
        }
        out << endl;
        rownum++;
    }
    out << endl;
}

// Contols string input ,if it's valid or not
int PegSolitaire :: controlInput(string movement)
{
    int flag = 1;
    if(movement.size() != 4) flag = 0;
    if(toupper(movement[0]) < 'A' || toupper(movement[0]) > 'Z') flag = 0;
    if(movement[1] < '0' || movement[1] > '7') flag = 0;
    if(movement[2] != '-') flag = 0;
    if(!(toupper(movement[3]) == 'U' || toupper(movement[3]) == 'D'|| toupper(movement[3]) == 'R'|| toupper(movement[3]) == 'L')) flag = 0;

    return flag;
}

}