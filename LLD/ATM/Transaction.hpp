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
    int TransID;
    int AccID;
    int Amount;
    TransactionStatus TransStatus;
    std::string CreationDate;
    TransType TypeOfTransaction;
    Transaction(int id, int amt, TransactionStatus status, std::string date, int accID, TransType type)
        : TransID(id), AccID(accID), Amount(amt), TransStatus(status), CreationDate(date), TypeOfTransaction(type) {}
    virtual void SaveTheTransaction() = 0;
};
class BalanceInquiry : public Transaction
{
public:
    BalanceInquiry(int id, int amt, TransactionStatus status, std::string date, int accID, TransType type)
        : Transaction(id, amt, status, date, accID, type) {}
    void GetAccountID(int accID);
    void SaveTheTransaction();
};

class Deposite : public Transaction
{

public:
    Deposite(int id, int amt, TransactionStatus status, std::string date, int accID, TransType type)
        : Transaction(id, amt, status, date, accID, type) {}
    void GetAmount(int amt);
    virtual void SaveTheTransaction() = 0;
};
class CashDeposite : public Deposite
{
    int CashLimit;

public:
    CashDeposite(int id, int amt, TransactionStatus status, std::string date, int accID, TransType type)
        : Deposite(id, amt, status, date, accID, type) {}
    void SaveTheTransaction();
};
class CheckDeposite : public Deposite
{
    int CheckNo;

public:
    CheckDeposite(int id, int amt, TransactionStatus status, std::string date, int accID, TransType type)
        : Deposite(id, amt, status, date, accID, type) {}
    void SaveTheTransaction();
};
class Withdraw : public Transaction
{
public:
    Withdraw(int id, int amt, TransactionStatus status, std::string date, int accID, TransType type)
        : Transaction(id, amt, status, date, accID, type) {}
    void GetAmount(int amt);
    void SaveTheTransaction();
};

class Transfer : public Transaction
{
    int DestAccNo;
    int SourceAccNo;

public:
    Transfer(int id, int amt, TransactionStatus status, std::string date, int accID, TransType type)
        : Transaction(id, amt, status, date, accID, type) {}
    void GetAmount(int amt);
    void GetDestAccNo(int destAcc);
    void GetSourceAccNo(int sourceAcc);
    void SaveTheTransaction();
};