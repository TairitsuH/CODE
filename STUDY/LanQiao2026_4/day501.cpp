// //木材加工 二分
// //2026.3.16
// #include<iostream>
// #include<algorithm>
// using namespace std;

// typedef long long LL;
// const LL N = 1e8 + 10;
// LL a[N];

// LL calc(LL x, LL n)
// {
//     LL cnt = 0;
//     for(int i=0; i<n; i++)
//     {
//         cnt += a[i] / x;
//     }
//     return cnt;
// }

// int main()

// {
//     LL n, k; cin >> n >> k;
//     for(int i=0; i<n; i++)
//     {
//         cin >> a[i];
//     }

//     LL left = 0, right = 1e8;
//     while(left < right)
//     {
//         LL mid = (left + right + 1) / 2;
//         if(calc(mid, n) >= k) left = mid;
//         else right = mid - 1;
//     }

//     cout << left;

//     return 0;
// }

//2026.3.17 复盘
#include<iostream>
using namespace std;

const int N = 1e8 + 10;
typedef long long LL;
LL a[N];
int n, k;

LL calc(LL x)
{
    LL cnt = 0;
    for(int i=0; i<n; i++)
    {
        cnt += a[i] / x;
    }
    return cnt;
}

int main()
{
    cin >> n >> k;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    LL left = 0, right = 1e8, ret = 0;
    while(left < right)
    {
        LL mid = (left + right + 1) / 2;
        if(calc(mid) < k)
        {
            right = mid - 1;
        }
        else
        {
            left = mid;
        }
        ret = max(ret, left);
    }

    cout << ret << endl;
    return 0;
}

