#include <iostream>
#include <cassert>
#include <cstddef>
#include <cstring>
using namespace std;
class Employee
{
	char *Name{"nullptr"};
	int Id{0};

public:
	Employee()
	{
		Name = "nullptr";
		Id = 0;
	}
	Employee(char *name, int id) : Name(name), Id(id)
	{
	}
	Employee(const Employee &emp)
	{
		char *temp = new char[strlen(emp.Name) + 1];

		strcpy(temp, emp.Name);
		Name = temp;
		Id = emp.Id;
	}

	Employee &operator=(const Employee &emp)
	{
		char *temp = new char[strlen(emp.Name) + 1];

		strcpy(temp, emp.Name);
		Name = temp;
		Id = emp.Id;

		return *this;
	}

	bool operator==(const Employee &emp)
	{
		if (this == &emp)
			return true;
		else
		{
			if (!strcmp(this->Name, emp.Name) && Id == emp.Id)
				return true;
		}
		return false;
	}
	~Employee()
	{
		delete[] Name;
	}

	void display()
	{
		if (Name != nullptr)
			cout << "Name: " << Name << "Id: " << Id << endl;
	}
};

int main()
{
	Employee e1[3] = {{"Ajay", 10}, {"Vijay", 20}, {"Navin", 100}};

	Employee e2(e1[1]);
	e2.display();
	Employee e3;
	e3.display();

	if(e3 == e2)
		cout<<"Are same ";
}