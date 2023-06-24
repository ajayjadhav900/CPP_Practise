#include "Transaction.hpp"
<<<<<<< HEAD
#include <iostream>
=======

>>>>>>> b74dd271694420b45c105c3c44b6e670bb9c520f
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

<<<<<<< HEAD
void BalanceInquiry::SaveTheTransaction()
{
}

=======
>>>>>>> b74dd271694420b45c105c3c44b6e670bb9c520f
Deposite::Deposite()
{
    Amt = 0;
}

void Deposite::GetAmount(int amt)
{
    Amt = amt;
}

<<<<<<< HEAD
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

=======
>>>>>>> b74dd271694420b45c105c3c44b6e670bb9c520f
Withdraw::Withdraw()
{
    Amt = 0;
}

void Withdraw::GetAmount(int amt)
{
    Amt = amt;
}

<<<<<<< HEAD
void Withdraw::SaveTheTransaction()
{
}

=======
>>>>>>> b74dd271694420b45c105c3c44b6e670bb9c520f
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
<<<<<<< HEAD

void Transfer::SaveTheTransaction()
{
}
=======
>>>>>>> b74dd271694420b45c105c3c44b6e670bb9c520f
