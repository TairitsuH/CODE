#include"List.h"
#include<iostream>
#include<utility>
#include<string>
#include<assert.h>
using namespace std;

int main()
{
	mzh::list<mzh::string> lt;

	mzh::string s1("111111111111");
	lt.emplace_back(s1); //传入左值s1，走拷贝构造
	lt.push_back(s1);
	cout << "*********************************" << endl;

	lt.emplace_back(move(s1)); //传入右值s1，走移动构造
	cout << "*********************************" << endl;

	lt.emplace_back("111111111111"); //把构造string参数包往下传（特有）
	cout << "*********************************" << endl;

	mzh::list<pair<mzh::string, int>> lt1; //构造lt1

	pair<mzh::string, int> kv("苹果", 1); //构造pair
    lt1.emplace_back(kv); //拷贝构造pair到list的节点中_data上
	cout << "*********************************" << endl;

	// 跟push_back⼀样
	lt1.emplace_back(move(kv));
	cout << "*********************************" << endl;

	////////////////////////////////////////////////////////////////////
	lt1.emplace_back("苹果", 1); //一步构造完成
	cout << "*********************************" << endl;

	return 0;
}








