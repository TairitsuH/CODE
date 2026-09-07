#include<iostream>
#include<vector>
#include<string>
#include "UnorderedMap.h"
#include "UnorderedSet.h"
using namespace std;


//整型测试（哈希桶）
void test_hash3()
{
	int a[] = { 19, 30, 5, 36, 13, 20, 21, 12, 24, 96 };
	mzh::unordered_set<int> s;

	for (auto x : a)
	{
		s.insert(x);
	}

	s.insert(100);
	s.insert(101);
}

////字符串测试（哈希桶）
//void test_hash4()
//{
//	vector<string> v = { "hello", "world", "abcd", "adcb", "acdb", "bcad", "C++", "int", "string", "char", "C", "Linux" };
//	mzh::unordered_set<string> hash4;
//	for (auto& str : v)
//	{
//
//		hash4.insert({ str, HashFunc<string>()(str) });
//	}
//
//	if (hash4.Find("abcd"))
//	{
//		cout << "找到了" << endl;
//	}
//	else
//	{
//		cout << "没找到" << endl;
//	}
//
//	hash4.Erase("abcd");
//	if (hash4.Find("abcd"))
//	{
//		cout << "找到了" << endl;
//	}
//	else
//	{
//		cout << "没找到" << endl;
//	}
//
//	if (hash4.Find("Linux"))
//	{
//		cout << "找到了" << endl;
//	}
//	else
//	{
//		cout << "没找到" << endl;
//	}
//}

//赋值重载和拷贝构造测试
//void test_hash5()
//{
//	int a[] = { 19, 30, 5, 36, 13, 20, 21, 12, 24, 96 };
//	hash_bucket::HashTable<int, int> hash5;
//
//	for (auto x : a)
//	{
//		hash5.Insert({ x, x });
//	}
//
//	//拷贝构造
//	hash_bucket::HashTable<int, int> hash6 = hash5;
//
//	//赋值重载
//	hash_bucket::HashTable<int, int> hash7;
//	hash_bucket::HashTable<int, int> hash8;
//
//	hash7 = hash8 = hash5;
//}

int main()
{
	//cout << "test_hash1" << endl;
	//test_hash1();
	//cout << endl;
	//cout << "test_hash2" << endl;
	//test_hash2();
	//cout << endl;
	cout << "test_hash3" << endl;
	test_hash3();
	cout << endl;
	//cout << "test_hash4" << endl;
	//test_hash4();
	//cout << endl;
	//cout << "test_hash5" << endl;
	//test_hash5();

	return 0;
}
