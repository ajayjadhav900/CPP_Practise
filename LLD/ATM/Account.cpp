#include "Account.hpp"
#include <iostream>

Account::Account()
{
}

Account::Account(std::string accno, int card) : AccNo(accno), card(card)
{
    balance = 0;
}

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

void Account::DisplayBalance()
{
    std::cout << "Balance in the account is " << balance << std::endl;
}
