#include "Cart.hpp"

void Cart::AddProductToCart(Product *pr)
{
        CartItems.push_back(pr);

}

void Cart::RemoveProductFromCart(int ch)
{
    if (ch > CartItems.size())
    {
        std::cout << "Enter valid choice!!!\n";
    }
    else
    {
        int i = 0;
        for (std::list<Product *>::iterator itr = CartItems.begin(); itr != CartItems.end(); itr++)
        {
            if (i == ch)
            {
                CartItems.erase(itr);
                std::cout << "Product removed from the Cart!!!\n";
                ++i;
            }
        }
    }
}

void Cart::UpdateTheQuantityOfProductsInCart(int ch, int quant)
{
    if (ch > CartItems.size())
    {
        std::cout << "Enter valid choice!!!\n";
    }
    else
    {
        int i = 0;
        for (std::list<Product *>::iterator itr = CartItems.begin(); itr != CartItems.end(); itr++)
        {
            if (i == ch)
            {
                (*itr)->SetQuantity(quant);
                std::cout << "Product quantity upadated to " << (*itr)->GetQuantity();
                ++i;
            }
        }
    }
}

void Cart::ViewTheCart()
{
    std::cout << "\n---------CART------------\n";
    for (auto itr : CartItems)
    {
        itr->PrintProduct();
    }

    std::cout << "\n Subtotal:" << SubTotal << "\n";
}
