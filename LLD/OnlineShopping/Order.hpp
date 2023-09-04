#include <string>
#include <vector>
#include "Product.hpp"
#include "Payment.hpp"
enum class DeliveryStatus
{
    RETURN,
    Confrimed,
    Delivered,
    ONTHEWAY
};

class Order
{
    public:
    std::string OrderID;
    std::vector<Product *> ItemsList;
    IPayment *PaymentMode ;
    DeliveryStatus OrderDelStatus;
    Order(std::string orderID,  
    std::vector<Product *> ItemsList,
    IPayment *PaymentMode);

};
