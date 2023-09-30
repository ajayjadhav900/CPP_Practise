#include<list>

#include "Product.hpp"
#ifndef Cart_HPP
#define Cart_HPP

class Cart
{
    std::list<Product *> CartItems;
    double SubTotal{0};
public:
    void AddProductToCart(Product *);
    void RemoveProductFromCart(int ch);
    void UpdateTheQuantityOfProductsInCart(int ch, int quan);
    void ViewTheCart();

    auto GetCartItems()
    {
        return CartItems;
    }
};
#endif