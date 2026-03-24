//高精度减法 P2142
//2026.3.13复盘
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 1e5 + 10;
int a[N], b[N], c[N];
int la, lb, lc;

bool cmp(string &x, string &y) //还是不太熟练，容易混淆
{
    if(x.size() < y.size()) return 1;
    else if(x.size() == y.size()) return x<y;
    return 0;
}

void sub(int a[], int b[], int c[])
{
    for(int i=0; i<lc; i++)
    {
        c[i] += a[i] - b[i];
        if(c[i] < 0)
        {
            c[i] += 10;
            c[i+1] -= 1;
        }
    }
    while(lc > 1 && c[lc-1] == 0) lc--;
}

int main()
{
    string x, y; cin >> x >> y;

    if(cmp(x, y))
    {
        swap(x, y);
        cout << '-';
    }

    la = x.size(), lb = y.size(), lc = max(la, lb);
    for(int i=0; i<la; i++) a[i] = x[la-i-1] - '0';
    for(int i=0; i<lb; i++) b[i] = y[lb-i-1] - '0';
    
    sub(a, b, c);

    for(int i=lc-1; i>=0; i--) cout << c[i];

    return 0;
}