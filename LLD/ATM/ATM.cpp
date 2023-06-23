#include <iostream>
#include "ATM.hpp"
#include <algorithm>

ATM::ATM()
{
    CurrAccount = nullptr;
}

bool ATM::CardPinValidation(int crd, int pin)
{
    auto it = std::find_if(CardVec.begin(), CardVec.end(), [crd, pin](const card &c)
                           { return c.CardNo == crd && c.CardPin == pin; });

    return (it != CardVec.end());
}

void ATM::StartTransaction(int crd, int pin)
{
    while (1)
    {
        auto it = std::find_if(AccountVec.begin(), AccountVec.end(), [crd](const Account &acc)
                               { return acc.card == crd; });

        if (it != AccountVec.end())
        {
            CurrAccount = &(*it);
        }
        else
        {
            std::cout << "Account not found for the given card number!\n";
            return;
        }
        int temp;
        std::cout << "Select the transaction type: 1: DEPOSITE 2: WITHDRAW 3: DISPLAY BALANCE \n";
        std::cin >> temp;
        //temp=1;
        if (temp == 1)
        {
            temp = 0;
            ATMUser.SelectTransactionType(TransType::DEPOSITE);
            std::cout << "Select amount for deposite: ";
            std::cin >> temp;
            CurrAccount->UpdateBalance(temp, TransType::DEPOSITE);
            CurrAccount->DisplayBalance();
        }
        else if (temp == 2)
        {
            temp = 0;
            ATMUser.SelectTransactionType(TransType::WITHDRAW);
            std::cout << "Select amount for withdraw: ";
            std::cin >> temp;
            CurrAccount->UpdateBalance(temp, TransType::WITHDRAW);
            CurrAccount->DisplayBalance();
        }
        else if (temp == 3)
        {
            CurrAccount->DisplayBalance();
        }
        else
        {
            std::cout << "Enter the valid type!!!";
            continue;
        }
        break;
    }
}

void ATM::GenerateData()
{
    card c1(12345, 1234);
    card c2(67890, 6789);
    CardVec.push_back(c1);
    CardVec.push_back(c2);
    Account Ac1("AB12345", 12345);
    Account Ac2("AB67890", 67890);
    AccountVec.push_back(Ac1);
    AccountVec.push_back(Ac2);
}
