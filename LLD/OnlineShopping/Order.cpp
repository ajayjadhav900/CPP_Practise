#include "Order.hpp"

Order::Order(std::string orderID, std::vector<Product *> ItemsList, IPayment *PaymentMode)
{
    OrderDelStatus = DeliveryStatus::ONTHEWAY;
}