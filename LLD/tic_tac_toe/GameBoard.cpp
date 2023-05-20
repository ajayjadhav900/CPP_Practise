#include "GameBoard.hpp"

void GameBoard::Initilize()
{
    // cout << "Initilize the board. \n";
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            board[i][j] = ' ';
        }
    }
}
void GameBoard::PrintBoard()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (board[i][j])
            {
                cout << board[i][j] << "   ";
            }
            else
            {
                cout << "    ";
            }
            cout << (" | ");
        }
        cout << endl;
    }
}

void GameBoard::GetSize()
{
    int tempSize;
    cout << "Enter the N X N level size for tic tac toe: ";
    cin >> tempSize;
    size = tempSize;
}

bool GameBoard::AddPiece(int r, int c, char pieceType)
{
    if (board[r][c] != ' ')
    {
        return false;
    }
    board[r][c] = pieceType;
    return true;
}

GameBoard::GameBoard()
{
    GetSize();

    // Declare memory block of size M
    board = new char *[size];
    for (int i = 0; i < size; i++)
    {
        // Declare a memory block
        // of size n
        board[i] = new char[size];
    }

    Initilize();
}
