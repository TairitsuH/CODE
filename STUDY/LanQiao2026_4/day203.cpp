// //铺地毯
// //2026.3.13
// #include<iostream>
// using namespace std;

// const int N = 1e5 + 10;
// int a[N], b[N], g[N], k[N];
// int n;

// int find(int x, int y)
// {
//     for(int i=n; i>0; i--)
//     {
//         if(x >= a[i] && y >= b[i] && x <= a[i]+g[i] && y <= b[i]+k[i])
//         {
//             return i;
//         }
//     }
//     return -1;
// }

// int main()
// {
//     cin >> n;
//     for(int i=1; i<=n; i++)
//     {
//         cin >> a[i] >> b[i] >> g[i] >> k[i];
//     }
//     int x, y; cin >> x >> y;

//     cout << find(x, y) << endl;
//     return 0;
// }

//2026.3.14 复盘
#include<iostream>
using namespace std;

const int N = 1e5 + 10;
int a[N], b[N], g[N], k[N];

int main()
{
    int n; cin >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i] >> b[i] >> g[i] >> k[i];
    }

    int x, y; cin >> x >> y;

    for(int i=n; i>0; i--)
    {
        if(x>=a[i] && x<=a[i]+g[i] && y>=b[i] && y<=b[i]+k[i])
        {
            cout << i; return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}