#include<string>
using namespace std;
//#include"PlayingPiece.hpp"
class Player
{
        string m_name;
        char m_pieceType;

    public:
    //PlayingPiece PlayWith;
     Player(string name, char cross);
     Player();
     const string & GetName();
     const char & GetPieceType();
     void EnterPieceType();
     void EnterNameOfthePlayer();
     bool ValidateInput(char type);


};

