#include "Shops.h"
#include <iostream>

Shops::Shops(int id, int employee, const std::string& name, const std::string& itemList)
    : shopId(id), employeeId(employee), shopName(name), itemList(itemList) {}

void Shops::ShopDetails() {
    // Implementation for displaying shop details
    // ...
}

void Shops::ItemDetails() {
    // Implementation for showing available items and their cost price
    // ...
}

void Shops::Buy() {
    // Implementation for buying items from the shop
    // ...
}
