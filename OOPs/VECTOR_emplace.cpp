#include <iostream>
#include <memory>

template <typename T>
class vector {
public:
    // ... (other member functions and constructors)

    // Emplace an element at the end of the vector
    template <typename... Args>
    void emplace_back(Args&&... args) {
        if (size_ == capacity_) {
            reserve(capacity_ == 0 ? 1 : capacity_ * 2);
        }
        new (&data_[size_]) T(std::forward<Args>(args)...);
        size_++;
    }

private:
    size_t size_;
    size_t capacity_;
    T* data_;

    // ... (other private member functions and data members)

    // Allocate new memory and copy existing elements to the new memory
    void reserve(size_t newCapacity) {
        T* newData = new T[newCapacity];
        for (size_t i = 0; i < size_; i++) {
            // Move construct the elements to the new memory
            new (&newData[i]) T(std::move(data_[i]));
            // Explicitly call the destructor for the old elements
            data_[i].~T();
        }
        delete[] data_;
        data_ = newData;
        capacity_ = newCapacity;
    }
};
