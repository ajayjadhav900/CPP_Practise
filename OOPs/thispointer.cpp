#include <iostream>

class MyClass {
public:
    void printAddress() {
        std::cout << "Address of the current object: " << this << std::endl;
    }

    MyClass& otherFunction() {
        // Pass the this pointer to another function
        someOtherFunction(this);
        return *this;
    }

    void someOtherFunction(MyClass* obj) {
        std::cout << "Address of the object received as parameter: " << obj << std::endl;
    }


};

int main() {
    MyClass obj;
    obj.printAddress(); // Output: Address of the current object: 0x7ffd8ee75d90
    MyClass &obj2 = obj.otherFunction(); // Output: Address of the object received as parameter: 0x7ffd8ee75d90
    obj2.printAddress();
    return 0;
}
