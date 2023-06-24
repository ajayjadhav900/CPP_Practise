#include <string>
#include "Account.hpp"
enum class TransactionStatus
{
    SUCCESS,
    FAILURE,
    BLOCKED,
    FULL,
    PARTIAL,
    NONE
};
class Transaction
{
    public:
    Transaction();
    Transaction(int id, TransactionStatus status,std::string date);
    int TransID;
    TransactionStatus TransStatus;
    std::string CreationDate;
    TransType TypeOfTransaction;
    void SaveTheTransaction();
};
class BalanceInquiry : public Transaction
{
    int AccID;
    public:
    BalanceInquiry();
       BalanceInquiry(int id, TransactionStatus status, std::string date, int accID)
        : Transaction(id, status, date), AccID(accID) {}
    void GetAccountID(int accID);
    void SaveTheTransaction();
};

class Deposite : public Transaction
{
    int Amt;
    public:
    Deposite();
    Deposite(int id, TransactionStatus status, std::string date, int amt)
        : Transaction(id, status, date), Amt(amt) {
            TypeOfTransaction = TransType::DEPOSITE;
        }
    void GetAmount(int amt);
    void SaveTheTransaction();
};

class Withdraw : public Transaction
{
    int Amt;
    public:
    Withdraw();
    void GetAmount(int amt);
    void SaveTheTransaction();
};

class Transfer : public Transaction
{
    int DestAccNo;
    int SourceAccNo;
    int Amt;
    public:
    Transfer();
    void GetAmount(int amt);
    void GetDestAccNo(int destAcc);
    void GetSourceAccNo(int sourceAcc);
    void SaveTheTransaction();
};