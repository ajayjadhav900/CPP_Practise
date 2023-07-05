#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Vehicle
{
public:
     Vehicle()
    {
    }
        virtual void display()
    {
        cout << "I am Vehicle";
    }
};
class Car : public Vehicle
{
public:
     Car()
    {
        
    }
        void display()
    {
        cout << "I am Car";
    }
};
class Bike : public Vehicle
{
public:
     Bike()
    {
        
    }
    void display()
    {
        cout << "I am Bike";
    }
};
int main()
{
    Bike C1;
    
    Vehicle *veh2 = static_cast<Vehicle *>(&C1);
    veh2->display();
    Bike *bk = dynamic_cast<Bike *>(veh2); 
    if (bk != nullptr) {
        bk->display();
    } else {
        std::cout << "Dynamic cast failed." << std::endl;
    }
    return 0;
}