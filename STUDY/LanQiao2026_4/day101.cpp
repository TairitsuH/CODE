//多项式输出 P1067
// 2026.3.13 复盘
#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int n; cin >> n;
    for(int i=n; i>=0; i--)
    {
        int a; cin >> a;
        if(a == 0) continue;

        if(a > 0 && i != n) cout << '+';
        else if(a < 0) cout << '-';

        a = abs(a);
        if((a == 1 && i == 0) || (a != 0 && a != 1)) cout << a;

        if(i == 1) cout << "x";
        else if(i != 1 && i != 0) cout << "x^" << i;

    }
    return 0;
}