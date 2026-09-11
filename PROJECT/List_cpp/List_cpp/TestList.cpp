#include"List.h"
#include<iostream>
#include<utility>
#include<string>
#include<assert.h>
using namespace std;


// emplace_back总体⽽⾔是更⾼效，推荐以后使⽤emplace系列替代insert和push系列
int main()
{
	bit::list<bit::string> lt;

	bit::string s1("111111111111");
	lt.emplace_back(s1); //传入左值s1，走拷贝构造
	cout << "*********************************" << endl;

	lt.emplace_back(move(s1)); //传入右值s1，走移动构造
	cout << "*********************************" << endl;

	lt.emplace_back("111111111111"); //把构造string参数包往下传（特有）
	cout << "*********************************" << endl;

	bit::list<pair<bit::string, int>> lt1; //构造lt1

	pair<bit::string, int> kv("苹果", 1); //构造pair
    lt1.emplace_back(kv); //拷贝构造pair到list的节点中_data上
	cout << "*********************************" << endl;

	// 跟push_back⼀样
	lt1.emplace_back(move(kv));
	cout << "*********************************" << endl;

	////////////////////////////////////////////////////////////////////
	// 直接把构造pair参数包往下传，用pair参数包构造pair
	// 这⾥达到的效果是push_back做不到的
	lt1.emplace_back("苹果", 1); //一步构造完成
	cout << "*********************************" << endl;

	return 0;
}








