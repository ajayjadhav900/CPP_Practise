#include "AbstractFactory.hpp"
#include <iostream>
using namespace std;
void TataCar::GetCar()
{
    cout << "I am tata car Nexon!!!\n";
}

void TataTruck::GetTruck()
{
    cout << "I am tata truck Ace!!!\n";
}

void MahindraCar::GetCar()
{
    cout << "I am Mahindra car XUV 400!!!\n";
}

void MahindraTruck::GetTruck()
{
    cout << "I am Mahindra truck Blazo!!!\n";
}

Icar *tata::GetCar()
{
    return new TataCar();
}

Itruck *tata::GetTruck()
{
    return new TataTruck();
}

Icar *Mahindra::GetCar()
{
    return new MahindraCar();
}

Itruck *Mahindra::GetTruck()
{
    return new MahindraTruck();
}

int main()
{
    
    // Icar is the first level abstraction but IVehicleCompany is the 2nd level abstraction.
    IVehicleCompany *comp = new tata();
    Icar *cars = comp->GetCar(); // we dont know concrete subclass
    cars->GetCar();

    Itruck *trucks = comp->GetTruck();
    trucks->GetTruck();

    IVehicleCompany *comp2 = new Mahindra();
    Icar *cars2 = comp2->GetCar(); // we dont know concrete subclass
    cars2->GetCar();

    Itruck *trucks2 = comp2->GetTruck();
    trucks2->GetTruck();

    /* conclusion:
    design pattern that lets us  produce families of
    related objects (Mahindra, tata) without specifying their concrete classes(Cars, Trucks).
    */
      
       

    return 0;
}
