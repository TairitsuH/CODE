#include<iostream>
using namespace std;

class cul
{
protected:
    int value;

public:
    void increment()
    {}
};

class loopcul: public cul
{
private:
    int minval;
    int maxval;

public:
    void increment()
    {
        if(value >= minval && value <= maxval)
        {
            value++;
        }
    }    

};

class Cl
{
private:
    int _h;
    int _m;
    int _s;

public:
    Cl(int h, int m, int s)
        :_h(h)
        ,_m(m)
        ,_s(s)
    {}

    void Time(int ss)
    {
        _s += ss;
        while(_s >= 60)
        {
            _s -= 60;
            _m += 1;
        }
        while(_m >= 60)
        {
            _m -= 60;
            _h += 1;
        }
        while(_h >= 24)
        {
            _h -= 24;
        }
    }

    void print_time()
    {
        printf("%d:%d:%d\n", _h, _m, _s);
    }
};

int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        int h, m, s, ss;
        cin >> h >> m >> s >> ss;

        Cl c1(h, m, s);

        c1.Time(ss);
        c1.print_time();
    }
    return 0;
}