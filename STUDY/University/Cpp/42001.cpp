#include<iostream>
#include<cmath>
#include <iomanip>
using namespace std;

class Equation
{
private:

    double _a;
    double _b;
    double _c;

public:
    Equation(double a = 1.0, double b = 1.0, double c = 0)
    {
        _a = a;
        _b = b;
        _c = c;
    }

    void getRoot()
    {
        double delta = _b*_b - 4*_a*_c;
        if(delta > 0)
        {
            double ret1 = (-_b + sqrt(delta)) / 2 / _a;
            double ret2 = (-_b - sqrt(delta)) / 2 / _a;
            printf("x1=%.2lf x2=%.2lf\n", ret1, ret2);
        }
        else if(delta == 0)
        {
            double ret = (-_b + delta) / 2 / _a;
            printf("x1=x2=%.2lf\n", ret);

        }
        else
        {
            double a = -_b / 2 / _a;
            double b = sqrt(-delta) / 2 / _a;
            printf("x1=%.2lf+%.2lfi x2=%.2lf-%.2lfi\n", a, b, a, b);
        }
    }

};

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        double a, b, c;
        cin >> a >> b >> c;
        Equation ret(a, b, c);

        ret.getRoot();
    }
    return 0;
}