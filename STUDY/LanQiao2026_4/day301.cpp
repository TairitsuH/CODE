// //海底高铁（差分）
// //2026.3.14
// #include<iostream>
// #include<algorithm>
// using namespace std;

// typedef long long LL;
// const int N = 1e6 + 10;
// LL f[N];

// int main()
// {
//     int n,m; cin >> n >> m;
//     int x; cin >> x;
//     //存数
//     for(int i=2; i<=m; i++)
//     {
//         int y; cin >> y;
//         if(x > y)
//         {
//             f[y]++;
//             f[x]--;
//         }
//         else
//         {
//             f[y]--;
//             f[x]++;
//         }
//         x = y;
//     }
//     //还原
//     for(int i=1; i<=n; i++)
//     {
//         f[i] += f[i-1];
//     }

//     //计算费用
//     LL ret = 0;
//     for(int i=1; i<n; i++)
//     {
        
//         int a, b, c; cin >> a >> b >> c;
//         ret += min(a*f[i], c+b*f[i]);
//     }
//     cout << ret;

//     return 0;
// }

//2026.3.15 复盘
#include<iostream>
using namespace std;

typedef long long LL;
const int N = 1e6 + 10;
LL f[N];

int main()
{
    int n, m; cin >> n >> m;
    int x; cin >> x;
    for(int i=2; i<=m; i++)
    {
        int y; cin >> y;
        if(x > y)
        {
            f[y]++;
            f[x]--;
        }
        else
        {
            f[y]--;
            f[x]++;
        }
        x = y;
    }

    for(int i=1; i<=n; i++)
    {
        f[i] += f[i-1];
    }

    LL ret = 0; //一定要注意数据范围！！！
    for(int i=1; i<n; i++)
    {
        LL a, b, c; cin >> a >> b >> c;

        ret += min(a*f[i], c+b*f[i]); 
    }

    cout << ret;

    return 0;
}