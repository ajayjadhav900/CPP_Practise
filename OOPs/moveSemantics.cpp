#include <iostream>
#include <vector>
#include <string>

// Function to simulate getting data
std::string getData() {
    return "Hello, World!";
}

int main() {
    std::vector<std::string> coll;
    coll.reserve(3); // Preallocate memory for 3 elements

    // Get data and add it to the vector
    std::string s1{getData()};
    std::string s2{getData()};

    // Store the addresses of individual strings
    const std::string* addr_s1 = &s1;
    const std::string* addr_s2 = &s2;

    std::cout << "Address of s1: " << addr_s1 << std::endl;
    std::cout << "Address of s2: " << addr_s2 << std::endl;

    coll.push_back(s1); // Copy the string
    coll.push_back(std::move(s2)); // Move the string

    std::cout << "Address of s1 (after copy push_back): " << addr_s1 << std::endl;
    std::cout << "Address of s2 (after move push_back): " << addr_s2 << std::endl;

    // Print the contents of the vector along with addresses
    std::cout << "Vector contents:" << std::endl;
    for (const std::string& element : coll) {
        std::cout << "Address: " << &element << " - Value: " << element << std::endl;
    }

    return 0;
}
