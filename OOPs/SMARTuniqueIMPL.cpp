template <typename T>
class unique_ptr
{
public:
    // Constructor: Takes ownership of a raw pointer
    explicit unique_ptr(T *ptr = nullptr) : ptr_(ptr) {}

    // Destructor: Releases ownership and deletes the object
    ~unique_ptr()
    {
        if (ptr_)
        {
            delete ptr_;
        }
    }

    // Move constructor: Transfers ownership from another unique_ptr
    unique_ptr(unique_ptr &&other) : ptr_(other.ptr_)
    {
        other.ptr_ = nullptr;
    }

    // Move assignment: Transfers ownership from another unique_ptr
    unique_ptr &operator=(unique_ptr &&other)
    {
        if (this != &other)
        {
            reset(other.ptr_);
            other.ptr_ = nullptr;
        }
        return *this;
    }

    // Copy constructor and assignment are explicitly deleted
    unique_ptr(const unique_ptr &) = delete;
    unique_ptr &operator=(const unique_ptr &) = delete;

    // Get the raw pointer
    T *get() const
    {
        return ptr_;
    }

    // Release ownership and return the raw pointer
    T *release()
    {
        T *ptr = ptr_;
        ptr_ = nullptr;
        return ptr;
    }

    // Reset the unique_ptr with a new raw pointer, releasing the old one
    void reset(T *ptr = nullptr)
    {
        if (ptr_ != ptr)
        {
            delete ptr_;
            ptr_ = ptr;
        }
    }

    // Dereference operator
    T &operator*() const
    {
        return *ptr_;
    }

    // Member access operator
    T *operator->() const
    {
        return ptr_;
    }

private:
    T *ptr_;
};
