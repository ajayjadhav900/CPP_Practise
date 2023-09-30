#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
using namespace std;
int main()
{
    vector<int> vec = {1, 2, 4, 2, 3, 5, 6, 4};
    set<int> dupSet;

    for (int i = 0; i < vec.size(); i++)
    {
        auto pair = dupSet.emplace(vec[i]);
        if (pair.second == false)
            cout << vec[i] << " ";
    }
    return 0;
}