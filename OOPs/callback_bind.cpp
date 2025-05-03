#include <iostream>
#include <string>
#include <functional> // For std::bind and std::function

void sayHelloWithSalutation(const std::string& salutation, const std::string& name) {
    std::cout << salutation << ", " << name << "!" << std::endl;
}

void processNameBound(const std::string& name, std::function<void(const std::string&)> callback) {
    std::cout << "Processing name (with bind): " << name << std::endl;
    callback(name);
    std::cout << "Processing complete (with bind)." << std::endl;
}

int main() {
    // Bind the "Hello" salutation to the sayHelloWithSalutation function
    auto helloCallback = std::bind(sayHelloWithSalutation, "Greetings", std::placeholders::_1);
    processNameBound("David", helloCallback);
    return 0;
}