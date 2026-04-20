#include<iostream>
using namespace std;

class Date
{

    public:
    int GetMonthDay(int y, int m)
    {
        static int MonthDay[13] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if(m == 2 && ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)))
        {
            return 29;
        }
        return MonthDay[m];
    }
};

int main()
{

    return 0;
}