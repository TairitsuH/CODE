//高精度加法 P1601
//2026.3.13复盘
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 1e5 + 10;
int a[N], b[N], c[N];
int la, lb, lc;

void add(int a[], int b[], int c[])
{
    for(int i=0; i<=lc; i++)
    {
        c[i] += a[i] + b[i];
        c[i+1] += c[i] / 10;
        c[i] %= 10;
    }

    if(c[lc]) lc++;
}

int main()
{
    string x, y; cin >> x >> y;

    la = x.size(), lb = y.size(), lc = max(la, lb);
    for(int i=0; i<la; i++) a[i] = x[la - i - 1] - '0'; //手快写成i<=la了！一定要注意是否越界！
    for(int i=0; i<lb; i++) b[i] = y[lb - i - 1] - '0';

    add(a, b, c);

    for(int i = lc-1; i>=0; i--) cout << c[i];
    return 0;

}