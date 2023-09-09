#include <iostream>

// Function taking an r-value reference parameter
void modifyValue(int&& x) {
    x = 42; // Modifying the r-value (temporary value)
}

// Function taking an r-value reference to const parameter
void printValue(const int&& x) {
    std::cout << "Value: " << x << std::endl;
    // x = 42; // Uncommenting this line will result in a compilation error because 'x' is const.
}

int main() {
    // Modifiable l-value
    int a = 10;

    // Non-modifiable l-value
    const int b = 20;

    // R-value (temporary value)
    int c = 30 + 5;

    // R-value reference initialized with an r-value
    int&& refC = c + 10;

    // R-value reference to const initialized with an r-value
    const int&& refTemp = c + 20;

    // Modify the r-value
    modifyValue(c+10);

    // Access the r-value (temporary value) using the const r-value reference
    printValue(c + 40);

    // Print the modified value after the modification in the function
    std::cout << "Modified value: " << c << std::endl;

    return 0;
}
