#include <string>
<<<<<<< HEAD
#include "Account.hpp"
=======

>>>>>>> b74dd271694420b45c105c3c44b6e670bb9c520f
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
<<<<<<< HEAD
    TransType TypeOfTransaction;
=======
>>>>>>> b74dd271694420b45c105c3c44b6e670bb9c520f
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
<<<<<<< HEAD
    void SaveTheTransaction();
=======
>>>>>>> b74dd271694420b45c105c3c44b6e670bb9c520f
};

class Deposite : public Transaction
{
    int Amt;
    public:
    Deposite();
    Deposite(int id, TransactionStatus status, std::string date, int amt)
<<<<<<< HEAD
        : Transaction(id, status, date), Amt(amt) {
            TypeOfTransaction = TransType::DEPOSITE;
        }
    void GetAmount(int amt);
    void SaveTheTransaction();
=======
        : Transaction(id, status, date), Amt(amt) {}
    void GetAmount(int amt);
>>>>>>> b74dd271694420b45c105c3c44b6e670bb9c520f
};

class Withdraw : public Transaction
{
    int Amt;
    public:
    Withdraw();
    void GetAmount(int amt);
<<<<<<< HEAD
    void SaveTheTransaction();
=======
>>>>>>> b74dd271694420b45c105c3c44b6e670bb9c520f
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
<<<<<<< HEAD
    void SaveTheTransaction();
=======
>>>>>>> b74dd271694420b45c105c3c44b6e670bb9c520f
};