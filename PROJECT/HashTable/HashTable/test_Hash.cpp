#include<iostream>
#include "HashTable.h"
using namespace std;

int main()
{
	//int a[] = {19, 30, 52, 63, 11, 22};
	int a[] = { 19, 30, 5, 36, 13, 20, 21, 12 };
	HashTable<int, int> hash;
	for (auto x : a)
	{
		pair<int, int> p1 = { x, x };
		hash.Insert(p1);
	}

	pair<int, int> p2 = { 15, 15 };
	hash.Insert(p2);

	hash.Erase(30);
	if (hash.Find(30))
	{
		cout << "找到了" << endl;
	}
	else
	{
		cout << "没找到" << endl;
	}

	if (hash.Find(20))
	{
		cout << "找到了" << endl;
	}
	else
	{
		cout << "没找到" << endl;
	}


	return 0;
}