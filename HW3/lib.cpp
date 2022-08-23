#include "lib.h"

int setGame()
{
    int in = 1, out = 0;
    string input;
    PegSolitaire start;

    cout << "   Welcome to solo test    \n";

    while(out == 0)
    {
        in = 1, out = 0;

        while(in == 1)
        {
            cout <<"\tHit Enter to Automaticly Select a Default Board \n";
            cout <<"\tLoad or Save a Default Board\n";
            cout <<"\tPlease Enter Board Type (1 to 6):";
            getline(cin,input);
            if(input == "")
            {
                PegSolitaire start = PegSolitaire();
                in = 0;
            } 
            else if(controlFilename(input) == 1)
            {
                start.File(input);
            }
            else if(input[0] - '0' < 0 ||  (int)input[0] - '0'> 6) 
            {
                cout << "\n\tInvalid Input, Try Again\n\n";
            }
            else
            {
                PegSolitaire start = PegSolitaire((int)input[0]);
                in = 0;
            }
        }
        in = 1;
        start.printBoard();

        while (in == 1)
        {
            cout << "\tHit Enter to Play an Automatic Move \n";
            cout << "\tEnter a Valid Move \n";
            cout << "\tEnter 1 to Play All Game\n";
            cout << "\tEnter 2 to Exit to Menu\n";
            cout << "\tEnter 3 to Exit Game\n\n";


            getline(cin,input);
            if(input == "")
            {
                start.play();
                start.printBoard();
                if(start.checkAll() == 0)
                {
                    cout << "Game is Ended\n";
                    in = 0;
                }
            } 
            else if(input[0] - '0' == 1) 
            {
                /*ask board*/
                start.playAll();
            }
            else if(input[0] - '0' == 2) 
            {
                in = 0;
                out = 1;
            }
            else if(input[0] - '0' == 3) 
            {
                return 0;
            }
            else if(controlInput(input) == 1)
            {
                start.play(input);
                start.printBoard();
                if(start.checkAll() == 0)
                {
                    cout << "Game is Ended\n";
                    in = 0;
                }
                in = 0;
            }
        }
    }

    return 0;
}


/*Controls user input for each move.*/
int controlInput(string movement)
{
    int flag = 1;
    if(movement.size() != 4) flag = 0;
    if(toupper(movement[0]) < 'A' || toupper(movement[0]) > 'Z') flag = 0;
    if(movement[1] < '0' || movement[1] > '9') flag = 0;
    if(movement[2] != '-') flag = 0;
    if(!(toupper(movement[3]) == 'U' || toupper(movement[3]) == 'D'|| toupper(movement[3]) == 'R'|| toupper(movement[3]) == 'L')) flag = 0;
    if(flag == 0)/*If input is not movement*/
    {
        cout << "  Invalid Input, Try Again\n";/*Completely wrong input*/
    } 
    return flag;
}


int controlFilename(string filename)
{
    int flag = 0;
    char input;
    string load = "load", save = "save";
    
    if(filename.find(load) != string::npos)/*Checks load statement*/
    {
        /*skips load part in the string*/
       
     flag = 1;   
    }  
    else if(filename.find(save) != string::npos)/*Checks save statement*/
    {
        flag = 1;
        /*Saves current board to txt file*/
        /*skips the save part*/
    }    
    else flag = 0;
    return flag; /*returns 1 if the input is save and load command, else returns 0.*/
}