#include <iostream>
#include <string>
#include <list>
#include <memory>
#include "Order.hpp"
enum class AccountStatus
{
    ACTIVE,
    BLOCKED,
    BANNED,
    COMPROMISED,
    ARCHIVED,
    UNKNOWN
};

class Account
{
public:
    std::string Name;
    std::string UserName;
    std::string Password;
    std::string Email;
    int MobNo;
    std::string ShippingAddress;
    std::string Address;
    // class CreditCard
    // class Bank Account
    Account(const std::string &name,
            const std::string &userName,
            const std::string &password,
            const std::string &email,
            const int &mobNo,
            const std::string &shippingAddress,
            // class CreditCard
            // class Bank Account
            const std::string &address);

    const std::string GetShippingAddress();

    /*

    def add_product(self, product):
        None

    def add_productReview(self, review):
        None

    def reset_password(self):
        None

    */
};

class Seller
{
    Account SellerAccount;

public:
    std::list<Product *> SellerProductInventory;

    Seller(const std::string &name,
           const std::string &userName,
           const std::string &password,
           const std::string &email,
           const int &mobNo,
           const std::string &shippingAddress,
           // class CreditCard
           // class Bank Account
           const std::string &address);
    void AddProductToProductInventory(Product *);
};

class Buyer
{
    Account BuyerAccount;

public:
    Buyer(const std::string &name,
          const std::string &userName,
          const std::string &password,
          const std::string &email,
          const int &mobNo,
          const std::string &shippingAddress,
          // class CreditCard
          // class Bank Account
          const std::string &address);
    std::list<Product *> Cart;
    std::list<Order *> Orders;
    void AddProductToCart(Product *pr);
    void ProceedToOrder(Order *order);
    void ConfirmTheAddress();
    void ProceedWithPayment(IPayment *pay);
    const std::string &GetAddress();
};
class Admin
{
    Account AdminAccount;

public:
    Admin(const std::string &name,
          const std::string &userName,
          const std::string &password,
          const std::string &email,
          const int &mobNo,
          const std::string &shippingAddress,
          // class CreditCard
          // class Bank Account
          const std::string &address);
    std::list<Seller> SellerInventory;
    std::list<Product *> ProductInventory;
    void AddProdcuts();
    void PrintProducts();
};
