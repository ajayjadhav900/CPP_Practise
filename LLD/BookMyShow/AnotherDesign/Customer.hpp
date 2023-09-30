#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer {
private:
    int customerId;
    std::string customerName;
    int customerAge;
    std::string customerGender;

public:
    Customer(int id, const std::string& name, int age, const std::string& gender);
    void CustomerDetails();
};

#endif  // CUSTOMER_H
