#include "Customer.hpp"
#include <iostream>

Customer::Customer(int id, const std::string& name, int age, const std::string& gender)
    : customerId(id), customerName(name), customerAge(age), customerGender(gender) {}

void Customer::CustomerDetails() {
    // Implementation for displaying customer details
    // ...
}
