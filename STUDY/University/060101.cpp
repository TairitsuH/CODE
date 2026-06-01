#include<iostream>
using namespace std;

class Shape
{
public:
    virtual double area() 
    {
        return 0;
    }
};

class Circle: public Shape
{
    double r;
public:
    Circle(double r1)
    :r(r1)
    {}

    double area()
    {
        double S = 3.1415926 * r * r;
        return S;
    }
};

class Square: public Shape
{
    double a;

public:
    Square(double a1)
    :a(a1)
    {}

    virtual double area()
    {
        return a * a;
    }
};

class Rectangle: public Shape
{
double l;
double w;

public:
    Rectangle(double l1, double w1)
    :l(l1)
    ,w(w1)
    {}

    virtual double area()
    {
        return l * w;
    }
};


int main()
{
    int t; cin >> t;
    while(t--)
    {
        double r, a, l, w;
        cin >> r >> a >> l >> w;

        Shape* p1 = new Circle(r);
        Shape* p2 = new Square(a);
        Shape* p3 = new Rectangle(l, w);

        printf("%.2lf\n%.2lf\n%.2lf\n", p1->area(), p2->area(), p3->area());
    }
    return 0;
}