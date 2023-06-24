#include <iostream>
#include "ATM.hpp"

/*
ATM LLD
g++ -g -o atm_machine Transaction.cpp Account.cpp User.cpp card.cpp  ATM.cpp main.cpp
*/
int main()
{
    ATM myATM;
    myATM.GenerateData();
    std::cout << "Enter Card : ";
    int crd = 12345, pin = 1234;
    // std::cin>>crd;
    std::cout << "Enter Pin :";
    // std::cin>>pin;
    if (!myATM.CardPinValidation(12345, 1234))
    {
        std::cout << "Invalid Card Pin no!!!\n";
    }
    while (1)
    {
        myATM.StartTransaction(crd, pin);
        std::cout << "Do u want to continue Press Y/N ";
        char ch;
        std::cin >> ch;
        if (ch == 'N')
        {
            return 0;
        }
    }
    return 0;
}