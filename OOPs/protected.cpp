#include <iostream>
using namespace std;

// Base class
class Vehicle
{
protected:
    int wheels;

public:
    Vehicle(int numWheels) : wheels(numWheels) {}
    void display()
    {
        cout << "Number of wheels: " << wheels << endl;
    }
};

// Derived class 1
class Car : protected Vehicle
{
protected:
    string brand;

public:
    Car(string carBrand, int numWheels) : Vehicle(numWheels), brand(carBrand) {}
    void showBrand()
    {
        cout << "Brand: " << brand << endl;
    }
};

// Derived class 2
class Sedan : protected Car
{
private:
    string model;

public:
    Sedan(string carBrand, int numWheels, string carModel) : Car(carBrand, numWheels), model(carModel) {}
    void showModel()
    {
        display();

        showBrand();
        cout << "Model: " << model << endl;
    }
};

int main()
{
    Sedan mySedan("Toyota", 4, "Camry");
    mySedan.display();    // Accessing base class member through derived class
    // mySedan.showBrand();  // Accessing protected member of the immediate base class
    mySedan.showModel(); // Accessing member of the derived class

    return 0;
}
