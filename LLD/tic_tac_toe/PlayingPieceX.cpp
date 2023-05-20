#include <PlayingPiece.hpp>
class PlayingPieceX //: public PlayingPiece
{
public:
    PieceType pieceType;
    PlayingPieceX()
    {
        pieceType = PieceType::O;
    }
};