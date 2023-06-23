#include "User.hpp"
#include<iostream>

User::User(){}

void User::InsertCard()
{
    std::cout<<"Insert Card means enter card details:";
    std::cin>>Card;
}

void User::EnterPin()
{
    std::cout<<"Enter the pin no: ";
    std::cin>>Pin;
}

void User::SelectTransactionType(TransType type)
{
    Type = type;
}
