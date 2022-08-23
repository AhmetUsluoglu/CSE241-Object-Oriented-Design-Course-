#include "BoardGame.h"

using namespace std;
namespace game{


class Klotski : public BoardGame2D
{
    private:
        int row , column , sizeX = 5, sizeY = 4, movecount = 0;
        char Direction, num;
    public:
        vector<vector<char>> Board;
        
        Klotski(/* args */);

        int boardScore() const;  
        
        bool endGame();

        int check();
        int move();
        int find();
        int findSame();

        int controlInput(string movement);
        void assignInput(string input);

        void randomMove();

        void printBoard(ostream& out);
        void initialize();
};












}