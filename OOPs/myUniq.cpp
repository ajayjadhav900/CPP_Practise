#include <iostream>
template <typename T>
class MyUniquePtr
{
    T *ptr;

public:
    MyUniquePtr(T *p = nullptr) : ptr(p)
    {
    }
    MyUniquePtr(MyUniquePtr &other) = delete;
    MyUniquePtr &operator=(MyUniquePtr &other) = delete;
    MyUniquePtr &operator=(MyUniquePtr &&other)
    {
        if (this != &other)
        {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }

    MyUniquePtr(MyUniquePtr &&other)
    {
        if (this != &other)
        {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
    }
    ~MyUniquePtr()
    {
        if (ptr != nullptr)
            delete ptr;
    }
};

class Resource
{
    int a;

public:
    Resource(int b)
    {
        a = b;
        std::cout << "Resource allocated\n";
    }
    ~Resource()
    {
        std::cout << "Resource destroyed!!!\n";
    }
};
int main()
{
    // Resource *res = new Resource(10);
    MyUniquePtr<Resource> temp(new Resource(10));
    MyUniquePtr<Resource> uniq2(std::move(temp));

    MyUniquePtr<int> a(new int(1));
    MyUniquePtr<int> b(new int(2));
    MyUniquePtr<int> c(new int(3));



    return 0;
}

