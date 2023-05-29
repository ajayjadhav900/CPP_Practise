#include <iostream>
#include "Observer.h"
using namespace std;

void customerPrime::update(string msg_from_amazon)
{
    cout << name << " msg :" << msg_from_amazon;
}

void Publisher::add_customers(const customerPrime &p)
{
    // adding cust on perticular cons
    PrimeList.push_back(p);
}

void Publisher::remover_customers()
{
    // delete from the list
}

void Publisher::notify_customers()
{
    for (auto itr : PrimeList)
    {
        itr.update("Amazon sell is on the new year.\n");
    }
}

void Publisher::business_logic()
{
    if (Imp_update == true)
    {
        notify_customers();
    }
}

int main()
{
    cout << "Observer Pattern" << endl;
    customerPrime Pc1("Ajay"), Pc2("Vijay");
    Publisher pub;
    pub.Imp_update = true;
    pub.add_customers(Pc1);
    pub.add_customers(Pc2);
    pub.business_logic();
    return 0;
}


class InterestCalculator {
public:
    virtual double calculateInterest(double balance) const = 0;
};

class FixedDepositInterestCalculator : public InterestCalculator {
public:
    double calculateInterest(double balance) const override {
        // logic to calculate interest for fixed deposit account
    }
};

class SavingsAccountInterestCalculator : public InterestCalculator {
public:
    double calculateInterest(double balance) const override {
        // logic to calculate interest for savings account
    }
};

