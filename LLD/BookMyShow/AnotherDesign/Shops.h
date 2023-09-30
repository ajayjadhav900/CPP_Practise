#ifndef SHOPS_H
#define SHOPS_H

#include <string>

class Shops {
private:
    int shopId;
    int employeeId;
    std::string shopName;
    std::string itemList;

public:
    Shops(int id, int employee, const std::string& name, const std::string& itemList);
    void ShopDetails();
    void ItemDetails();
    void Buy();
};

#endif  // SHOPS_H
