#ifndef Base
#define Base

#include <iostream>
#include <vector>
#include <time.h>
#include <fstream>
#include <string>
#include <sstream>


using namespace std;
namespace game{

class BoardGame2D
{
    public:

        int row , column ;
        char Direction, num;

        BoardGame2D(/* args */);

        void virtual playUser() final;
        void virtual playUser(string input);

        void virtual playAutoAll() final;
        void playAuto();
        
        friend ostream & operator<<(ostream& out, BoardGame2D & board);
        
        virtual bool endGame() = 0;
        virtual void printBoard(ostream& out) = 0;
        virtual void initialize() = 0;
        virtual int boardScore() const = 0;

        virtual void randomMove() = 0;
        virtual int check() = 0;
        virtual int move() = 0;
        
        static void playVector(vector<BoardGame2D*>);
        
        virtual int controlInput(string input) = 0;
        virtual void assignInput(string input) = 0;


};

}
#endif // !Base