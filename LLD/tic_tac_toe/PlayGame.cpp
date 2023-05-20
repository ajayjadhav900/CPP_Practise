#include <iostream>
#include "PlayGame.hpp"

PlayGame::PlayGame()
{
}
bool PlayGame::StartGame()
{
    // cout<<"In function start game\n";
    m_Board.PrintBoard();
    bool isWinner = true;
    while (isWinner)
    {
        Player player = nextTurn.front();
        nextTurn.pop_front();
        if (!GetFreeCells())
        {
            cout << "\nAll Cells are completed.";
            isWinner = false;
            continue;
        }
        int row = 0, col = 0;
        cout << "\nEnter the position for Player: " << player.GetName();
        cin >> row >> col;
        if (!m_Board.AddPiece(row, col, player.GetPieceType()))
        {
            cout << "\nEnter valid position, Try Again!!!\n";
            nextTurn.push_front(player);
            continue;
        }
        m_Board.PrintBoard();
        if (IsThereAWinner(row, col, player.GetPieceType()))
        {
            cout << "Player " << player.GetName() << " Wins the game!!!\n";
            return true;
        }
        nextTurn.push_back(player);
    }
    return isWinner;
}

void PlayGame::initializeGame()
{
    // m_Board.PrintBoard();

    // cout << "\nPlayers initilized\n";
    /*     Player player1;
        player1.EnterNameOfthePlayer();
        player1.EnterPieceType(); */
    Player player1("Player1", 'X');
    Player player2("Player2", 'O');
    nextTurn.push_back(player1);
    nextTurn.push_back(player2);
}

bool PlayGame::GetFreeCells()
{
    for (int i = 0; i < m_Board.size; i++)
    {
        for (int j = 0; j < m_Board.size; j++)
        {
            if (m_Board.board[i][j] == ' ')
            {
                return true;
            }
        }
    }
    return false;
}

bool PlayGame::IsThereAWinner(int row, int column, char pieceType)
{

    bool rowMatch = true;
    bool columnMatch = true;
    bool diagonalMatch = true;
    bool antiDiagonalMatch = true;

    // need to check in row
    for (int i = 0; i < m_Board.size; i++)
    {

        if (m_Board.board[row][i] == ' ' || m_Board.board[row][i] != pieceType)
        {
            rowMatch = false;
        }
    }

    // need to check in column
    for (int i = 0; i < m_Board.size; i++)
    {

        if (m_Board.board[i][column] == ' ' || m_Board.board[i][column] != pieceType)
        {
            columnMatch = false;
        }
    }

    // need to check diagonals
    for (int i = 0, j = 0; i < m_Board.size; i++, j++)
    {
        if (m_Board.board[i][j] == ' ' || m_Board.board[i][j] != pieceType)
        {
            diagonalMatch = false;
        }
    }

    // need to check anti-diagonals
    for (int i = 0, j = m_Board.size - 1; i < m_Board.size; i++, j--)
    {
        if (m_Board.board[i][j] == ' ' || m_Board.board[i][j] != pieceType)
        {
            antiDiagonalMatch = false;
        }
    }

    return rowMatch || columnMatch || diagonalMatch || antiDiagonalMatch;
}
