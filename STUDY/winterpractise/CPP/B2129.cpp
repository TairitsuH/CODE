#include<iostream>
#include<cstdio>
using namespace std;

float a,b,c,m;

float MAX(float a, float b, float c)
{
    if(a<b)
    {
        float mid = a;
        a = b;
        b = mid;
    }
    if(b<c)
    {
        float mid = c;
        c = b;
        b = mid;
    }
    if(a<b)
    {
        float mid = a;
        a = b;
        b = mid;
    }
    return a;
}

int main()
{
    cin >> a >> b >> c;
    m = MAX(a,b,c) / (MAX(a+b,b,c)*MAX(a,b,b+c));
    printf("%.3f",m);
    return 0;
}