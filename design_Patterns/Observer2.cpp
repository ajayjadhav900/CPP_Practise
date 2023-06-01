#include <iostream>
#include <vector>
#include <algorithm> // Include the <algorithm> header

#include "Observer2.hpp"
using namespace std;

int main()
{

    Stock *ibm = new IBM("IBM", 120);
    IInvestor *i1 = new Investor("Ajay");
    IInvestor *i2 = new Investor("Gopal");
    IInvestor *i3 = new Investor("Vinita");

    ibm->attach(i1);
    ibm->attach(i2);
    ibm->attach(i3);

    ibm->setPrice(120.50);
    ibm->setPrice(112.50);
    ibm->setPrice(125.50);

    ibm->detach(i3);
    ibm->setPrice(125.50);
    return 0;
}

void Stock::detach(IInvestor *valueToRemove)
{
    investors.erase(std::remove(investors.begin(), investors.end(), valueToRemove), investors.end());
}

void Stock::notifyInvestors(double price)
{
    for (auto itr : investors)
    {
        itr->update(price);
    }
    std::cout << endl;
}

void Stock::setPrice(double newPrice)
{
    Price = newPrice;
    notifyInvestors(Price);
}

void Stock::attach(IInvestor *inv)
{
    investors.push_back(inv);
}

void Investor::update(double price)
{
    std::cout << Name << " received update. New price: " << price << std::endl;
}
