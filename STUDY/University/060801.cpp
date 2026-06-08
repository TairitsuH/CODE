#include<iostream>
using namespace std;

class Complex
{
private:
    float real, image;
public:
    Complex(float x = 0, float y = 0)
    :real(x)
    ,image(y)
    {}

    friend Complex operator+(Complex&, Complex&);
    friend Complex operator-(Complex&, Complex&);
    friend Complex operator*(Complex&, Complex&);

    void show()
    {
        printf("Real=%.0f Image=%.0f\n", real, image);
    }
};

Complex operator+(Complex& c1, Complex& c2)
{
    Complex ret;
    ret.image = c1.image + c2.image;
    ret.real = c1.real + c2.real;
    return ret;
}

Complex operator-(Complex& c1, Complex& c2)
{
    Complex ret;
    ret.image = c1.image - c2.image;
    ret.real = c1.real - c2.real;
    return ret;
}

Complex operator*(Complex& c1, Complex& c2)
{
    Complex ret;
    ret.real = c1.real * c2.real - c1.image * c2.image ;
    ret.image = c2.real * c1.image + c1.real * c2.image;
    return ret;
}

int main()
{
    float r1, i1, r2, i2;
    cin >> r1 >> i1 >> r2 >> i2;
    Complex c1(r1, i1);
    Complex c2(r2, i2);

    Complex c3 = c1 + c2;
    c3.show();
    c3 = c1 - c2;
    c3.show();
    c3 = c1 * c2;
    c3.show();
    return 0;
}