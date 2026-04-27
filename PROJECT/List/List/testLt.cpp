#include"List.h"
#include<iostream>
using namespace std;
using namespace tairitsu_h;

List<int> lt;

struct AA
{
	int _a1 = 0;
	int _a2 = 10;
};

template<typename T>
void print_list(List<T>& lt1)
{
	for (auto node : lt1)
	{
		cout << node << " ";
	}
	cout << endl;
}

void test_list1()
{
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);
}

void test_list2()
{
	List<int>::iterator it = lt.begin();
	while (it != lt.end())
	{
		cout << it._node->_data << " ";
		++it;
	}

	cout << endl;
}

void test_list3()
{
	List<AA> lta;
	lta.push_back(AA());
	lta.push_back(AA());
	lta.push_back(AA());
	lta.push_back(AA());
	lta.push_back(AA());

	List<AA>::iterator ita = lta.begin();
	while (ita != lta.end())
	{
		//这里相当于->了两次，由于编译器会自动补充->，所以仅需写一次
		cout << ita->_a1 << " " << ita->_a2 << " ";
		++ita;
	}

	cout << endl;
}

void test_list4()
{
	for (size_t i = 0; i < 4; i++)
	{
		lt.insert(lt.begin(), 0);
	}

	print_list(lt);
}

void test_list5()
{
	lt.pop_front();
	lt.pop_front();
	lt.pop_back();
	lt.pop_back();

	print_list(lt);
}

int main()
{
	test_list1();
	test_list2();
	test_list3();
	test_list4();
	test_list5();
	return 0;
}