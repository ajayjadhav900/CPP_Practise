#include <iostream>

class MyClass
{
private:
    int *data;

public:
    // Default constructor
    MyClass()
    {
        data = new int(0);
        std::cout << "Default constructor called. Value: " << *data << std::endl;
    }
    MyClass &operator()(MyClass &other)
    {
                std::cout << "() called. Value: " << other.data << std::endl;

        return other;
    }
    // Parameterized constructor
    MyClass(int value)
    {
        data = new int(value);
        std::cout << "Parameterized constructor called. Value: " << *data << std::endl;
    }

    // Copy constructor
    MyClass(const MyClass &other)
    {
        data = new int(*other.data);
        std::cout << "Copy constructor called. Value: " << *data << std::endl;
    }

    // Assignment operator
    MyClass &operator=(const MyClass &other)
    {
        if (this != &other)
        {
            delete data; // Deallocate existing memory
            data = new int(*other.data);
        }
        std::cout << "Assignment operator called. Value: " << *data << std::endl;
        return *this;
    }

    // Getter method
    int getValue() const
    {
        return *data;
    }

    // Destructor
    ~MyClass()
    {
        delete data; // Deallocate memory
        std::cout << "Destructor called. Value: " << *data << std::endl;
    }
};

int main()
{
    // Create an object using the default constructor
    MyClass obj1;

    // Create another object using the parameterized constructor
    MyClass obj2(42);

    // Copy obj2 to obj3 using the copy constructor
    MyClass obj3 = obj2;

    // Assign obj1 with the value of obj3 using the assignment operator
    obj3(obj3);

    // Print values
    std::cout << "obj1: " << obj1.getValue() << std::endl;
    std::cout << "obj2: " << obj2.getValue() << std::endl;
    std::cout << "obj3: " << obj3.getValue() << std::endl;

    return 0;
}
