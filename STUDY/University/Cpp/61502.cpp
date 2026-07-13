#include<iostream>
using namespace std;

class CMoney
{
    int y;
    int j;
    int c;

public:
    CMoney(int y1, int j1, int c1)
    :y(y1)
    ,j(j1)
    ,c(c1)
    {}

    CMoney& operator+(CMoney& cm)
    {
        y += cm.y;
        j += cm.j;
        c += cm.c;

        j += c / 10;
        c -= c / 10 * 10;
        y += j / 10;
        j -= j / 10 * 10;

        return *this;
    }

    CMoney& operator-(CMoney& cm)
    {
        y -= cm.y;
        j -= cm.j;
        c -= cm.c;

        while(c < 0)
        {
            c += 10;
            j -= 1;
        }

        while(j < 0)
        {
            j += 10;
            y -= 1;
        }

        return *this;
    }

    friend istream& operator >> (istream& in, CMoney& cm);
    friend ostream& operator<<(ostream& out, CMoney& cm);
};

istream& operator >> (istream& in, CMoney& cm)
{
    in >> cm.y >> cm.j >> cm.c;
    return in;
}

ostream& operator<<(ostream& out, CMoney& cm)
{
    out << cm.y << "元" << cm.j << "角" << cm.c << "分" << endl;
    return out;
}



int main()
{
    int t; cin >> t;
    while(t--)
    {
        int y, j, c; cin >> y >> j >> c;
        CMoney cm(y, j, c);

        string op;
        while(cin >> op && op != "stop")
        {
            cin >> y >> j >> c;
            CMoney cm1(y, j, c);

            if(op == "add")
            {
                cm = cm + cm1;
            }
            else
            {
                cm = cm - cm1;
            }
        }

        cout << cm;
    }
    return 0;
}