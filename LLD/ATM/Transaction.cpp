#include "Transaction.hpp"
#include <iostream>
Transaction::Transaction()
{
}

Transaction::Transaction(int id, TransactionStatus status, std::string date)
    : TransID(id), TransStatus(status), CreationDate(date)
{
}

void Transaction::SaveTheTransaction()
{
}

BalanceInquiry::BalanceInquiry()
{
    AccID = 0;
}

void BalanceInquiry::GetAccountID(int accID)
{
    AccID = accID;
}

void BalanceInquiry::SaveTheTransaction()
{
}

Deposite::Deposite()
{
    Amt = 0;
}

void Deposite::GetAmount(int amt)
{
    Amt = amt;
}

void Deposite::SaveTheTransaction()
{
    std::cout << "\n------------------------------\n";
    std::cout << "\n-------RECIEPT----------\n";
    std::cout << "TranID: " << TransID << std::endl;
    std::cout << "Transaction Status: " << static_cast<int>(TransStatus) << std::endl;
    std::cout << "Date: " << CreationDate.c_str() << std::endl;
    std::cout << "Transaction Type: " << static_cast<int>(TypeOfTransaction) << std::endl;
    std::cout << "Amount: " << Amt << std::endl;
    std::cout << "\n------------------------------\n";
}

Withdraw::Withdraw()
{
    Amt = 0;
}

void Withdraw::GetAmount(int amt)
{
    Amt = amt;
}

void Withdraw::SaveTheTransaction()
{
}

Transfer::Transfer()
{
}

void Transfer::GetAmount(int amt)
{
    Amt = amt;
}

void Transfer::GetDestAccNo(int destAcc)
{
    DestAccNo = destAcc;
}

void Transfer::GetSourceAccNo(int sourceAcc)
{
    SourceAccNo = sourceAcc;
}

void Transfer::SaveTheTransaction()
{
}
