#include <iostream>
#include <cassert>
#include <cstddef>
#include <cstring>
using namespace std;
template <typename T>
class shared_ptr
{
    T *data;
    int *ref_count;

public:
    shared_ptr()
    {
        ref_count++;
    }
    shared_ptr(T *ptr) 
    {
        data = ptr;
        ref_count++;
    }
    shared_ptr(const T &rhs)
    {
        data = rhs.data;
        ref_count++;
    }
    T &operator=(const T &rhs)
    {
        data = rhs.data;
        ref_count++;

        return *this;
    }

    shared_ptr(const T &&rhs)
    {
        data = rhs.data;
        ref_count++;
    }
    T &operator=(const T &&rhs)
    {
        data = rhs.data;
        rhs.data = nullptr;

        return *this;
    }

    T *operator->()
    {
        return ptr;
    }

    T &operator*()
    {
        return *ptr;
    }

    int use_count()
    {
        return *ref_count;
    }
    ~shared_ptr()
    {
        *ref_count--;

        if (*ref_count == 0)
        {
            delete ref_count;
            delete data;
        }
    }
};

class Resource
{
public:
    Resource()
    {
        cout << " Constructor \n";
    }

    ~Resource()
    {
        cout << "Destructor \n";
    }
};

int main()
{
    shared_ptr<Resource> res(new Resource());
    cout << res.use_count();
}