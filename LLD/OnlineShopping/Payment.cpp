#include <iostream>
#include "Payment.hpp"
void DebitCard::DoThePayment(int prize)
{
    std::cout << "Payment of Rupeez %d Done via DebitCard!!!\n"
              << prize;
}

void CreditCard::DoThePayment(int prize)
{
    std::cout << "Payment of Rupeez %d Done via CreditCard!!!\n"
              << prize;
}

void UPIMode::DoThePayment(int prize)
{
    std::cout << "Payment of Rupeez %d Done via UPIMode!!!\n"
              << prize;
}

void COD::DoThePayment(int prize)
{
    std::cout << "Payment of Rupeez %d Done via Cash(COD)!!!\n"
              << prize;
}
