#include<iostream>
using namespace std;

class CPoint
{
public:
    int x;
    int y;

    CPoint(int rx, int ry)
        :x(rx)
        ,y(ry)
    {}
};

class CCircle: public CPoint
{
public:
    int r;

    CCircle(int rx, int ry, int R)
        :CPoint(rx, ry)
        ,r(R)
    {}    

    double Area()
    {
        return 3.14 * r * r;
    }

    void Print_circle()
    {
        printf("Circle:(%d,%d),%d\n", x, y, r);
        double area = Area();
        printf("Area:%.2lf\n", area);
    }
};

class CCylinder: public CCircle
{
public:
    int h;

    CCylinder(int RX, int RY, int R, int H)
        :CCircle(RX, RY, R)
        ,h(H)
    {}


    double V()
    {
        return 3.14 * r * r * h;
    }

    void Print_cc()
    {
        printf("Cylinder:(%d,%d),%d,%d\n", x, y, r, h);
        double v = V();
        printf("Volume:%.2lf\n", v);
    }
};

int main()
{
    int rx, ry, r;
    cin >> rx >> ry >> r;
    int RX, RY, R, H;
    cin >> RX >> RY >> R >> H;

    CCircle c1(rx, ry, r);
    CCylinder c2(RX, RY, R, H);

    c1.Print_circle();
    c2.Print_cc();

    return 0;
}