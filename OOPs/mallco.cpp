#include <iostream>
#include <memory>

class Base
{
public:
    Base()
    {
        std::cout << "Base class constr" << std::endl;
    }
    Base(const Base &other)
    {
        std::cout << "Base class copy constr" << std::endl;
    }
    Base &operator=(Base &other)
    {
        std::cout << "Base class assign= constr" << std::endl;

        if (this == &other)
        {
            return *this;
        }

        return other;
    }
    virtual void display() const
    {
        std::cout << "Base class" << std::endl;
    }
};

class Derived : public Base
{
public:
    Base B;
    void display() const override
    {
        std::cout << "Derived class" << std::endl;
    }
    Derived()
    {
        std::cout << "Derived class constr" << std::endl;
    }
    Derived(Base &other)
    {
        std::cout << "Derived class copy constr" << std::endl;

        Derived::B = other;
    }
};

int main()
{
    Base b;
    Derived d1(b);
    return 0;
}
