#include<iostream>
#include<cstring>
using namespace std;

class CDate
{
public:
        int year, month, day;
        CDate(int y, int m, int d);
        bool isLeapYear();
        int getYear();
        int getMonth();
        int getDay();
        int getDayofYear();

        // 日期+=天数
        CDate& operator += (int _day)
        {
            day += _day;
            while(day > GetMonthDay(year, month))
            {
                day -= GetMonthDay(year, month);
                month++;

                if(month == 13)
                {
                    year++;
                    month = 1;
                }
            }

            return *this;
        }

        // >运算符重载
        bool operator < (const CDate& d)
        {
            if(year < d.year)
            {
                return true;
            }

            if(year == d.year && month < d.month)
            {
                return true;
            }

            if(month == d.month && day < d.day)
            {
                return true;
            }

            return false;
        }

        // ==运算符重载
        bool operator != (const CDate& d)
        {
            if(year == d.year && month == d.month && day == d.day)
            {
                return false;
            }

            return true;
        }

    // 日期-日期 返回天数
    int operator - (const CDate& d)
    {
        int flag = 1;
        CDate big = *this;
        CDate small = d;

        if(*this < d)
        {
            big = d;
            small = *this;
            flag = -1;
        }

        int Nday = 0;
        while(small != big)
        {
            small += 1;
            Nday += 1;
        }

        return Nday * flag;
    }

    int GetMonthDay(int year, int month) const
    {
        static int MonthDay[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if(month == 2 && ((year%4==0 && year%100!=0) ||(year%400==0)))
        {
            return 29;
        }
        return MonthDay[month];
    }
};
 
CDate::CDate(int y, int m, int d)
{ 
    year = y, month = m,day = d;
}
 
bool CDate::isLeapYear()
{ 
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0; 
}
 
int CDate::getYear()
{ 
    return year;
}
 
int CDate::getMonth() 
{ 
    return month;
}
 
int CDate::getDay() 
{ 
    return day;
}
 
int CDate::getDayofYear()
{
    int i, sum = day;
    int a[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isLeapYear())
    {
        a[2]++;
    }
    // 求日期的天数
    for (i = 0; i < month; i++)
    {
        sum += a[i];
    }
    return sum;
}



class Software
{
private:
    char* _name;
    char _type;
    char _intype;

public:
    Software(const char* name, char type, char intype):
    _name(new char[35]),
    _type(type),
    _intype(intype)
    {
        strcpy(_name, name);
    }

    Software(const Software& rev)
        : _name(new char[35])
        , _type('B')
        , _intype('H')
    {
        strcpy(_name, rev._name);
    }

    ~Software() {
        delete[] _name;
    }

    Software& operator=(const Software& other)
    {
        if (this != &other)
        {
            delete[] _name;
            _name = new char[35];
            strcpy(_name, other._name);
            _type = 'B';      // 固定为 B
            _intype = 'H';    // 固定为 H
        }
        return *this;
    }

    void Print()
    {
        cout << "name:" << _name << endl;
        if(_type == 'O')
        {
            cout << "type:original" << endl;
        }
        else if(_type == 'T')
        {
            cout << "type:trial" << endl;           
        }
        else
        {
            cout << "type:backup" << endl;           
        }
        if(_intype == 'D')
        {
            cout << "media:optical disk"<< endl;
        }
        else if(_intype == 'U')
        {
            cout << "media:USB disk"<< endl;
        }
        else
        {
            cout << "media:hard disk"<< endl;
        }
    }
};

int main()
{
    int t;
    cin >> t;

    CDate standardDate(2015, 4, 7);

    while(t--)
    {
        char name[35];
        char type;
        char intype;
        cin >> name >> type >> intype;

        Software ware(name, type, intype);

        int year, month, day;
        cin >> year >> month >> day;
        CDate cmpDate(year, month, day);

        ware.Print();

        if(cmpDate.year == 0 && cmpDate.month == 0 && cmpDate.day == 0)
        {
            cout << "this software has unlimited use" << endl;
        }
        else
        {
            int gap = cmpDate - standardDate;
            if(gap < 0)
            {
                cout << "this software has expired" << endl;
            }
            else
            {
                cout << "this software is going to be expired in " << gap << " days\n";
            }
        }
        cout << endl;

        //拷贝
        Software warecpy = ware;
        warecpy.Print();

        if(cmpDate.year == 0 && cmpDate.month == 0 && cmpDate.day == 0)
        {
            cout << "this software has unlimited use" << endl << endl;
            continue;
        }

        int gap = cmpDate - standardDate;
        if(gap < 0)
        {
            cout << "this software has expired" << endl;
        }
        else
        {
            cout << "this software is going to be expired in " << gap << " days\n";
        }

        cout << endl;
    }
    return 0;
}