#include<iostream>
#include<vector>
#include<string>
#include "UnorderedMap.h"
#include "UnorderedSet.h"
using namespace std;

void test_set1()
{
	int a[] = { 3, 1, 6, 7, 8, 2, 1, 1, 5, 6, 7, 6 };
	mzh::unordered_set<int> s;
	for (auto x : a)
	{
		s.insert(x);
	}

	mzh::unordered_set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	for (auto x : s)
	{
		cout << x << " ";
	}

}

void test_map1()
{
	mzh::unordered_map<string, string> dict;
	dict.insert({ "字符串", "string" });
	dict.insert({ "插入", "insert" });
	dict.insert({ "删除", "delete" });
	dict.insert({ "查找", "find" });
	dict.insert({ "整型", "int" });

	mzh::unordered_map<string, string>::iterator it = dict.begin();
	while (it != dict.end())
	{
		cout << it->first << " " << it->second << endl;
		++it;
	}

	cout << endl;
	for (auto& x : dict)
	{
		//x.second += "hello!"; //可以修改value
		cout << x.first << " " << x.second << endl;
	}
	
}

int main()
{
	cout << "test_set1" << endl;
	test_set1();
	cout << endl;

	cout << "test_map1" << endl;
	test_map1();
	cout << endl;

	return 0;
}
