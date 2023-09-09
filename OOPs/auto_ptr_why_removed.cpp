#include <iostream>
#include <memory>

void useAutoPtr(std::auto_ptr<int> ptr) {
    // Access the auto_ptr argument (resource was moved to ptr)
    if (ptr.get() != nullptr) {
        std::cout << "Value from useAutoPtr: " << *ptr << std::endl;
    } else {
        std::cout << "Pointer is null in useAutoPtr." << std::endl;
    }
}

int main() {
    std::auto_ptr<int> ptr(new int(42));
    std::cout << "Value from main: " << *ptr << std::endl;

    useAutoPtr(ptr); // Ownership transferred to useAutoPtr

    // Access the auto_ptr argument in main (ptr is now a null pointer)
    if (ptr.get() != nullptr) {
        std::cout << "Value from main after useAutoPtr: " << *ptr << std::endl;
    } else {
        std::cout << "Pointer is null in main." << std::endl;
    }

    return 0;
}
