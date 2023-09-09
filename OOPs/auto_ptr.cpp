#include <iostream>
using namespace std;

template <typename T>
class Auto_ptr
{
    T *m_ptr;

public:
    Auto_ptr()
    {
    }
    Auto_ptr(T *ptr = nullptr)
    {
        m_ptr = ptr;
    }
    Auto_ptr(Auto_ptr &ptr)
    {
        m_ptr = ptr.m_ptr;
        ptr.m_ptr = nullptr;
    }

    Auto_ptr & operator =(Auto_ptr &ptr)
    {
        if(this == &ptr)
            return *this;

        m_ptr = ptr.m_ptr;
        ptr.m_ptr  = nullptr;
        return *this;

    }
    T *operator->()
    {
        return m_ptr;
    }

    T &operator*()
    {
        return *m_ptr;
    }
    ~Auto_ptr()
    {
        cout << "Deleted Address: " << m_ptr << endl;
        delete m_ptr;
    }
};

// A sample class to prove the above works
class Resource
{
public:
    Resource() { std::cout << "Resource acquired\n"; }
    ~Resource() { std::cout << "Resource destroyed\n"; }
};

void passByValue(Auto_ptr<Resource> res)
{
}
int main()
{
    Auto_ptr<Resource> res(new Resource()); // Note the allocation of memory here
    Auto_ptr<Resource> res2(res);
    passByValue(res);
    return 0;
}