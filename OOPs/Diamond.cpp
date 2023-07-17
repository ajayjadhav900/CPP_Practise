#include <iostream>
#include<memory>
class PoweredDevice
{
public:
    PoweredDevice(int power)
    {
        std::cout << "PoweredDevice: " << power << '\n';
    }
        PoweredDevice()
    {
        std::cout << "PoweredDevice: "  << '\n';
    }
};

class Scanner :  public PoweredDevice
{

public:
    Scanner(int scanner, int power)
        : PoweredDevice{power}
    {
        std::cout << "Scanner: " << scanner << '\n';
    }
};

class Printer :  public PoweredDevice
{
public:
    Printer(int printer, int power)
        : PoweredDevice{power}
    {
        std::cout << "Printer: " << printer << '\n';
    }
};

class Copier : public Scanner, public Printer
{
public:
    Copier(int scanner, int printer, int power)
        : //PoweredDevice{power}, // PoweredDevice is constructed here
          Scanner{scanner, power}, Printer{printer, power}
    {
    }
};

int main()
{
    Copier copier{1, 2, 3};



    return 0;
}