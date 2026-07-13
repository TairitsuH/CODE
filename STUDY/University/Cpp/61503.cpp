#include<iostream>
using namespace std;

class Clock
{
    int h;
    int m;
    int s;

public:
    Clock(int h1, int m1, int s1)
    :h(h1)
    ,m(m1)
    ,s(s1)
    {}

    Clock& operator+(int x)
    {
        s += x;

        m += s / 60;
        s -= s / 60 * 60;

        h += m / 60;
        m -= m / 60 * 60;
        
        if(h / 12 > 0)
        {
            h -= 12;
        }

        return *this;
    }

    Clock& operator-(int x)
    {

        s -= x;
        
        while(s < 0)
        {
            s += 60;
            m--;
        }
        while(m < 0)
        {
            m += 60;
            h--;
        }
        if(h < 0)
        {
            h += 12;
        }

        return *this;
    }

    friend ostream& operator<<(ostream& out, Clock cl);


};

ostream& operator<<(ostream& out, Clock cl)
{
    out << cl.h << ":" << cl.m << ":" << cl.s << endl;
    return out;
}

int main()
{
    int h, m, s; cin >> h >> m >> s;
    Clock cl(h, m, s);

    int t; cin >> t;

    while(t--)
    {
        int x; cin >> x;
        if(x > 0)
        {
            cl = cl + x;
        }
        if(x < 0)
        {
            x = -x;
            cl = cl - x;
        }

        cout << cl;
    }
    return 0;
}