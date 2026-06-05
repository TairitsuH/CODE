// https://www.nowcoder.com/practice/ccb7383c76fc48d2bbc27a2a6319631c?tpId=62&&tqId=29468&rp=1&ru=
#include<iostream>
#include<string>
using namespace std;

class Date
{
public:
    int _tuple;
    int _year;
    int _month;
    int _day;

    void GetYMD()
    {
        _year = _tuple / 1e4;
        _month = _tuple % 10000 / 100;
        _day = _tuple % 100;
    }

    int GetMonthDay()
    {
        static int MonthDay[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        if(_month == 2 && ((_year % 4 == 0 && _year % 100 != 0) || _year % 400 == 0))
        {
            return 29;
        }

        return MonthDay[_month];
    }

    Date& operator+=(int day)
    {
        _day += day;
        while(_day > GetMonthDay())
        {
            _day -= GetMonthDay();
            _month++;

            if(_month > 12)
            {
                _year++;
                _month = 1;
            }
        }

        return *this;
    }

    bool operator==(Date& d)
    {
        if(_year == d._year)
        {
            if(_month == _month)
            {
                if(_day == _day)
                {
                    return true;
                }

                return false;
            }

            return false;
        }

        return false;
    }

    bool operator<(Date& d)
    {
        if(_year < d._year)
        {
            return true;
        }
        else
        {
            if(_month < d._month)
            {
                return true;
            }
            else
            {
                if(_day < d._day)
                {
                    return true;
                }
            }
        }

        return false;
    }

    int operator-(Date& d)
    {
        Date small = *this;
        Date great = d;
        if(d < *this)
        {
            great = small;
            small = d;
        }

        int cnt = 1;
        while(small < great)
        {
            cnt++;
            small += 1;
        }

        return cnt;
    }
};



int main()
{
    Date d1, d2;
    cin >> d1._tuple >> d2._tuple;

    d1.GetYMD();
    d2.GetYMD();

    cout << d1 - d2;

    return 0;
}