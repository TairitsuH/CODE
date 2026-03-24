// //差分 牛客
// //https://ac.nowcoder.com/acm/problem/226303
// //2026.3.13
// #include<iostream>
// using namespace std;

// const int N = 1e5 + 10;
// long long a[N], f[N];

// int main()
// {
//     long long n,m; cin >> n >> m;

//     for(int i=1; i<=n; i++)
//     {
//         cin >> a[i];
//         f[i] = a[i] - a[i-1];
//     }

//     while(m--)
//     {
//         long long l, k, r; cin >> l >> r >> k;
//         f[l] += k;
//         f[r+1] -= k;
//     }

//     for(int i=1; i<=n; i++)
//     {
//         a[i] = f[i] + a[i-1];
//         cout << a[i] << " ";
//     }
    

//     return 0;
// }

//2026.3.14 复盘
#include<iostream>
using namespace std;

typedef long long LL;
const int N = 1e7 + 10;
LL a[N];
LL f[N];

int main()
{
    int n, m; cin >> n >> m;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
        f[i] = a[i] - a[i-1];
    }

    while(m--)
    {
        int l, r, k; cin >> l >> r >> k;
        f[l] += k;
        f[r+1] -= k;
    }

    for(int i=1; i<=n; i++)
    {
        a[i] = a[i-1] + f[i];
        cout << a[i] << " ";
    }
    return 0;
}