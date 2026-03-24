#include<iostream>
using namespace std;

struct xy
{
    int a,b,c;

    void Mul2()
    {
        a *= 2;
        b *= 2;
        c *= 2;
    }

    void Print()
    {
        cout << a << " " << b << " "<< c << endl;
    }

    xy& operator -= (const xy& Y)
    {
        a -= Y.a;
        b -= Y.b;
        c -= Y.c;
        return *this;
    }

}X, Y, Z;

bool operator > (const xy& X, const xy& Y)
{
    return X.a > Y.a;
}

int operator * (const xy& X, const xy& Y)
{
    return X.b * Y.b;
}

xy operator + (const xy& X, const xy& Y)
{
    xy Z;
    Z.a = X.a + Y.a;
    Z.b = X.b + Y.b;
    Z.c = X.c + Y.c;
    return Z;
}


int main()
{
    cin >> X.a >> X.b >> X.c;
    cin >> Y.a >> Y.b >> Y.c;
    X.Mul2();
    Y.Mul2();
    X.Print();
    if(X > Y) cout << "X is bigger" << endl;
    else cout << "X is not bigger"<< endl;
    cout << X * Y << endl;
    xy Z = X + Y;
    Z.Print();
    X -= Y;
    X.Print();

    return 0;
}