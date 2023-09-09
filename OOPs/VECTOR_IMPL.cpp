template <typename T>
class vector {
public:
    // Constructor: Creates an empty vector
    vector() : size_(0), capacity_(0), data_(nullptr) {}

    // Destructor: Deletes the allocated memory
    ~vector() {
        delete[] data_;
    }

    // Copy constructor: Creates a deep copy of the vector
    vector(const vector& other) : size_(other.size_), capacity_(other.capacity_) {
        data_ = new T[capacity_];
        std::copy(other.data_, other.data_ + size_, data_);
    }

    // Move constructor: Transfers ownership of data from another vector
    vector(vector&& other) : size_(other.size_), capacity_(other.capacity_), data_(other.data_) {
        other.size_ = 0;
        other.capacity_ = 0;
        other.data_ = nullptr;
    }

    // Copy assignment operator: Creates a deep copy of the vector
    vector& operator=(const vector& other) {
        if (this != &other) {
            delete[] data_;
            size_ = other.size_;
            capacity_ = other.capacity_;
            data_ = new T[capacity_];
            std::copy(other.data_, other.data_ + size_, data_);
        }
        return *this;
    }

    // Move assignment operator: Transfers ownership of data from another vector
    vector& operator=(vector&& other) {
        if (this != &other) {
            delete[] data_;
            size_ = other.size_;
            capacity_ = other.capacity_;
            data_ = other.data_;
            other.size_ = 0;
            other.capacity_ = 0;
            other.data_ = nullptr;
        }
        return *this;
    }

    // Access elements using index operator []
    T& operator[](size_t index) {
        return data_[index];
    }

    const T& operator[](size_t index) const {
        return data_[index];
    }

    // Push back an element to the end of the vector
    void push_back(const T& value) {
        if (size_ == capacity_) {
            reserve(capacity_ == 0 ? 1 : capacity_ * 2);
        }
        data_[size_++] = value;
    }

    // Get the current size of the vector
    size_t size() const {
        return size_;
    }

    // Get the maximum number of elements the vector can hold
    size_t capacity() const {
        return capacity_;
    }

private:
    size_t size_;
    size_t capacity_;
    T* data_;

    // Allocate new memory and copy existing elements to the new memory
    void reserve(size_t newCapacity) {
        T* newData = new T[newCapacity];
        std::copy(data_, data_ + size_, newData);
        delete[] data_;
        data_ = newData;
        capacity_ = newCapacity;
    }
};
