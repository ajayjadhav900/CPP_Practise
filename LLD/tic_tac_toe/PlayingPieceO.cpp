#include "PlayingPiece.hpp"
class PlayingPieceO //: public PlayingPiece
{
public:
    PieceTypes pieceType;
    PlayingPieceO()
    {
        pieceType = PieceTypes::O;
    }
};