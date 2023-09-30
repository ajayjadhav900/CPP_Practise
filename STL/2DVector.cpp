#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include<set>
#include<queue>
using namespace std;
int main()
{
    queue<int> vec;
    set<int> dupSet;

    for (int i = 0; i < vec.size(); i++)
    {
        auto pair = dupSet.emplace(vec[i]);
        if(pair.second == false)
            cout<<vec[i]<<" ";
    }
    return 0;
}