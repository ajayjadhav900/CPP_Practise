#include <iostream>

class MyClass {
private:
    int* data;

public:
    // Constructor
    MyClass(int size) : data(new int[size]) {
        std::cout << "Constructor called." << std::endl;
    }

    MyClass( MyClass & other)
    {
        int *data = new int;
        data = other.data;
    }
    void display()
    {
        std::cout<<"Address of the object data  is"<<&this->data;
    }
    // Move constructor
    MyClass(MyClass&& other) noexcept : data(other.data) {
        std::cout << "Move constructor called." << std::endl;

        other.data = nullptr; // Transfer ownership of data to the current object and set the source object's data to nullptr.
    }

    // Destructor
    ~MyClass() {
        delete[] data;
        std::cout << "\nDestructor called." << std::endl;
    }

    // Other member functions and operators are defined here.
};

int main() {
    MyClass obj1(5);
    obj1.display();
    MyClass obj2(std::move(obj1)); // Move constructor called, transferring ownership of data from obj1 to obj2
    //MyClass obj2(obj1);
    obj2.display();
    return 0;
}
