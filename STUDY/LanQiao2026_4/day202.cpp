// //高精度除法
// //2026.3.13
// #include<iostream>
// #include<cstring>
// using namespace std;

// const int N = 1e5 + 10;
// int a[N], c[N];
// int la, lc;
// int b;

// void sub(int a[], int b, int c[])
// {
//     long long t = 0; //余数也可能会超出int范围！
//     for(int i=la-1; i>=0; i--)
//     {
//         t = t * 10 + a[i];
//         c[i] += t / b;
//         t %= b;
//     }

//     while(lc>1 && c[lc-1]==0) lc--;
// }

// int main()
// {
//     string x; cin >> x >> b;

//     la = x.size(), lc = la;
//     for(int i=0; i<la; i++) a[i] = x[la-i-1] -'0';

//     sub(a, b, c);

//     for(int i=lc-1; i>=0; i--) cout << c[i];
//     return 0;
// }


// //2026.3.14 复盘
// #include<iostream>
// #include<cstring>
// using namespace std;

// const int N = 1e5 + 10;
// int a[N], c[N];
// int la, lc;
// typedef long long LL;
// LL b;

// void sub(int a[], LL b, int c[])
// {
//     LL t = 0;
//     for(int i=la-1; i>=0; i--) //倒序！！！倒序！！！！
//     {
//         //过程还是很乱，要在理解的基础上记忆！细细推导一遍！
//         t = t * 10 + a[i];
//         c[i] += t / b;
//         t %= b;
//     }

//     while(lc > 1 && c[lc-1] == 0) lc--;
// }

// int main()
// {
//     string x; cin >> x >> b;
    
//     la = x.size(), lc = la;
//     for(int i=0; i<la; i++) a[i] = x[la-i-1] - '0';

//     sub(a, b, c);

//     for(int i=lc-1; i>=0; i--) cout << c[i];

//     return 0;
// }

//2026.3.15 复盘
#include<iostream>
#include<cstring>
using namespace std;

const int N = 1e5 + 10;
int a[N], c[N];
int la, lc;
long long b;

void sub(int a[], long long b, int c[])
{
    long long t = 0;
    for(int i=lc-1; i>=0; i--)
    {
        t = t * 10 + a[i];
        c[i] = t / b;
        t %= b;
    }

    while(lc > 1 && c[lc-1] == 0) lc--;
}

int main()
{
    string x; cin >> x >> b;

    la = x.size(), lc = la;
    for(int i=0; i<la; i++) a[i] = x[la-i-1] -'0';

    sub(a, b, c);

    for(int i=lc-1; i>=0; i--) cout << c[i];
    return 0;
}
//注意数据范围！！b和t用long long存更稳妥。