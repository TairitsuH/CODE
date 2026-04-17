#include"Date.h"

// 全缺省的构造函数(参数只能给在声明中！)
Date::Date(int year, int month, int day)
{
    _year = year;
    _month = month;
    _day = day;

    if(!CheckDate())
    {
        cout << "输入的日期非法！" << endl;
    }
}

// 拷贝构造函数
// d2(d1)
Date::Date(const Date& d)
{
    _year = d._year;
    _month = d._month;
    _day = d._day;
}

// 析构函数
Date::~Date()
{
    _year = 0;
    _month = 0;
    _day = 0;
}

// 赋值运算符重载(如果开辟了资源需要先释放)
// d2 = d3 -> d2.operator=(&d2, d3)
Date& Date::operator=(const Date& d)
{
    _year = d._year;
    _month = d._month;
    _day = d._day;
    return *this;
}

//判断日期合法
bool Date::CheckDate() const
{
    if(_month < 1 || _month > 12)
    {
        return false;
    }

    if(_day < 1 || _day > GetMonthDay(_year, _month))
    {
        return false;
    }

    return true;
}

//打印日期
void Date::Print() const
{
    if(!CheckDate())
    {
        cout << "日期非法，无法打印！" << endl;
        return;
    }

    cout << _year << "年" << _month << "月" << _day << "日" << endl;
}

// 日期+=天数
Date& Date::operator += (int day)
{
    if(!CheckDate())
    {
        cout << "日期非法，无法运算！" << endl;
        return *this;
    }

    if(day < 0)
    {
        return *this -= (-day);
    }

    _day += day;
    while(_day > GetMonthDay(_year, _month))
    {
        _day -= GetMonthDay(_year, _month);
        _month++;

        if(_month == 13)
        {
            _year++;
            _month = 1;
        }
    }

    return *this;
}

// 日期-=天数
Date& Date::operator -= (int day)
{
    if(!CheckDate())
    {
        cout << "日期非法，无法运算！" << endl;
        return *this;
    }

    if(day < 0)
    {
        return *this += (-day);
    }

    _day -= day;
    while(_day <= 0)
    {
        _day += GetMonthDay(_year, _month);
        _month--;

        if(_month == 0)
        {
            _year--;
            _month = 12;
        }
    }

    return *this;
}

// 日期+天数
Date Date::operator + (int day)
{
    Date tmp = *this;
    tmp += day;
    return tmp;
}

// 日期-天数
Date Date::operator - (int day)
{
    Date tmp = *this;
    tmp -= day;
    return tmp;
}

// 前置++
Date& Date::operator ++ ()
{
    *this += 1;
    return *this;
}

// 后置++
Date Date::operator ++ (int)
{
    Date tmp = *this;
    *this += 1;
    return tmp;
}

// 前置--
Date& Date::operator -- ()
{
    *this -= 1;
    return *this;
}

// 后置--
Date Date::operator -- (int)
{
    Date tmp = *this;
    *this -= 1;
    return tmp;
}

// >运算符重载
bool Date::operator > (const Date& d)
{
    if(_year > d._year)
    {
        return true;
    }

    if(_year == d._year && _month > d._month)
    {
        return true;
    }

    if(_month == d._month && _day > d._day)
    {
        return true;
    }

    return false;
}

// ==运算符重载
bool Date::operator == (const Date& d)
{
    if(_year == d._year && _month == d._month && _day == d._day)
    {
        return true;
    }

    return false;
}

// >=运算符重载
bool Date::operator >= (const Date& d)
{
    return (!(*this < d));
}

// <运算符重载
bool Date::operator < (const Date& d)
{
    return (!((*this > d) || (*this == d)));
}

// <=运算符重载
bool Date::operator <= (const Date& d)
{
    return (!(*this > d));
}

// !=运算符重载
bool Date::operator != (const Date& d)
{
    return (!(*this == d));
}

// 日期-日期 返回天数
int Date::operator - (const Date& d)
{
    int flag = 1;
    Date big = *this;
    Date small = d;

    if(*this < d)
    {
        big = d;
        small = *this;
        flag = -1;
    }

    int Nday = 0;
    while(small != big)
    {
        small++;
        Nday++;
    }

    return Nday * flag;
}

//输入输出（全局）
ostream& operator << (ostream& out, const Date& d)
{
    out << d._year << "年" << d._month << "月" << d._day << "日";
    return out;
}

istream& operator >> (istream& in, Date& d)
{
    cout << "请依次输入年月日：" << endl;
    while(1)
    {
        in >> d._year >> d._month >> d._day;
        if(!d.CheckDate())
        {
            cout << "输入日期" << d << "非法，请重新输入！" << endl;
        }
        else
        {
            break;
        }
    }

    return in;
}