// src/main.cpp
#include "Calculator.hpp"
#include <iostream>
#include <limits> // For numeric limits
#include <stdexcept> // For std::invalid_argument>

int main() {
    Calculator calc;
    double num1, num2; // Use double for more flexibility with input
    char operation;

    std::cout << "Simple Calculator Application" << std::endl;
    std::cout << "-----------------------------" << std::endl;

    while (true) {
        std::cout << "Enter first number: ";
        if (!(std::cin >> num1)) {
            std::cerr << "Invalid input. Please enter a number." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        std::cout << "Enter second number: ";
        if (!(std::cin >> num2)) {
            std::cerr << "Invalid input. Please enter a number." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        std::cout << "Enter operation (+, -, *, /) or 'q' 'Q' to quit: ";
        std::cin >> operation;

        if (operation == 'q' || operation == 'Q') {
            std::cout << "Exiting calculator." << std::endl;
            break;
        }

        double result; // Store result as double to handle potential floating-point division

        switch (operation) {
            case '+':
                result = calc.add(static_cast<int>(num1), static_cast<int>(num2));
                std::cout << "Result: " << result << std::endl;
                break;
            case '-':
                result = calc.subtract(static_cast<int>(num1), static_cast<int>(num2));
                std::cout << "Result: " << result << std::endl;
                break;
            case '*':
                result = calc.multiply(static_cast<int>(num1), static_cast<int>(num2));
                std::cout << "Result: " << result << std::endl;
                break;
            case '/':
                try {
                    result = calc.divide(static_cast<int>(num1), static_cast<int>(num2));
                    std::cout << "Result: " << result << std::endl;
                } catch (const std::invalid_argument& e) {
                    std::cerr << "Error: " << e.what() << std::endl;
                }
                break;
            default:
                std::cerr << "Invalid operation!" << std::endl;
        }
        std::cout << std::endl;
        // Consume any remaining input in the buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return 0;
}