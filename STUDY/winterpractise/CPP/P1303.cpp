// #include<iostream>
// #include<string>
// using namespace std;

// string x, y;
// const int N = 1e6+10;
// int a[N],b[N],c[N];
// int la,lb,lc;

// void mul(int a[], int b[], int c[])
// {
//     for(int i=0; i<la; i++) //计算乘法
//     {
//         for(int j=0; j<lb; j++)
//         {
//             c[i+j] += a[i]*b[j];
//         }
//     }

//     //处理进位
//     for(int i=0; i<lc; i++)
//     {
//         c[i+1] += c[i]/10;
//         c[i] %= 10;
//     }

//     while(lc > 1 && c[lc-1]==0) lc--;
// }

// int main()
// {
//     cin >> x >> y;

//     la = x.size(); lb = y.size(); lc = la + lb;
//     for(int i=0; i<la; i++) a[i] = x[la-i-1]-'0';
//     for(int i=0; i<lb; i++) b[i] = y[lb-i-1]-'0';

//     mul(a,b,c);

//     for(int i=lc-1; i>=0; i--) cout << c[i];

//     return 0;
// }

#include<iostream>
using namespace std;

const int N = 1e5;
string x,y;
int la,lb,lc;
int a[N], b[N], c[N];

void mul(int a[], int b[], int c[])
{
    for(int i=0; i<la; i++)
    {
        for(int j=0; j<lb; j++)
        {
            c[i+j] += a[i] * b[j];
        }
    }

    for(int i=0; i<lc; i++)
    {
        c[i+1] += c[i] / 10;
        c[i] %= 10;
    }

    while(c[lc-1]==0 && lc>1) lc--;
}

int main()
{
    cin >> x >> y;

    la = x.size(), lb = y.size(), lc = la + lb;
    for(int i=0; i<la; i++) a[i] = x[la-i-1] -'0';
    for(int i=0; i<lb; i++) b[i] = y[lb-i-1] -'0';

    mul(a, b, c);

    for(int i=lc-1; i>=0; i--) cout << c[i];
    return 0;
}