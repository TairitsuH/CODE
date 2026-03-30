#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

class Point
{
private:
    double x, y;
public:
    void setPoint(double a, double b) { x = a; y = b; }
    double getX() { return x; }
    double getY() { return y; }
};

class Circle
{
private:
    double x, y, r;
public:
    void setCenter(double a, double b) { x = a; y = b; }
    void setRadius(double a) { r = a; }
    double getArea() { return 3.14 * r * r; }
    double getLength() { return 2 * 3.14 * r; }
    bool contain(Point p) {
        double d = sqrt((x - p.getX())*(x - p.getX()) + (y - p.getY())*(y - p.getY()));
        return d <= r;
    }
};


int main()
{
    Circle c;
    Point p;
    
    double cx, cy, cr, px, py;
    cin >> cx >> cy >> cr >> px >> py;
    
    c.setCenter(cx, cy);
    c.setRadius(cr);
    p.setPoint(px, py);
    
    cout << fixed << setprecision(2);
    cout << c.getArea() << " " << c.getLength() << endl;
    cout << (c.contain(p) ? "yes" : "no") << endl;
    
    return 0;
}