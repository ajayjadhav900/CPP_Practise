#include "PlayingPiece.hpp"
#include <iostream>
using namespace std;

void PlayingPiece:: PrintPieceTypes()
{
    for (int itr = PieceTypes::X; itr != PieceTypes::O; itr++)
    {
        char foo = static_cast<char>(itr);
        cout << foo<<" ";
    }
    cout<<endl;
}