#include <iostream>
#include <string>

// 1. Overloading based on number of parameters
int calculateArea(int side) {
    std::cout << "Calculating area of square: ";
    return side * side;
}

int calculateArea(int length, int width) {
    std::cout << "Calculating area of rectangle: ";
    return length * width;
}

// 2. Overloading based on type of parameters
double calculateArea(double radius) {
    std::cout << "Calculating area of circle: ";
    return 3.14159 * radius * radius;
}

// 3. Overloading with different parameter order
void printInfo(std::string name, int age) {
    std::cout << "Name: " << name << ", Age: " << age << std::endl;
}

void printInfo(int age, std::string name) {
    std::cout << "Age: " << age << ", Name: " << name << std::endl;
}

// 4. Overloading with const parameters
void processString(std::string str) {
    std::cout << "Processing non-const string: " << str << std::endl;
    str += " (modified)"; // Can modify
}

void processString(const std::string& str) {
    std::cout << "Processing const string: " << str << std::endl;
    // str += " (modified)"; // Error: cannot modify const string
}

// 5. Ambiguous overload example (and how to fix)
// void processValue(int value) {
//     std::cout << "Processing int: " << value << std::endl;
// }

// void processValue(double value) {
//     std::cout << "Processing double: " << value << std::endl;
// }

//Fixed version, using explicit conversions when needed:
void processValue(int value) {
    std::cout << "Processing int: " << value << std::endl;
}

void processValue(double value) {
    std::cout << "Processing double: " << value << std::endl;
}

// 6. Overloading with reference and pointer types.
void modifyValue(int& value) {
    std::cout << "Modifying int reference: ";
    value *= 2;
}

void modifyValue(int* value) {
    std::cout << "Modifying int pointer: ";
    *value *= 3;
}

int main() {
    std::cout << calculateArea(5) << std::endl;
    std::cout << calculateArea(4, 6) << std::endl;
    std::cout << calculateArea(2.5) << std::endl;

    printInfo("Alice", 30);
    printInfo(25, "Bob");

    std::string myString = "Test";
    //processString(myString);
    //processString("Constant string");
    std::cout << "Modified string: " << myString << std::endl;

    processValue(10);
    processValue(5.5);
    processValue(static_cast<double>(10)); //Explicit cast to resolve ambiguity if it existed.

    int x = 5;
    modifyValue(x);
    std::cout << "Modified x: " << x << std::endl;

    int y = 10;
    modifyValue(&y);
    std::cout << "Modified y: " << y << std::endl;

    return 0;
}