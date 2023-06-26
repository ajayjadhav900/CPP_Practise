#include "Transaction.hpp"
#include<deque>
class User
{
public:
    int Pin;
    int Card;
    TransType Type;
    std::deque<const Transaction *> UserTrans;
    Account *UserAcc;
    User();
    void InsertCard();
    void EnterPin();
    void SelectTransactionType(TransType type);
    void SaveTransactionStatement(const Transaction * trans);
    void PrintStatement();
};