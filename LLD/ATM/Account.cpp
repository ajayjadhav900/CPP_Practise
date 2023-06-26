#include "Account.hpp"
#include <iostream>

void Account::UpdateBalance(int amt, TransType type)
{
    if (type == TransType::DEPOSITE)
    {
        balance = balance + amt;
    }
    else if (type == TransType::WITHDRAW)
    {
        if (amt > balance)
        {
            std::cout << "Insufficient balance!!!\n";
        }
        else
        {
            balance = balance - amt;
        }
    }
}


int SavingAccount::GetAvailableBalance()
{
    return balance;
}

int CheckingAccount::GetAvailableBalance()
{
    return balance;
}