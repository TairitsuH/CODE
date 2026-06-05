//https://www.nowcoder.com/practice/eebb2983b7bf40408a1360efb33f9e5d?tpId=40&&tqId=31013&rp=1&ru=/activity/oj&qru=/ta/kaoyan/question-ranking
#include<iostream>
#include<vector>
using namespace std;

class Date
{
private:
    int _year;
    int _month;
    int _day;

public:
    Date(int year = 0, int month = 0, int day = 0)
        :_year(year)
        ,_month(month)
        ,_day(day)
        {}

    Date& operator+=(int day)
    {
        _day += day;
        while(_day > GetMonthDay(_year, _month))
        {
            _day -= GetMonthDay(_year, _month);
            _month += 1;

            if(_month == 13)
            {
                _month = 1;
                _year += 1;
            }
        }

        return *this;
    }

    int GetMonthDay(int y, int m)
    {
        static int monthday[13] = {0, 31,28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if(m == 2 && ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0))
        {
            return 29;
        }

        return monthday[m];
    }

    void Print_Date()
    {
        printf("%04d-%02d-%02d\n", _year, _month, _day);
    }
};

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int y, m, d, day;
        cin >> y >> m >> d >> day;

        Date d1(y, m, d);

        d1 += day;

        d1.Print_Date();
    }
    return 0;
}