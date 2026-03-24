////最大子段和
//2026.3.13
// #include<iostream>
// #include<algorithm>
// using namespace std;

// const int N = 2e6 + 10;
// long long f[N];

// int main()
// {
//     int n; cin >> n;
//     for(int i=1; i<=n; i++)
//     {
//         int x; cin >> x;
//         f[i] = f[i-1] + x;
//     }

//     long long ret = f[1];
//     long long prevmin = 0;
//     for(int i=1; i<=n; i++)
//     {
//         ret = max(f[i] - prevmin, ret);
//         prevmin = min(f[i], prevmin);
//     }

//     cout << ret << endl;
//     return 0;
// }

//2026.3.14 复盘
#include<iostream>
using namespace std;

typedef long long LL;
const int N = 2e6 + 10;
LL f[N];

int main()
{
    int n; cin >> n;
    for(int i=1; i<=n; i++)
    {
        int x; cin >> x;
        f[i] = f[i-1] + x;
    }

    LL maxnum = f[1];
    LL minnum = 0;
    for(int i=1; i<=n; i++) //一定要先更新最大区间和再更新最小前缀和！！！
    {
        maxnum = max(f[i]-minnum, maxnum);
        minnum = min(f[i], minnum);
    }

    cout << maxnum;
    return 0;
}