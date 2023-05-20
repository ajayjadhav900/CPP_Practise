#include "Player.hpp"
#include"PlayingPiece.hpp"
#include<string>
#include<iostream>
using namespace std;

Player::Player(std::string name, char pieceType)
{
    m_name = name;
    m_pieceType = pieceType;
    
}

Player::Player()
{
}

const string &Player::GetName()
{
    return m_name;
}

const char &Player::GetPieceType()
{
    return m_pieceType;
}

void Player::EnterPieceType()
{
    char inputType;
    while(true)
    {
    cout<<"Enter the piece type for the player: ";
    PlayingPiece PlayWith;
    PlayWith.PrintPieceTypes();
    cin>>inputType;
    if(!ValidateInput(inputType))
    {
        cout<<"Enter the valid piece type!!!\n";
        continue;
    }
    break;
    }
    m_pieceType=inputType;
}

void Player::EnterNameOfthePlayer()
{
    string name;
    cout<<"Enter Name :";
    cin>>name;
    name =m_name;
}

bool Player::ValidateInput(char type)
{
    if(type == PieceTypes::O)
    {
        return true;
    }
    else if(type == PieceTypes::X)
    {
        return true;
    }
    return false;
}
