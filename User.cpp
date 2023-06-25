#include "User.hpp"
#include<iostream>

User::User(){
}

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

void User::SaveTransactionStatement(Transaction *trans)
{
    UserTrans.emplace_front(trans);
}

#include <iomanip>

void User::PrintStatement()
{
    int count = 0;
    std::cout << std::left;
    std::cout << std::setw(12) << "TransID"
              << std::setw(12) << "AccID"
              << std::setw(12) << "Amount"
              << std::setw(12) << "Status"
              << std::setw(15) << "Creation Date"
              << std::setw(15) << "Transaction Type" << std::endl;
    std::cout << std::setfill('-') << std::setw(75) << "-" << std::setfill(' ') << std::endl;
    
    for (auto it = UserTrans.rbegin(); it != UserTrans.rend() && count < 5; ++it)
    {
        std::cout << std::setw(12) << (*it)->TransID
                  << std::setw(12) << (*it)->AccID
                  << std::setw(12) << (*it)->Amount
                  << std::setw(12) << static_cast<int>((*it)->TransStatus)
                  << std::setw(15) << (*it)->CreationDate
                  << std::setw(15) << static_cast<int>((*it)->TypeOfTransaction) << std::endl;
        count++;
    }
}

