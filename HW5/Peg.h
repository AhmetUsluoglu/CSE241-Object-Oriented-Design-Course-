#include "BoardGame.h"

using namespace std;
namespace game{


class PegSolitaire : public BoardGame2D
{
    private:
        int row , column , size = 7;
        char Direction;
    public:
        enum class pegType : char {empty = '.', peg = 'P', free = ' '};
        vector<vector<pegType>> Board;
        
        PegSolitaire(/* args */);

        int boardScore() const;  
        
        bool endGame();

        int check();
        int move();

        int controlInput(string movement);
        void assignInput(string input);

        void randomMove();

        void printBoard(ostream& out);
        void initialize();
};
    
}