#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee {
private:
    int employeeId;
    std::string employeeName;
    std::string designation;
    float salary;

public:
    Employee(int id, const std::string& name, const std::string& designation, float salary);
    void EmployeeDetails();
};

#endif  // EMPLOYEE_H
