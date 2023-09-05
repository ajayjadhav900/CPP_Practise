#include "Account.hpp"
#include "Catalog.hpp"
#include <iostream>
int main()
{
    /*g++ -o amazon Payment.cpp Product.cpp Order.cpp Catalog.cpp Account.cpp main.cpp*/

    std::cout << "\n\n---------------AMAZON SHOPPING---------------\n\n";

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

    Catalog c1;

    for (auto sellers : admin1.SellerInventory)
    {
        for (auto prodcuts : sellers.SellerProductInventory)
        {
            c1.AddProductsInCatalog(prodcuts);
        }
    }
    Buyer buyer1("Ajay", "ajay.jadhav900", "BuyerPass123",
                 "ajay.jadhav900@gmail.com", 1234567890, "Chakan", "ShippingAddress");

    // At this point, the user has finished adding products to their cart
    // You can proceed with the payment process

    IPayment *pay = new DebitCard();
    buyer1.ProceedWithPayment(pay);
    int choice;
    std::list<Product> searchResults;
    std::string searchProductName = "";
    while (true)
    {
        // Display the menu
        std::cout << "Online Shopping Menu:" << std::endl;
        std::cout << "1. Search The Product" << std::endl;
        std::cout << "2. Add Product To Cart" << std::endl;
        std::cout << "3. Proceed to Buy" << std::endl;
        std::cout << "4. Select Delivery Address" << std::endl;
        std::cout << "5. Select Payment" << std::endl;
        std::cout << "6. Place Your Order" << std::endl;
        std::cout << "7. Exit" << std::endl;

        // Prompt for user choice
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cout << "Searching for products..." << std::endl;
            std::cout << "Enter the product name to search (or type 'exit' to finish): ";
            std::cin >> searchProductName;

            if (searchProductName == "exit")
            {
                break; // Exit the loop if the user wants to finish
            }

            // Search for the product in the catalog
            searchResults = c1.SearchTheProductsByName(searchProductName);

            if (searchResults.empty())
            {
                std::cout << "Product not found. Please try again.\n";
            }
            else
            {
                std::cout << "Product found!\n";
            }
            break;

        case 2:
            std::cout << "Adding product to cart..." << std::endl;
            // Add code for adding a product to the cart

            int productChoice;
            std::cout << "Enter the number of the product you want to add to your cart: ";
            std::cin >> productChoice;

            if (productChoice >= 1 && productChoice <= searchResults.size())
            {
                // Add the selected product to the cart
                int i = 1; // Initialize i to 1
                for (auto itr : searchResults)
                {
                    if (i == productChoice)
                    {
                        buyer1.AddProductToCart(&itr);
                        std::cout << "Product added to cart!\n";
                        break;
                    }
                    i++;
                }
            }
            else
            {
                std::cout << "Invalid choice. Please try again.\n";
            }
            break;

        case 3:
            std::cout << "Proceeding to Buy..." << std::endl;
            // Add code for proceeding to buy
            break;

        case 4:
            int deliveryChoice;
            std::cout << "Select Delivery Address:" << std::endl;
            std::cout << "1. Address1" << std::endl;
            std::cout << "2. Address2" << std::endl;
            std::cout << "3. Add New Address" << std::endl;
            std::cout << "4. Pickup the Location Near You" << std::endl;
            std::cout << "5. Back to Cart" << std::endl;
            std::cout << "Enter your choice: ";
            std::cin >> deliveryChoice;
            // Handle delivery address choices here
            break;

        case 5:
            int paymentChoice;
            std::cout << "Select Payment Method:" << std::endl;
            std::cout << "1. Credit or Debit Card" << std::endl;
            std::cout << "2. UPI" << std::endl;
            std::cout << "3. Cash on Delivery" << std::endl;
            std::cout << "Enter your choice: ";
            std::cin >> paymentChoice;
            // Handle payment choices here
            break;

        case 6:
            std::cout << "Placing your order..." << std::endl;
            // Add code for placing the order
            break;

        case 7:
            std::cout << "Exiting the program." << std::endl;
            return 0;

        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
        }
    }

    return 0;
}
