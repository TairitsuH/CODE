#include<iostream>
#include<cstdio>
using namespace std;

double x,n;
double f(double x, double n)
{
    if(n == 1)
        return x/(1+x);

    double out = x/(n + f(x, n-1));
    return out;
        
}

int main()
{
    cin >> x >> n;
    double out = f(x, n);
    printf("%.2lf",out);
    return 0;
}