#include "Account.hpp"
#include <iostream>
int main()
{
    /*g++ -g -o amazon Payment.cpp Product.cpp Order.cpp Account.cpp main.cpp*/

    std::cout << "\n\n---------------AMAZONSHOPPING---------------\n\n";

    Seller seller1("SellerName1", "SellerUsername1", "SellerPassword1",
                   "seller1@example.com", 1234567890, "SellerAddress1", "ShippingAddress1");
    Seller seller2("SellerName2", "SellerUsername2", "SellerPassword2",
                   "seller2@example.com", 1234567890, "SellerAddress2", "ShippingAddress2");

    seller1.AddProductToProductInventory(new Product("Classmates", "Stationary", 200, 0));
    seller1.AddProductToProductInventory(new Product("12th Physics", "Stationary", 500, 0));

    Product *product1 = new Product("Iphone14Plus", "Mobiles", 90000, 0);
    seller2.AddProductToProductInventory(product1);
    seller2.AddProductToProductInventory(new Product("MacbookPro", "Laptops", 150000, 0));

    Admin admin1("AjayAdmin", "ajay.jadhav900", "BuyerPass123",
                 "ajay.jadhav900@gmail.com", 1234567890, "Chakan", "ShippingAddress");
    admin1.SellerInventory.push_back(seller1);
    admin1.SellerInventory.push_back(seller2);

    admin1.AddProdcuts();
    admin1.PrintProducts();

    Buyer buyer1("Ajay", "ajay.jadhav900", "BuyerPass123",
                 "ajay.jadhav900@gmail.com", 1234567890, "Chakan", "ShippingAddress");

    buyer1.AddProductToCart(product1);
    IPayment *pay = new DebitCard();
    buyer1.ProceedWithPayment(pay);

    return 0;
}