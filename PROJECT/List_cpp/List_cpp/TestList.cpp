#include"List.h"
#include<iostream>
#include<utility>
#include<string>
#include<assert.h>
using namespace std;

//emplace_back
//int main()
//{
//	mzh::list<mzh::string> lt;
//
//	mzh::string s1("111111111111");
//	lt.emplace_back(s1); //传入左值s1，走拷贝构造
//	lt.push_back(s1);
//	cout << "*********************************" << endl;
//
//	lt.emplace_back(move(s1)); //传入右值s1，走移动构造
//	cout << "*********************************" << endl;
//
//	lt.emplace_back("111111111111"); //把构造string参数包往下传（特有）
//	cout << "*********************************" << endl;
//
//	mzh::list<pair<mzh::string, int>> lt1; //构造lt1
//
//	pair<mzh::string, int> kv("苹果", 1); //构造pair
//    lt1.emplace_back(kv); //拷贝构造pair到list的节点中_data上
//	cout << "*********************************" << endl;
//
//	// 跟push_back⼀样
//	lt1.emplace_back(move(kv));
//	cout << "*********************************" << endl;
//
//	////////////////////////////////////////////////////////////////////
//	lt1.emplace_back("苹果", 1); //一步构造完成
//	cout << "*********************************" << endl;
//
//	return 0;
//}


//新的类功能+default+delete
class Person
{
public:
	Person(const char* name = "LiHua", int age = 0)
		:_name(name)
		, _age(age)
	{
	}

	// ~Person(){} //加上后就不会再生成默认的移动构造
	//Person(Person&& p) = default; //会影响到拷贝构造的生成
	Person(Person& p) = delete;
	//Person& operator=(const Person& p) = default;
	//Person& operator=(Person&& p) = default;

private:
	mzh::string _name;
	int _age;
};
int main()
{
	Person s1; //构造
	Person s2 = s1; //拷贝构造
	//Person s3 = move(s1); //移动构造
	cout << endl;

	Person s4; //构造
	s4 = s2; //拷贝赋值
	//s4 = move(s2); //移动赋值
	return 0;
}

////IO流和线程不允许拷贝构造(delete)
//void Cout(ostream out)
//{
//	out << endl;
//}
//
//int main()
//{
//	Cout(cout);
//}



