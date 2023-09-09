#include <iostream>
using namespace std;

template <typename T>
class MyUnique
{
public:
	T *data{nullptr};

	MyUnique(T *ptr) : data(ptr)
	{
	}
	MyUnique(const MyUnique &other) = delete;
	MyUnique &operator=(const MyUnique &other) = delete;
	MyUnique(MyUnique &&other)
	{

		data = other.data;
		other.data = nullptr;
	}

	MyUnique &operator=(const MyUnique &&other)
	{
		if (this == &other)
			return *this;

		delete data;
		data = other.data;
		return *this;
	}
	T &operator*()
	{
		return *data;
	}
	T *operator->()
	{
		return data;
	}
	~MyUnique()
	{
		cout<<"MyUnique destr\n";
		delete data;
	}
	T *Get()
	{
		return data;
	}
};
class Resource
{
public:
	Resource()
	{
		cout << "Resource Const\n";
	}
	~Resource()
	{
		cout << "Resource Destr\n";
	}
	void MyFunc(int a )
	{
		cout << "MyFunc\n"<<a;
	}
};

int PassByValue(MyUnique<Resource> Res)
{
	Res->MyFunc(10);
}
int main()
{
	MyUnique<Resource> res2(new Resource());
	//MyUnique<Resource> res1(move(res2));
	// res2(move(res1));
	Resource *it = res2.Get();
	it->MyFunc(11);

	PassByValue(std::move(res2));
	res2->MyFunc(12);
	return 0;
}