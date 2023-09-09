#include <iostream>
#include <string>
#include <utility> // for std::move
#include <vector>

int main()
{
	std::vector<std::string*> v;

	// We use std::string because it is movable (std::string_view is not)
	std::string *str= new std::string { "Knock" };
    std::cout<<"&str: "<<&str<<'\n';
	v.push_back(str); // calls l-value version of push_back, which copies str into the array element

	//v.push_back("AJay"); // calls r-value version of push_back, which moves str into the array element

	std::cout << "vector:" << v[0] << ' ' << v[1] << '\n'<<"v[1]: "<<&v[1];
    for(auto itr:v)
    {
        delete itr;
    }
	return 0;
}