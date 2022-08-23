#include "BoardGame.h"

using namespace std;
namespace game{


class EightPuzzle : public BoardGame2D
{
    private:
        int row , column , size = 3, movecount = 0;
        char Direction, num;
    public:
        vector<vector<char>> Board;
        
        EightPuzzle(/* args */);

        int boardScore() const;  
        int possibile();  
        
        bool endGame();

        int check();
        int move();
        int find();

        int controlInput(string movement);
        void assignInput(string input);

        void randomMove();

        void printBoard(ostream& out);
        void initialize();
};

}