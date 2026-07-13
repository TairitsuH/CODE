#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Date
{
public:
    int year;
    int month;
    int day;

    Date(int y, int m, int d)
    :year(y)
    ,month(m)
    ,day(d)
    {}
};

class Time
{
public:
    int hour;
    int minute;
    int second;

    Time(int h, int min, int s)
    :hour(h)
    ,minute(min)
    ,second(s)
    {}

};

class Work: public Date, public Time
{
public:
    int id;

    Work(int i,int y,int m,int d,int h,int min,int s)
    :Date(y, m, d)
    ,Time(h, min, s)
    ,id(i)
    {}

    friend bool before(const Work& w1,const Work& w2);
};

bool before(const Work& w1,const Work& w2)
{
    if(w1.year < w2.year)
    {
        return true;
    }
    else if(w1.year == w2.year)
    {
        if(w1.month < w2.month)
        {
            return true;
        }
        else if(w1.month == w2.month)
        {
            if(w1.day < w2.day)
            {
                return true;
            }
            else if(w1.day == w2.day)
            {
                if(w1.hour < w2.hour)
                {
                    return true;
                }
                else if(w1.hour == w2.hour)
                {
                    if(w1.minute < w2.minute)
                    {
                        return true;
                    }
                    if(w1.minute == w2.minute)
                    {
                        if(w1.second < w2.second)
                        {
                            return true;
                        }
                    }
                }
            }
        }
    }

    return false;
}

int main()
{
    vector<Work> vv;
    int i;
    while(cin >> i && i != 0)
    {
        int y, m, d, h, min, s;
        cin >> y >> m >> d >> h >> min >> s;
        Work w(i, y, m, d, h, min, s);

        vv.push_back(w);
    }

    sort(vv.begin(), vv.end(), before);

    cout << "The urgent Work is No." << vv[0].id << ": ";
    printf("%04d/%02d/%02d %02d:%02d:%02d", vv[0].year, vv[0].month, vv[0].day, vv[0].hour, vv[0].minute, vv[0].second);
    return 0;
}