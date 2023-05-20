#include <deque>
using namespace std;
#include "GameBoard.hpp"
#include "Player.hpp"

class PlayGame
{
private:
    /* data */
public:
    GameBoard m_Board;
    deque<Player> nextTurn;
    bool StartGame();
    void initializeGame();
    bool GetFreeCells();
    bool IsThereAWinner(int row, int column, char pieceType) ;

    PlayGame();

};



