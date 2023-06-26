#include <iostream>
#include <iomanip>
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
        std::cout << "Select the transaction type: 1: DEPOSITE 2: WITHDRAW 3: DISPLAY BALANCE 4:CHECK DEPOSITE 5: Print Mini Statement\n";
        std::cin >> temp;

        if (temp == 1)
        {
            temp = 0;
            ATMUser.SelectTransactionType(TransType::DEPOSITE);
            std::cout << "Select amount for deposite: ";
            std::cin >> temp;
            Transaction *tr = new CashDeposite(111, temp, TransactionStatus::SUCCESS, "23-Jun-2023", 2222, TransType::DEPOSITE);
            tr->SaveTheTransaction();
            PerformTheTransaction(tr, TransType::DEPOSITE,temp);
        }
        else if (temp == 2)
        {
            temp = 0;
            ATMUser.SelectTransactionType(TransType::WITHDRAW);
            std::cout << "Select amount for withdraw: ";
            std::cin >> temp;
            Transaction *tr = new Withdraw(112, temp, TransactionStatus::SUCCESS, "23-Jun-2023", 2222, TransType::WITHDRAW);
            tr->SaveTheTransaction();
            PerformTheTransaction(tr, TransType::WITHDRAW,temp);
        }
        else if (temp == 3)
        {
            temp = 0;
            ATMUser.SelectTransactionType(TransType::BALANCE);
            CurrAccount->GetAvailableBalance();
            Transaction *tr = new BalanceInquiry(113, CurrAccount->GetAvailableBalance(), TransactionStatus::SUCCESS, "23-Jun-2023", 2222, TransType::WITHDRAW);
            tr->SaveTheTransaction();
            PerformTheTransaction(tr, TransType::BALANCE,temp);
        }
        else if (temp == 4)
        {
            temp = 0;
            ATMUser.SelectTransactionType(TransType::CHECK_DEPOSITE);
            Transaction *tr = new CheckDeposite(114, temp, TransactionStatus::SUCCESS, "23-Jun-2023", 2222, TransType::CHECK_DEPOSITE);
            tr->SaveTheTransaction();
            PerformTheTransaction(tr, TransType::CHECK_DEPOSITE,temp);
        }
        else if (temp == 5)
        {
            temp = 0;
            ATMUser.SelectTransactionType(TransType::MINI_STATEMENT);
            ATMUser.PrintStatement();
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

void ATM:: PerformTheTransaction(const Transaction *tr, TransType type,int temp)
{
    CurrAccount->UpdateBalance(temp, type);
    ATMTrasn.push_back(tr);
    std::cout << "Do u need reciept(Y/N):";
    ATMUser.SaveTransactionStatement(tr);
    AllUserList.emplace_front(ATMUser);
}

void ATM::PrintAllATMTransaction()
{
    // Print the header
    std::cout << std::setw(10) << "PIN";
    std::cout << std::setw(10) << "Card";
    std::cout << std::setw(20) << "Transaction Type";
    std::cout << std::setw(20) << "Account Number";
    std::cout << std::endl;

    // Print each user's transaction information
    for (const auto& user : AllUserList)
    {
        std::cout << std::setw(10) << user.Pin;
        std::cout << std::setw(10) << user.Card;
        std::cout << std::setw(20) << static_cast<int>(user.Type);
        std::cout << std::setw(20) << user.UserAcc->AccNo;
    }
}