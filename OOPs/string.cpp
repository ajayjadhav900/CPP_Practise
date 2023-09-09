#include <cstring>
#include <iostream>
#include <utility>
using namespace std;

class Mystring
{
	size_t Size;
	char *StrArray; 

	public:
	Mystring(char *str =nullptr):StrArray(str),Size(0)
	{
        if(str)
		Size = strlen(str);
	}
	Mystring(const Mystring &other)
	{
		StrArray = new char[strlen(other.StrArray)+1];
		strcpy(StrArray,other.StrArray);
		Size = other.Size;
	}

    friend std::ostream& operator<<(std::ostream& os, const Mystring& str) {
        os << str.StrArray;
        return os;
    }

	Mystring & operator = (Mystring & other)
	{
		if(this != &other)
		{
			delete [] StrArray;
			StrArray = new char[strlen(other.StrArray)+1];
			strcpy(StrArray,other.StrArray);
			Size = other.Size;
		}
		
		return *this;
		
	}
    size_t GetSize()
    {
        return Size;
    }
	~Mystring()
	{
		delete [] StrArray;
	}

};

int add(int a, int b) {
    return a + b;
}

double add(double a, int b) {
    return a+b;
}


int main()
{
	Mystring str("Ajay");
    Mystring str2;
    str2=str;
     int temp  =10;
     const int *ptr = &temp;
    int* temp2 = const_cast<int*>(ptr);
    (*temp2)++;
    cout<<*temp2;
}