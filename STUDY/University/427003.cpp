#include<iostream>
using namespace std;

class Date
{
public:
    int year;
    int month;
    int day;
    int h;
    int m;
    int s;

    Date(int y, int mo, int d, int h1, int m1, int s1)
    {
        year = y;
        month = mo;
        day = d;
        h = h1;
        m = m1;
        s = s1;
    }

    void print_date()
    {
        cout << year << '-';
        if(month < 10) cout << '0';
        cout << month << '-';
        if(day < 10) cout << '0';
        cout << day << " ";

        if(h < 10) cout << '0';
        cout << h << ':';
        if(m < 10) cout << '0';
        cout << m << ':';
        if(s < 10) cout << '0';
        cout << s << endl;
    }

};

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int y, mo, d;
        int  h, m, s;
        cin >> y >> mo >> d;
        cin >> h >> m >> s;
        Date date(y, mo, d, h, m, s);

        date.print_date();
    }
    return 0;
}