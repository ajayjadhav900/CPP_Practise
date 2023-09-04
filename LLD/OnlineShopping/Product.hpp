#include <iostream>
#include <string>

class Product
{
    std::string ProductName;
    std::string Catagory;
    double Prize;
    double Discount;

public:
    Product(std::string name, std::string catagory, double prize, double discount);
    void SetProductName(std::string name);
    void SetProductCatagory(std::string catagory);
    void SetPrize(double prize);
    void SetDiscount(double disc);
    std::string &GetProductName();
    std::string &GetProductCatagory();
    double GetPrize();
    double GetDiscount();
    void PrintProduct();
};