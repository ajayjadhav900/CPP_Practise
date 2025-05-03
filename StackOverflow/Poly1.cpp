#include <iostream>
#include <vector>
#include <exception>

void foo(std::exception const &e1)
{
    try
    {
        std::cout << e1.what() << std::endl;
        throw e1;
    }
    catch (std::exception const &e2)
    {
        std::cout << e2.what() << std::endl;
    }
}

int main()
{
    foo(std::runtime_error{"this is not std::exception"});
}