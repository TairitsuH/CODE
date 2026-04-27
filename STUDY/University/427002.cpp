#include<iostream>
using namespace std;

class Complex
{
private:
	double real; // 实部
	double imag; // 虚部

public:
    Complex()
    {
        real = 0;
        imag = 0;
    }
	Complex(double r, double i)
    {
        real = r;
        imag = i;
    }
	// 友元函数，复数c1 + c2(二参数对象相加)
	friend Complex addCom(const Complex& c1, const Complex& c2);
	// 友元函数，输出类对象c的有关数据(c为参数对象)
	friend void outCom(const Complex& c);
};

Complex addCom(const Complex& c1, const Complex& c2)
{
    double r = c1.real + c2.real;
    double i = c1.imag + c2.imag;
    Complex ret(r, i);
    return ret;
}

void outCom(const Complex& c)
{
    cout << '(' << c.real << "," << c.imag  << ')' << endl;
}


int main()
{
    int a, b;
    cin >> a >> b;
    Complex c1(a, b);

    int t;
    cin >> t;
    while(t--)
    {
        char symbol;
        cin >> symbol;
        double flag = -1;
        if(symbol == '+')
        {
            flag *= -1;
        }

        int a, b;
        cin >> a >> b;
        Complex c2(flag*a, flag*b);

        Complex c3 = addCom(c1, c2);
        outCom(c3);
        c1 = c3;
    }
    return 0;
}