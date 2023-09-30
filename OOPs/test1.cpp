template <typename T>

class MySmartPointer
{
    T *ptr;
    size_t *count{0};

public:
    MySmartPointer(T *p = nullptr) : ptr(p)
    {
        count = new int(1);
    }
    MySmartPointer(const MySmartPointer &other)
    {
        ptr = other.ptr;
        count = other.count;
        (*count)++;
    }

    MySmartPointer &operator=(MySmartPointer &other)
    {
        if (this != &other)
        {
            if (count >= 2)
            {
                ptr = other.ptr;
                count = other.count;
                (*count)++;
            }
            else if (count > 0 || count == 1)
            {
                delete ptr;
                ptr = other.ptr;
                count = other.count;
                (*count)++;
            }
        }
        return *this;
    }

    ~MySmartPointer()
    {
        if ((*count) > 0)
        {
            (*count)--;
            if (ptr && count == 0)
            {
                delete ptr;
            }
        }
    }
};

class Resource
{

public:
    Resource()
    {
        // constrctor
    }
    ~Resource()
    {
        // destr
    }
};

int main()
{
    MySmartPointer<Resource> res(new Resource());

    return 0;
}