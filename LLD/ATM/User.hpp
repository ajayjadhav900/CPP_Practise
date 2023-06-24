#include "Transaction.hpp"
class User
{
    public:
    int Pin;
    int Card;
    TransType Type;
    Transaction *UserTrans;

    User();
    void InsertCard();
    void EnterPin();
    void SelectTransactionType(TransType type);
};
