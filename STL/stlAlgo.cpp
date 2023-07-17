#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
bool isEven(int num)
{
    return num % 2 == 1;
}
int main()
{
    vector<int> myVec{10, 34, 12, 25, 7, 11, 6, 4, 10};

    vector<int>::iterator itr;

    auto result = std::find_if(myVec.begin(), myVec.end(), isEven);
    cout << *result;
    cout << "\nVector : ";
    for (itr = myVec.begin(); itr != myVec.end(); itr++)
    {
        cout << *itr << " ";
    }

    return 0;
}
