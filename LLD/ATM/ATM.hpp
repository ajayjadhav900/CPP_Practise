#include <vector>
#include "card.hpp"
#include "User.hpp"
#include <list>
class ATM
{
public:
    std::vector<card> CardVec;
    std::vector<Account *> AccountVec;
    std::vector<const Transaction *> ATMTrasn;
    Transaction *CurrTrans;
    User ATMUser;
    std::list<User> AllUserList;
    Account *CurrAccount;
    ATM();
    bool CardPinValidation(int crd, int pin);
    void StartTransaction(int crd, int pin);
    void GenerateData();
    void PerformTheTransaction(const Transaction *tr, TransType type, int temp);
    void PrintAllATMTransaction();

};
