#include "Transaction.hpp"
#include <iostream>

void BalanceInquiry::GetAccountID(int accID)
{
    AccID = accID;
}

void BalanceInquiry::SaveTheTransaction()
{
    std::cout << "\n------------------------------\n";
    std::cout << "\n-------BalanceInquiry RECIEPT----------\n";
    std::cout << "TranID: " << TransID << std::endl;
    std::cout << "Transaction Status: " << static_cast<int>(TransStatus) << std::endl;
    std::cout << "Date: " << CreationDate.c_str() << std::endl;
    std::cout << "Transaction Type: " << static_cast<int>(TypeOfTransaction) << std::endl;
    std::cout << "Amount: " << Amount << std::endl;
    std::cout << "\n------------------------------\n";
}

void Deposite::GetAmount(int amt)
{
}

void Deposite::SaveTheTransaction()
{
    std::cout << "\n------------------------------\n";
    std::cout << "\n-------DEPOSITE RECIEPT----------\n";
    std::cout << "TranID: " << TransID << std::endl;
    std::cout << "Transaction Status: " << static_cast<int>(TransStatus) << std::endl;
    std::cout << "Date: " << CreationDate.c_str() << std::endl;
    std::cout << "Transaction Type: " << static_cast<int>(TypeOfTransaction) << std::endl;
    std::cout << "Amount: " << Amount << std::endl;
    std::cout << "\n------------------------------\n";
}

void Withdraw::SaveTheTransaction()
{
    std::cout << "\n------------------------------\n";
    std::cout << "\n-------Withdraw RECIEPT----------\n";
    std::cout << "TranID: " << TransID << std::endl;
    std::cout << "Transaction Status: " << static_cast<int>(TransStatus) << std::endl;
    std::cout << "Date: " << CreationDate.c_str() << std::endl;
    std::cout << "Transaction Type: " << static_cast<int>(TypeOfTransaction) << std::endl;
    std::cout << "Amount: " << Amount << std::endl;
    std::cout << "\n------------------------------\n";
}

void Transfer::GetAmount(int amt)
{
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

void CheckDeposite::GetAmount(int amt)
{
}

void CheckDeposite::SaveTheTransaction()
{
    std::cout << "\n------------------------------\n";
    std::cout << "\n-------CHECK DEPOSITE RECIEPT----------\n";
    std::cout << "TranID: " << TransID << std::endl;
    std::cout << "Transaction Status: " << static_cast<int>(TransStatus) << std::endl;
    std::cout << "Date: " << CreationDate.c_str() << std::endl;
    std::cout << "Transaction Type: " << static_cast<int>(TypeOfTransaction) << std::endl;
    std::cout << "Amount: " << Amount << std::endl;
    std::cout << "\n------------------------------\n";
}
