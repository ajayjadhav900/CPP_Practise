#include<iostream>
using namespace std;
template<typename T>
void MySwapFunct(T &a, T&b)
{
    T temp = a;
	a= b;
	b= temp;
}
class MyClass
{
	char *Name;
	public:
	MyClass(char *name):Name(name)
	{
	}
	char * GetName()
	{
		return Name;
	}
};
int main()
{
	MyClass m1("Ajay"), m2("Vijay");

	cout<<m1.GetName();
	cout<<m1.GetName();
		MySwapFunct(m1,m2);cout<<"After \n";
	
	cout<<m2.GetName();
	cout<<m2.GetName();
}