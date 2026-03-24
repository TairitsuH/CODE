// //最大子段和：贪心
// //2026.3.16
// #include<iostream>
// using namespace std;

// const int N = 1e6 + 10;
// int a[N];

// int main()
// {
//     int n; cin >> n;
//     for(int i=0; i<n; i++)
//     {
//         cin >> a[i];
//     }

//     long long sum = 0;
//     long long ret = -1e8;
//     for(int i=0; i<n; i++)
//     {
//         sum += a[i];
//         ret = max(ret, sum); //ret要放在判断前，保证数据先录入
//         if(sum < 0) sum = 0;

//     }

//     cout << ret;

//     return 0;
// }

//2026.3.17 复盘
#include<iostream>
using namespace std;

const int N = 1e6 + 10;
int a[N];

int main()
{
    int n; cin >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
    }

    long long sum = 0;
    long long ret = -1e5;

    for(int i=1; i<=n; i++)
    {
        sum += a[i];
        ret = max(ret, sum);
        if(sum < 0)
        {
            sum = 0;
        }
    }

    cout << ret << endl;

    return 0;
}