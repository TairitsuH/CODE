#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

double x,n;

double f(double x, double n)
{
    if(n == 1)
        return sqrt(1 + x);
    double out = sqrt(n + f(x, n-1));
    return out;
}

int main()
{
    cin >> x >> n;
    double out = f(x, n);

    printf("%.2lf",out);
    return 0;
}