#include <iostream>

class A
{
public:
    void print()
    {
        std::cout << "A";
    }
    virtual void vprint()
    {
        std::cout << "A";
    }
};
class B : public A
{
public:
    void print()
    {
        std::cout << "B";
    }
    void vprint() override
    {
        std::cout << "B";
    }
    void MyFunct(A &a)
    {
        a.vprint();
    }
};

class C
{
private:
    A m_a{};

public:
    virtual A &get()
    {
        return m_a;
    }
};

class D : public C
{
private:
    B m_b{};

public:
    B &get() override
    {
        return m_b;
    }
};

class MyClass
{
    int i;

public:
    explicit MyClass(int j) : i(j)
    {
        i = i * 10;
    }
    void print()
    {
        std::cout << "i = " << i;
    }
};
void funct(MyClass o )
{
}
int main()
{
    A a;
    B b;

    b.MyFunct(b);

    MyClass obj(10);
    funct(std::move(obj));
    return 0;
}