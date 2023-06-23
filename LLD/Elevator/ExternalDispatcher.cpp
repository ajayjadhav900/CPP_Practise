#include "ExternalDispatcher.hpp"
#include <iostream>
void ExternalDispatcher::PressExternalButton(int no)
{
    FloorNo = no;
    std::cout<<"External user requested the lift from the floor no: "<<FloorNo<<std::endl;
};