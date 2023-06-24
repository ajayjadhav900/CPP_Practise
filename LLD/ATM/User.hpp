<<<<<<< HEAD
=======
#include"Account.hpp"
>>>>>>> b74dd271694420b45c105c3c44b6e670bb9c520f
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
