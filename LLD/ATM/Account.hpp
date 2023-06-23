#include<string>
enum class TransType
{
    WITHDRAW,
    DEPOSITE
};
class Account
{
public:
    std::string AccNo;
    int balance;
    int card;
    Account();
    Account(std::string accno,int card);
    void UpdateBalance(int amt, TransType type);
    void DisplayBalance();
};