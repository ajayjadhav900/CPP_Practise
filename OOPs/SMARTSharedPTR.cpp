template <typename T>
class shared_ptr {
public:
    // Constructor: Takes ownership of a raw pointer
    explicit shared_ptr(T* ptr = nullptr) : ptr_(ptr), ref_count_(new size_t(1)) {}

    // Destructor: Release ownership and delete the object if ref_count becomes zero
    ~shared_ptr() {
        decrementRefCount();
    }

    // Copy constructor: Increases the reference count
    shared_ptr(const shared_ptr& other) : ptr_(other.ptr_), ref_count_(other.ref_count_) {
        (*ref_count_)++;
    }

    // Copy assignment: Decreases the old reference count and increases the new one
    shared_ptr& operator=(const shared_ptr& other) {
        if (this != &other) {
            decrementRefCount();
            ptr_ = other.ptr_;
            ref_count_ = other.ref_count_;
            (*ref_count_)++;
        }
        return *this;
    }

    // Move constructor: Transfers ownership from another shared_ptr
    shared_ptr(shared_ptr&& other) : ptr_(other.ptr_), ref_count_(other.ref_count_) {
        other.ptr_ = nullptr;
        other.ref_count_ = nullptr;
    }

    // Move assignment: Transfers ownership from another shared_ptr
    shared_ptr& operator=(shared_ptr&& other) {
        if (this != &other) {
            decrementRefCount();
            ptr_ = other.ptr_;
            ref_count_ = other.ref_count_;
            other.ptr_ = nullptr;
            other.ref_count_ = nullptr;
        }
        return *this;
    }

    // Get the raw pointer
    T* get() const {
        return ptr_;
    }

    // Dereference operator
    T& operator*() const {
        return *ptr_;
    }

    // Member access operator
    T* operator->() const {
        return ptr_;
    }

private:
    T* ptr_;
    size_t* ref_count_;

    // Decrement the reference count and delete the object if no more references
    void decrementRefCount() {
        if (ref_count_) {
            (*ref_count_)--;
            if (*ref_count_ == 0) {
                delete ptr_;
                delete ref_count_;
            }
        }
    }
};
