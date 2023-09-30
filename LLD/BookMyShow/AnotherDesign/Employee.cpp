#include "Employee.hpp"
#include <iostream>

Employee::Employee(int id, const std::string& name, const std::string& designation, float salary)
    : employeeId(id), employeeName(name), designation(designation), salary(salary) {}

void Employee::EmployeeDetails() {
    // Implementation for displaying employee details
    // ...
}
