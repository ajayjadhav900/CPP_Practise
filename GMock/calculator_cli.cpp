#include "calculator.h"
#include <iostream>
#include <memory>

class SimpleDependency : public Dependency {
public:
    int getValue() override {
        return 10; // Example fixed value
    }

    bool process(int data) override {
        return data > 0; // Example condition
    }

    int add(int num1, int num2) {
        return num1 + num2;
    }

    int subtract(int num1, int num2) {
        return num1 - num2;
    }
};

/* 
The error occurs because both calculator_cli.cpp and calculator_test.cpp define a `main` function, leading to a multiple definition error during linking. To resolve this, you need to compile and link only one file with a `main` function at a time.

For example:
- To run the tests, compile and link calculator_test.cpp with the necessary dependencies.
- To run the command-line interface, compile and link calculator_cli.cpp with the necessary dependencies.

Here are the commands you can use:

1. **Compile and run the tests:**

   g++ -std=c++11 calculator_test.cpp calculator.cpp -o calculator_test -lgtest -lgtest_main -lgmock -lgmock_main -pthread
   ./calculator_test


2. **Compile and run the CLI:**

g++ -std=c++14 calculator_cli.cpp calculator.cpp -o calculator_cli
./calculator_cli   

*/
int main() {
    std::unique_ptr<Dependency> dependency = std::make_unique<SimpleDependency>();
    Calculator calculator(dependency.get());

    int choice;
    do {
        std::cout << "Calculator Menu:\n";
        std::cout << "1. Add with value from dependency\n";
        std::cout << "2. Process data and get value\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            int input;
            std::cout << "Enter a number to add: ";
            std::cin >> input;
            int result = calculator.addWithValueFromDependency(input);
            std::cout << "Result: " << result << "\n";
            break;
        }
        case 2: {
            bool result = calculator.processDataAndGetValue();
            std::cout << "Result: " << (result ? "True" : "False") << "\n";
            break;
        }
        case 0:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}