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
        auto it = std::find_if(AccountVec.begin(), AccountVec.end(), [crd](const Account *acc)
                               { return acc->card == crd; });

        if (it != AccountVec.end())
        {
            CurrAccount = *it;
        }
        else
        {
            std::cout << "Account not found for the given card number!\n";
            return;
        }
        int temp;
        std::cout << "Select the transaction type: 1: DEPOSITE 2: WITHDRAW 3: DISPLAY BALANCE 4:CHECK DEPOSITE\n";
        std::cin >> temp;

        if (temp == 1)
        {
            temp = 0;
            ATMUser.SelectTransactionType(TransType::DEPOSITE);
            std::cout << "Select amount for deposite: ";
            std::cin >> temp;
            Transaction *tr = new Deposite(111, temp, TransactionStatus::SUCCESS, "23-Jun-2023", 2222, TransType::DEPOSITE);
            CurrAccount->UpdateBalance(temp, TransType::DEPOSITE);
            ATMTrasn.push_back(tr);
            std::cout << "Do u need reciept(Y/N):";
            tr->SaveTheTransaction();
        }
        else if (temp == 2)
        {
            temp = 0;
            ATMUser.SelectTransactionType(TransType::WITHDRAW);
            std::cout << "Select amount for withdraw: ";
            std::cin >> temp;
            Transaction *tr = new Withdraw(112, temp, TransactionStatus::SUCCESS, "23-Jun-2023", 2222, TransType::WITHDRAW);
            CurrAccount->UpdateBalance(temp, TransType::WITHDRAW);
            ATMTrasn.push_back(tr);
            std::cout << "Do u need reciept(Y/N):";
            tr->SaveTheTransaction();
        }
        else if (temp == 3)
        {
            temp = 0;
            ATMUser.SelectTransactionType(TransType::BALANCE);
            Transaction *tr = new BalanceInquiry(113, temp, TransactionStatus::SUCCESS, "23-Jun-2023", 2222, TransType::WITHDRAW);
            CurrAccount->UpdateBalance(temp, TransType::WITHDRAW);
            ATMTrasn.push_back(tr);
            std::cout << "Do u need reciept(Y/N):";
            tr->SaveTheTransaction();
        }
        else if (temp == 4)
        {
            temp = 0;
            ATMUser.SelectTransactionType(TransType::CHECK_DEPOSITE);
            Transaction *tr = new CheckDeposite(114, temp, TransactionStatus::SUCCESS, "23-Jun-2023", 2222, TransType::WITHDRAW);
            CurrAccount->UpdateBalance(temp, TransType::WITHDRAW);
            ATMTrasn.push_back(tr);
            std::cout << "Do u need reciept(Y/N):";
            tr->SaveTheTransaction();
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
    Account *Ac1 = new SavingAccount("AB12345", 12345, 0);
    Account *Ac2 = new SavingAccount("AB12345", 12345, 1000);
    AccountVec.push_back(Ac1);
    AccountVec.push_back(Ac2);
}
