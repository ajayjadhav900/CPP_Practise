#include <string>
<<<<<<< HEAD
/*This is account class*/
=======
>>>>>>> a3d2e1b (ATM: CheckDEPOSITE and SAVINGACCOUNT are inherited for Account)
enum class TransType
{
    WITHDRAW,
    DEPOSITE,
    TRANSFER,
    BALANCE,
    CHECK_DEPOSITE
};
class Account
{
public:
    std::string AccNo;
    int balance;
    int card;
    Account(std::string accno, int card, int bal) : AccNo(accno), card(card), balance(bal) {}
    virtual int GetAvailableBalance() = 0;
    void UpdateBalance(int amt, TransType type);
};

class SavingAccount : public Account
{
public:
    int withdrawLimit;
    SavingAccount(std::string accno, int card, int bal) : Account(accno, card, bal)
    {
        withdrawLimit = 20000;
    }
    int GetAvailableBalance();
};

class CheckingAccount : public Account
{
public:
    CheckingAccount(std::string accno, int card, int bal) : Account(accno, card, bal)
    {
    }
    int GetAvailableBalance();
};