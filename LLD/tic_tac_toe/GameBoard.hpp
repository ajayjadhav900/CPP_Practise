#include<iostream>
using namespace std;

//#include<PlayingPiece.hpp>
#define  SIZE  4;

class GameBoard
{    //PlayingPiece Board[3][3];
    public:
    char **board;
    int size;
    void Initilize();
    bool AddPiece(int , int, char);
    void PrintBoard();
    void GetSize();
    GameBoard();

};
