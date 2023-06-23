#include"Account.hpp"
class User
{
    public:
    int Pin;
    int Card;
    TransType Type;
    User();
    void InsertCard();
    void EnterPin();
    void SelectTransactionType(TransType type);
};
