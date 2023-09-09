#include <iostream>
#include <vector>
class MyClass
{
private:
    int value;

public:
    MyClass(int val = 0) : value(val) {}

    // Pre-increment operator (++obj)
    MyClass &operator++()
    {
        // Increment the value and return the updated object
        ++value;
        return *this;
    }

    // Post-increment operator (obj++)
    MyClass operator++(int)
    {
        // Create a temporary object with the current value
        MyClass temp = *this;

        // Increment the value in the original object
        ++value;

        // Return the temporary object with the original value
        return temp;
    }

    // Function to display the value
    void display() const
    {
        std::cout << "Value: " << value << std::endl;
    }
};

int main()
{
    MyClass obj1(5);

    // Pre-increment
    ++obj1;
    obj1.display(); // Output: Value: 6

    // Post-increment
    MyClass obj2 = obj1++;
    obj1.display(); // Output: Value: 7
    obj2.display(); // Output: Value: 6

    std::vector<MyClass> numbers = {obj1, obj2};

    for (auto itr = numbers.begin(); itr != numbers.end(); ++itr)
    {
        itr->display();

        std::cout << typeid(itr).name();
    }
    auto a = 10;
    std::cout << typeid(a).name();

    auto abc = 'a';
    std::cout << typeid(abc).name();
    return 0;
}
