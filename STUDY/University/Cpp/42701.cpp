#include<iostream>
#include<math.h>
using namespace std;

class Point
{
private:
    double x, y;
public:
    Point(double xx, double yy) // 构造函数
    {
        x = xx;
        y = yy;
    }

    friend double Distance(Point &a, Point &b);
};


double Distance(Point &a, Point &b)
{
    double dis;
    dis = sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
    return dis;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        double x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        Point p1(x1, y1);
        Point p2(x2, y2);

        cout << (int)Distance(p1, p2) << endl;

    }
}