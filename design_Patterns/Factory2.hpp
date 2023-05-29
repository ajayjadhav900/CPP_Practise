#include"string"
//using namespace std;
class ICar
{

    public:
    int virtual GetCarPrice() = 0;
    std::string virtual GetCarModel()=0;
    std::string virtual GetCarColour() = 0;
};

class Kia: public ICar
{
    public:
    int GetCarPrice();
    std::string GetCarModel();
    std::string GetCarColour();

};

class Hundai:public ICar
{
    public:
    int GetCarPrice();
    std::string GetCarModel();
    std::string GetCarColour();

};

class BMW:public ICar
{
    public:
    int GetCarPrice();
    std::string GetCarModel();
    std::string GetCarColour();

};


class FactoryCars 
{

public:
  static ICar *  GetCarDetails(std::string Model);
};

