#include <iostream>

class A {
public:
    virtual void foo() {
        std::cout << "A::foo()" << std::endl;
    }
};

class B : virtual public A {  // Virtual inheritance
public:
    void foo() {
        std::cout << "B::foo()" << std::endl;
    }
};

class C : virtual public A {  // Virtual inheritance
public:
    void foo() {
        std::cout << "C::foo()" << std::endl;
    }
};

class D : public B, public C {
public:
    void foo()  {
        A::foo(); // Call B's foo()
    }
};

int main() {
    D d;
    d.foo();  // Calls B::foo() or C::foo() (no ambiguity)
    return 0;
}
