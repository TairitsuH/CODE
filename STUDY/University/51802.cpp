#include<iostream>
#include<math.h>
using namespace std;

class C2D
{
public:
    int x;
    int y;

    C2D(int x0, int y0)
        :x(x0)
        ,y(y0)
    {}

    double getDistance()
    {
        return sqrt(x*x + y*y);
    }
};

class C3D: public C2D
{
public:
    int z;

    C3D(int x1, int y1, int z1)
        :C2D(x1, y1)
        ,z(z1)
    {}

    double getDistance()
    {
        return sqrt(x*x + y*y + z*z);
    }
};

int main()
{
    int x0, y0;
    int x1, y1, z1;
    int x2, y2, z2;
    cin >> x0 >> y0;
    cin >> x1 >> y1 >> z1;
    cin >> x2 >> y2 >> z2;

    C2D c1(x0, y0);
    C3D c2(x1, y1, z1);
    C3D c3(x2, y2, z2);

    cout << c1.getDistance() << endl;
    cout << c2.getDistance() << endl;
    cout << c3.getDistance() << endl;

    C2D c4(x2, y2);
    cout << c4.getDistance() << endl;
    return 0;
}