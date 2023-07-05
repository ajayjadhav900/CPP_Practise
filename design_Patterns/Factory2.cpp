#include <iostream>
#include <vector>
#include <algorithm> // Include the <algorithm> header
using namespace std;

class Product
{
public:
    virtual ~Product()
    {
    }
};

class ConcreteProduct1 : public Product
{
public:
    ConcreteProduct1()
    {
        cout << "I am ConcreteProduct1" << endl;
    }
    virtual ~ConcreteProduct1()
    {
    }
};

class ConcreteProduct2 : public Product
{
public:
    ConcreteProduct2()
    {
        cout << "I am ConcreteProduct2" << endl;
    }
    virtual ~ConcreteProduct2()
    {
    }
};

class Creater
{

public:
    virtual Product *FactoryMethod() = 0;

    virtual ~Creater()
    {
    }
};
class ConcreteCreater1 : public Creater
{

public:
    virtual ~ConcreteCreater1()
    {
    }
    Product *FactoryMethod()
    {
        Product *pr = nullptr;
        pr = new ConcreteProduct1();
        return pr;
    }
};

class ConcreteCreater2 : public Creater
{

public:
    virtual ~ConcreteCreater2()
    {
    }
    Product *FactoryMethod()
    {
        Product *pr = nullptr;

        pr = new ConcreteProduct2();
        return pr;
    }
};

int main()
{
    Creater *cr = new ConcreteCreater1();
    cr->FactoryMethod();
    delete cr;
    return 0;
}