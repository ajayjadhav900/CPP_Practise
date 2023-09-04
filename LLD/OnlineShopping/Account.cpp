#include "Account.hpp"
#include <iomanip>

Account::Account(const std::string &name,
                 const std::string &userName,
                 const std::string &password,
                 const std::string &email,
                 const int &mobNo,
                 const std::string &shippingAddress,
                 const std::string &address)
    : Name(name),
      UserName(userName),
      Password(password),
      Email(email),
      MobNo(mobNo),
      ShippingAddress(shippingAddress),
      Address(address)
{
}

const std::string Account::GetShippingAddress()
{
    return ShippingAddress;
}

Admin::Admin(const std::string &name,
             const std::string &userName,
             const std::string &password,
             const std::string &email,
             const int &mobNo,
             const std::string &shippingAddress,
             const std::string &address)
    : AdminAccount(name, userName, password, email, mobNo, shippingAddress, address)
{
}

void Admin::AddProdcuts()
{
    for (auto seller : SellerInventory)
    {
        for (auto products : seller.SellerProductInventory)
            ProductInventory.push_back(products);
    }
}

void Admin::PrintProducts()
{

    for (auto product : ProductInventory)
    {
        product->PrintProduct();
    }
}

Seller::Seller(const std::string &name,
               const std::string &userName,
               const std::string &password,
               const std::string &email,
               const int &mobNo,
               const std::string &shippingAddress,
               const std::string &address)
    : SellerAccount(name, userName, password, email, mobNo, shippingAddress, address)
{
}
void Seller::AddProductToProductInventory(Product *product)
{
    SellerProductInventory.push_back(product);
}

Buyer::Buyer(const std::string &name,
             const std::string &userName,
             const std::string &password,
             const std::string &email,
             const int &mobNo,
             const std::string &shippingAddress,
             const std::string &address)
    : BuyerAccount(name, userName, password, email, mobNo, shippingAddress, address)
{
}

void Buyer::AddProductToCart(Product *pr)
{
    Cart.push_back(pr);
}

void Buyer::ProceedToOrder(Order *order)
{
    Orders.push_back(order);
}

void Buyer::ConfirmTheAddress()
{
    std::cout << "Address confirmed : " << GetAddress();
}

void Buyer::ProceedWithPayment(IPayment *pay)
{
}

const std::string &Buyer::GetAddress()
{
    return BuyerAccount.Address;
}
