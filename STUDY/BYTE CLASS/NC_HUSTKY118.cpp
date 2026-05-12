//https://www.nowcoder.com/practice/b1f7a77416194fd3abd63737cdfcf82b?tpId=69&&tqId=29669&rp=1&ru=/activity/oj&qru=/ta/hust-kaoyan/question-ranking
#include<iostream>
using namespace std;

class Date
{
private:
    int _year;
    int _month;
    int _day;

public:
    Date(int year = 0, int day = 0, int month = 1)
        :_year(year)
        ,_month(month)
        ,_day(day)
    {}

    int GetMonthDay(int y, int m)
    {
        static int monthday[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if(m == 2 && ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0))
        {
            return 29;
        }

        return monthday[m];
    }

    void CulDate()
    {
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
    }

    void Print_Date()
    {
        printf("%04d-%02d-%02d\n", _year, _month, _day);
    }

};

int main()
{
    int y, d;
    while(cin >> y >> d)
    {
        Date d1(y, d);

        d1.CulDate();
        d1.Print_Date();
    }

    return 0;
}