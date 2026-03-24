// //前缀和（区间和）
// //2026.3.13
// #include<iostream>
// using namespace std;

// const int N = 1e6 + 10;
// long long a[N], f[N];

// int main()
// {
//     int n, m;
//     cin >> n;
    
//     for(int i=1; i<=n; i++)
//     {
//         cin >> a[i];
//     }

//     for(int i=1; i<=n; i++)
//     {
//         f[i] = f[i-1] + a[i];
//     }

//     cin >> m;
//     while(m--)
//     {
//         int l, r; cin >> l >> r;
//         cout << f[r] - f[l-1] << endl;
//     }
//     return 0;
// }

//2026.3.14 复盘
#include<iostream>
using namespace std;

const int N = 1e5 + 10;
int a[N];
long long f[N];

int main()
{
    int n; cin >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
        f[i] = f[i-1] + a[i];
    }

    int m; cin >> m;
    while(m--)
    {
        int l, r; cin >> l >> r;
        cout << f[r] - f[l-1] << endl;
    }

    return 0;
}