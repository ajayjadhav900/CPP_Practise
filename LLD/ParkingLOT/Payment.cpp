#include "Payment.hpp"

#include<iostream>

void OnlineApp::PayingTheFee(int fee)
{
    std::cout<<"Paying the fee via APP!"<<fee<<std::endl;
}

void Cash::PayingTheFee(int fee)
{
    std::cout<<"Paying the fee via cash!"<<fee<<std::endl;
}

void Card::PayingTheFee(int fee)
{
     std::cout<<"Paying the fee via card!"<<fee<<std::endl;
}
