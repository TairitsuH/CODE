#include<iostream>
#include "HashTable.h"
using namespace std;

//整型测试（开放定址）
void test_hash1()
{
	int a[] = { 19, 100, 63, 56, 13, 80, 71, 12 };
	open_address::HashTable<int, int> hash;
	for (auto x : a)
	{
		pair<int, int> p1 = { x, x };
		hash.Insert(p1);
	}

	pair<int, int> p2 = { 15, 15 };
	hash.Insert(p2);

	hash.Erase(100);
	if (hash.Find(100))
	{
		cout << "找到了" << endl;
	}
	else
	{
		cout << "没找到" << endl;
	}

	if (hash.Find(19))
	{
		cout << "找到了" << endl;
	}
	else
	{
		cout << "没找到" << endl;
	}
}

//字符串测试（开放定址）
void test_hash2()
{
	vector<string> v = { "hello", "world", "abcd", "adcb", "acdb", "bcad", "C++", "int", "string", "char", "C", "Linux"};
	open_address::HashTable<string, int, HashFunc<string>> hash;
	for (auto& str : v)
	{
		hash.Insert({ str, HashFunc<string>()(str) });
	}

	if (hash.Find("abcd"))
	{
		cout << "找到了" << endl;
	}
	else
	{
		cout << "没找到" << endl;
	}

	hash.Erase("abcd");
	if (hash.Find("abcd"))
	{
		cout << "找到了" << endl;
	}
	else
	{
		cout << "没找到" << endl;
	}

	if (hash.Find("Linux"))
	{
		cout << "找到了" << endl;
	}
	else
	{
		cout << "没找到" << endl;
	}
}

//测试（哈希桶）
void test_hash3()
{
	int a[] = {19, 30, 5, 36, 13, 20, 21, 12, 24, 96};
	hash_bucket::HashTable<int, int> hash3;

	for (auto x : a)
	{
		hash3.Insert({ x, x });
	}

	hash3.Insert({ 100, 100 });
	hash3.Insert({ 101, 101 });

}

int main()
{
	//cout << "test_hash1" << endl;
	//test_hash1();
	//cout << endl;
	//cout << "test_hash2" << endl;
	//test_hash2();
	cout << "test_hash3" << endl;
	test_hash3();

	return 0;
}