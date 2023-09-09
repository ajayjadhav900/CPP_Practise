#include <iostream>
#include <memory>
#include <cstring>
class Base
{
    char *Name;
    int no = 0;

public:
    Base(char *name = nullptr) : Name(new char[strlen(name) + 1])
    {
        strcpy(Name, name);
    }
    Base(const Base &copy)
    {
        char *temp = nullptr;
        temp = new char[strlen(copy.Name) + 1];
        strcpy(Name, copy.Name);
    }
    Base &operator=(const Base &other)
    {
        if (this != &other)
        {
            delete[] Name;
            Name = new char[strlen(other.Name) + 1];
            strcpy(Name, other.Name);
        }

        return *this;
    }
    Base & operator++()
    {
        delete Name;
        strcpy(Name, new char[strlen(Name) + 1]);
        strcpy(Name, Name);
        no++;
        return *this;
    }

    void display()
    {

        std::cout << "Name :" << Name << std::endl<<" No: "<<no;
    }
    ~Base()
    {
        delete[] Name;
    }
};

int main()
{
    Base b1("Ajay");
    Base b2(b1);
    b1++;
    b1.display();

    return 0;
}