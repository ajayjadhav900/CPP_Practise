#include <iostream>

class Base
{
public:
    virtual void display() const
    {
        std::cout << "Base class display" << std::endl;
    }
    virtual ~Base() {} // Important for polymorphic behavior
};

class Derived : public Base
{
public:
    void display() const override
    {
        std::cout << "Derived class display" << std::endl;
    }

    void derivedSpecificFunction() const
    {
        std::cout << "Derived-specific function" << std::endl;
    }
};

int main()
{
    Base *basePtr1 = new Derived(); // Points to a Derived object
    Base *basePtr2 = new Base();    // Points to a Base object

    // static_cast (no runtime type check)
    Derived *derivedPtr1_static = static_cast<Derived *>(basePtr1);
    Derived *derivedPtr2_static = static_cast<Derived *>(basePtr2); // Potentially dangerous!

    if (derivedPtr1_static)
    {
        derivedPtr1_static->derivedSpecificFunction(); // Safe, because basePtr1 points to a Derived
    }

    if (derivedPtr2_static)
    {
        // derivedPtr2_static->derivedSpecificFunction(); // Undefined behavior! basePtr2 is a base.
    }

    // dynamic_cast (runtime type check)
    Derived *derivedPtr1_dynamic = dynamic_cast<Derived *>(basePtr1);
    Derived *derivedPtr2_dynamic = dynamic_cast<Derived *>(basePtr2);

    if (derivedPtr1_dynamic)
    {
        derivedPtr1_dynamic->derivedSpecificFunction(); // Safe
    }

    if (derivedPtr2_dynamic)
    {
        // This block will not execute, as dynamic_cast returns nullptr
        // derivedPtr2_dynamic->derivedSpecificFunction();
    }
    else
    {
        std::cout << "dynamic_cast failed: basePtr2 is not a Derived object." << std::endl;
    }

    delete basePtr1;
    delete basePtr2;

    return 0;
}