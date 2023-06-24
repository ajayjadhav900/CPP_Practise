#include <vector>
#include "card.hpp"
#include "User.hpp"
class ATM
{
public:
    std::vector<card> CardVec;
    std::vector<Account> AccountVec;
    std::vector<Transaction> ATMTrasn;
    Transaction *CurrTrans;
    User ATMUser;
    Account *CurrAccount;
    ATM();
    bool CardPinValidation(int crd, int pin);
    void StartTransaction(int crd, int pin);
    void GenerateData();
};
