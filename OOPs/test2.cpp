#include <iostream>
#include <vector>

// Write your printElement function here
template <typename T>

void printElement(std::vector<T> pVec, int index)
{
    if (index < 0 || index >= pVec.size())
    {
        std::cout << "Invalid Index!!!";
        return;
    }
    std::cout << "Element found at " << index <<std:: endl;
}

int main()
{
    std::vector v1{0, 1, 2, 3, 4};
    printElement(v1, 2);
    printElement(v1, 5);

    std::vector v2{1.1, 2.2, 3.3};
    printElement(v2, 0);
    printElement(v2, -1);

    return 0;
}