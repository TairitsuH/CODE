#include "Shared_Ptr.h"
#include<iostream>
#include<functional>
using namespace std;

struct Date
{
	int _year;
	int _month;
	int _day;

	Date(int y = 2000, int m = 1, int d = 1)
		:_year(y)
		,_month(m)
		,_day(d)
	{
		cout << "Date()" << endl;
	}

	~Date()
	{
		cout << "~Date()" << endl;
	}

	Date& operator=(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;

		return *this;
	}

};

int main()
{
	mzh::shared_ptr<Date> sp1(new Date);
	mzh::shared_ptr<Date> sp2(sp1);
	mzh::shared_ptr<Date> sp3(sp1);

	mzh::shared_ptr<Date> sp4 = new Date;

	sp1->_year++;
	sp1->_year++;
	sp1->_year++;

	//自赋值
	sp1 = sp1;
	sp1 = sp2;

	//赋值
	sp1 = sp4;

	cout << sp1->_year << endl;

	return 0;
}