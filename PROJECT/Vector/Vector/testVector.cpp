#include"Vector.h"
#include<string>

using namespace std;
using namespace tairitsu_h;

Vector<int> v;

template<class T>
void print_vector1(Vector<T>& v)
{
	for (auto i : v)
	{
		cout << i << " ";
	}

	cout << endl;
}

template<class T>
void print_vector2(Vector<T>& v)
{
	typename Vector<T>::const_iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
}

void test_vector1()
{
	v.push_back(1);
	print_vector1(v);
	v.push_back(2);
	print_vector1(v);
	v.push_back(3);
	print_vector1(v);
	v.push_back(4);
	print_vector1(v);
	v.push_back(5);
	print_vector1(v);
	v.push_back(6);
	print_vector1(v);
}

void test_vector2()
{
	v.pop_back();
	print_vector2(v);
	v.pop_back();
	print_vector2(v);
	v.pop_back();
	print_vector2(v);
	v.pop_back();
	print_vector2(v);
	v.pop_back();
	print_vector2(v);
}

void test_vector3()
{
	v.insert(v.begin(), 0);
	v.insert(v.begin() + 2, 0);
	v.insert(v.begin() + 5, 0);
	v.insert(v.end(), 0);
	//v.insert(v.begin() + 15, 0); 越界报错
	print_vector1(v);
}

void test_vector4()
{
	v.erase(v.begin());
	v.erase(v.begin() + 1);
	v.erase(v.begin() + 3);
	v.erase(v.end() - 1);
	print_vector1(v);
}

//测试删除偶数
template <class T>
void test_vector5(Vector<T>& v)
{
	typename Vector<T>::iterator it = v.begin();
	//或者auto it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0)
		{
			it = v.erase(it);
		}
		else
		{
			++it;
		}
	}

	print_vector1(v);
}

void test_vector6()
{
	cout << "构造测试" << endl;
	Vector<int> v1 = v;
	size_t n = 5;
	Vector<string> v2(n, "hello");
	print_vector1(v1);
	print_vector1(v2);

	Vector<string> v3 = v2;
	print_vector1(v3);

	Vector<string> v4(v3.begin(), v3.end());
	print_vector2(v4);
}

//void test_vector7()
//{
//
//}

int main()
{
	test_vector1();
	//test_vector2();
	test_vector3();
	test_vector4();
	test_vector5(v);
	test_vector6();
	return 0;
}