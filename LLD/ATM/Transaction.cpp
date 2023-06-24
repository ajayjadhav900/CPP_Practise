#include "Transaction.hpp"

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

Deposite::Deposite()
{
    Amt = 0;
}

void Deposite::GetAmount(int amt)
{
    Amt = amt;
}

Withdraw::Withdraw()
{
    Amt = 0;
}

void Withdraw::GetAmount(int amt)
{
    Amt = amt;
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
