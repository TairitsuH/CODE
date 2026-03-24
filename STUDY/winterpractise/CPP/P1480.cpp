#include<iostream>
using namespace std;

const int N = 1e6+10;
string x;
int la,lc,b;
int a[N],c[N];

void div(int a[], int b, int c[])
{
    long long t = 0;
    for(int i=la-1; i>=0; i--)
    {
        t = t * 10 + a[i];
        c[i] = t/b;
        t %= b;
    }

    while(lc>1 && c[lc-1]==0) lc--; 
}

int main()
{
    cin >> x >> b;

    la = x.size();
    for(int i=0; i<la; i++) a[i] = x[la-i-1]-'0';
    lc = la;

    div(a,b,c);
    for(int i=lc-1; i>=0; i--) cout << c[i];
    return 0;
}