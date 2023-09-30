#include <iostream>
using namespace std;

class A {
public:
    void foo() { cout << "A::foo()" << endl; }
};

class B :  public virtual A { // Use virtual inheritance
public:
    void foo() { cout << "B::foo()" << endl; }
};

class C :   public virtual A { // Use virtual inheritance
public:
    void foo() { cout << "C::foo()" << endl; }
};

class D : public B, public C {
public:
    
};

int main() {
    D d;
    //d.foo(); // Now, B::foo() will be called without ambiguity
    return 0;
}
