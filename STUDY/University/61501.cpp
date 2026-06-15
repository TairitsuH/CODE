#include<iostream>
using namespace std;

class point
{
public:
    int x;
    int y;
    int z;

    point(int x1=0, int y1=0, int z1=0)
    :x(x1)
    ,y(y1)
    ,z(z1)
    {}

    friend point& operator++(point& a);
    friend point operator++(point& a, int);
    friend point& operator --(point& a);
    friend point operator --(point& a, int);

    void show()
    {
        cout<<"x="<<x<<' '<<"y="<<y<<' '<<"z="<<z<<endl;
    }

};

point& operator++(point& a)
{
    a.x++;
    a.y++;
    a.z++;

    return a;
}

point operator++(point& a, int)
{
    point tmp = a;
    a.x++;
    a.y++;
    a.z++;

    return tmp;
}

point& operator--(point& a)
{
    a.x--;
    a.y--;
    a.z--;

    return a;
}
point operator --(point& a, int)
{
    point tmp = a;
    a.x--;
    a.y--;
    a.z--;

    return tmp;
}

int main()
{
    int x, y, z; cin >> x >> y >> z;
    point p1(x, y, z);

    p1++;
    p1.show();
    p1--;
    point p2 = p1++;
    p2.show();
    p1--;
    (++p1).show();
    p1.show();
    p1--;
    p1--;
    p1.show();
    p1++;
    p1.show();
    (--p1).show();
    p1.show();

    return 0;
}