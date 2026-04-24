// https://www.nowcoder.com/practice/769d45d455fe40b385ba32f97e7bcded?tpId=37&&tqId=21296&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
#include<iostream>
using namespace std;

class Date
{
public:
    int _year;
    int _month;
    int _day;

    int GetMonthDay(int y, int m)
    {
        static int MonthDay[13] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if(m == 2 && ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)))
        {
            return 29;
        }
        return MonthDay[m];
    }

    int CalculateDay()
    {
        int sum = 0;
        sum += _day;

        while(--_month > 0)
        {
            sum += GetMonthDay(_year, _month);
        }

        return sum;
    }
};

int main()
{
    Date date;
    cin >> date._year >> date._month >> date._day;
    cout << date.CalculateDay() << endl;
    return 0;
}