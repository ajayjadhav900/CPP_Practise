#include <iostream>
#include<map>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<unordered_map>
using namespace std;

int main()
{
    map<int,string> myMap;
    myMap.insert(make_pair(101,"Ajay"));
	myMap.insert(make_pair(102,"Vijay"));
	myMap.insert(make_pair(102,"Vijay"));
	myMap[101] = "AAjay";
	
	map<int, string> ::iterator itr;
	
	for(itr = myMap.begin();itr != myMap.end();itr++)
	{
		cout<<itr->first<<" " <<itr->second<<endl;
	}
	vector<int> myVec;
	myVec.resize
    return 0;
}