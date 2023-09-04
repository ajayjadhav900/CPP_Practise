#include "Product.hpp"
#include <iomanip>

Product::Product(std::string name, std::string catagory, double prize, double discount)
{
    ProductName = name;
    Catagory = catagory;
    Prize = prize;
    Discount = discount;
}

void Product::SetProductName(std::string name)
{
    ProductName = name;
}

void Product::SetProductCatagory(std::string catagory)
{
    Catagory = catagory;
}

void Product::SetPrize(double prize)
{
    Prize = prize;
}

void Product::SetDiscount(double disc)
{
    Discount = disc;
}

std::string &Product::GetProductName()
{
    return ProductName;
}

std::string &Product::GetProductCatagory()
{
    return Catagory;
}

double Product::GetPrize()
{
    return Prize;
}

double Product::GetDiscount()
{
    return Discount;
}

void Product::PrintProduct() 
{
    std::cout << "\n-------------------------------------\n";
    std::cout << "Product Name: " << ProductName << "\n";
    std::cout << "Category: " << Catagory << "\n";
    std::cout << "Price: $" << std::fixed << std::setprecision(2) << Prize << "\n";
    std::cout << "Discount: " << Discount << "%\n";
    std::cout << "\n-------------------------------------\n";
}