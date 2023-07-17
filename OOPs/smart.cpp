#include <iostream>
#include <memory>

class Base {
public:
    virtual void display() const {
        std::cout << "Base class" << std::endl;
    }
};

class Derived : public Base {
public:
    void display() const override {
        std::cout << "Derived class" << std::endl;
    }
};

int main() {
    std::shared_ptr<Base> basePtr = std::make_shared<Derived>();
    
    // Access the object and call a virtual function through basePtr
    basePtr->display(); // Output: Derived class
    
    // Create another shared_ptr pointing to the same object
    std::shared_ptr<Base> anotherPtr = std::make_shared<Derived>();
    
    anotherPtr = basePtr;

    std::shared_ptr<Base> bp(anotherPtr);
    bp->display();

    basePtr= bp;
    std::cout << "Usage count: " << basePtr.use_count() << std::endl;
    std::weak_ptr<Base> weakPtr(basePtr);
    
    basePtr = nullptr;
    if (!weakPtr.lock()) {
        std::cout << "Weak pointer is valid." << std::endl;
    } else {
        std::cout << "Weak pointer is expired." << std::endl; // Output: Weak pointer is expired.
    }
    return 0;
}
