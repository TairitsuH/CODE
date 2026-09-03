#include <iostream>
#include <math.h>
using namespace std;

class Point
{
    double x, y;

public:
    Point()
    {
        x = 0;
        y = 0;
        cout << "Constructor." << endl;
    }

    Point(double x_value, double y_value)
        : x(x_value), y(y_value)
    {
        cout << "Constructor." << endl;
    }

    ~Point() // 析构函数
    {
        x = 0;
        y = 0;
        cout << "Distructor." << endl;
    }

    Point(const Point &p)
    {
        x = p.x;
        y = p.y;
        cout << "Constructor." << endl;
    }

    double getX() // 返回x的值
    {
        return x;
    }

    double getY() // 返回y的值
    {
        return y;
    }

    void setXY(double x1, double y1)
    {
        x = x1;
        y = y1;
    }

    void setX(double x_value) // 设置x的值
    {
        x = x_value;
    }
    void setY(double y_value) // 设置y的值
    {
        y = y_value;
    }

    double getDisTo(const Point &p) // 计算当前点到参数点p的距离
    {
        double len = sqrt((x-p.x)*(x-p.x) + (y-p.y)*(y-p.y));
        return len;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Point *point = new Point[n];
        for (int i = 0; i < n; i++)
        {
            double cx, cy;
            cin >> cx >> cy;
            point[i].setXY(cx, cy);
        }

        double maxlen = 0;
        int a = 0, b = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                double len = point[i].getDisTo(point[j]);
                if (maxlen < len)
                {
                    a = i, b = j;
                    maxlen = len;
                }
            }
        }

        printf("The longeset distance is %.2lf,between p[%d] and p[%d].\n", maxlen, a, b);

        delete[] point;
    }
    return 0;
}