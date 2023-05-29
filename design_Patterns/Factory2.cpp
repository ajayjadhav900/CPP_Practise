#include "Factory2.hpp"
#include "string"
#include <iostream>
using namespace std;
int Kia::GetCarPrice()
{
    return 120000;
}

std::string Kia::GetCarModel()
{
    return "Sonet";
}

std::string Kia::GetCarColour()
{
    return "Dark redish";
}

int Hundai::GetCarPrice()
{
    return 900000;
}

std::string Hundai::GetCarModel()
{
    return "Venue";
}

std::string Hundai::GetCarColour()
{
    return "Dark Blue";
}

int BMW::GetCarPrice()
{
    return 8000000;
}

std::string BMW::GetCarModel()
{
    return "X7";
}

std::string BMW::GetCarColour()
{
    return "Dark Silver";
}

ICar *FactoryCars::GetCarDetails(std::string model)
{
    ICar *CarDetails = nullptr;
    if (model.compare("Sonet") == 0)
    {
        CarDetails = new Kia();
    }

    else if (model.compare("Venue") == 0)
    {
        CarDetails = new Hundai();
    }

    else if (model.compare("X7") == 0)
    {
        CarDetails = new BMW();
    }
    return CarDetails;
}

int main()
{

    ICar *CarDetails = nullptr;
    string model("X7");
    cout << "Enter car model";
    // cin>>model;

    CarDetails = FactoryCars::GetCarDetails(model);
    cout<<CarDetails->GetCarModel().c_str()<<endl;
    cout << CarDetails->GetCarColour().c_str()<<endl;
    cout << CarDetails->GetCarPrice();

    return 0;
}
