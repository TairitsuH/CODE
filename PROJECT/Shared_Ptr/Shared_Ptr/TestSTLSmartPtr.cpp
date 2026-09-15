#include<iostream>

struct Date
{
	int _year;
	int _month;
	int _day;

	Date(int y = 2000, int m = 1, int d = 1)
		:_year(y)
		, _month(m)
		, _day(d)
	{
		std::cout << "Date()" << std::endl;
	}

	~Date()
	{
		std::cout << "~Date()" << std::endl;
	}

	Date& operator=(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;

		return *this;
	}

};

