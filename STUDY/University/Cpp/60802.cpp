#include<iostream>
using namespace std;

class Fraction
{
private:

    int fz, fm;

public:

    Fraction(int x = 0, int y = 1)
    :fz(x)
    ,fm(y)
    {}

    // Fraction(const Fraction&);

    Fraction operator+(Fraction f)
    {
        Fraction ret;
        ret.fm = f.fm * fm;
        ret.fz = f.fz * fm + fz * f.fm;
        return ret;
    }

    Fraction operator-(Fraction f)
    {
        Fraction ret;
        ret.fm = f.fm * fm;
        ret.fz = fz * f.fm - f.fz * fm;
        return ret;
    }

    Fraction operator*(Fraction f)
    {
        Fraction ret;
        ret.fm = f.fm * fm;
        ret.fz = fz * f.fz;
        return ret;
    }

    Fraction operator/(Fraction f)
    {
        Fraction ret;
        ret.fm = fm * f.fz;
        ret.fz = fz * f.fm;
        return ret;
    }

    // void set(int = 0, int = 1);

    void display()
    {
        printf("fraction=%d/%d\n", fz, fm);   
    }

};

int main()
{
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    Fraction f1(x1, y1), f2(x2, y2);

    Fraction f3 = f1 + f2;
    f3.display();
    f3 = f1 - f2;
    f3.display();
    f3 = f1 * f2;
    f3.display();
    f3 = f1 / f2;
    f3.display();
    return 0;
}