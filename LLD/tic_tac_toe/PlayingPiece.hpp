
enum PieceTypes
{
    X,
    O
};

class PlayingPiece
{

public:

    PieceTypes m_pieceType;
     PlayingPiece(PieceTypes p)
    {
        this->m_pieceType = p;
    } 
    PlayingPiece()
    {
        
    }
        void PrintPieceTypes();
}; 