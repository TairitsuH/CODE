// //货仓选址（贪心）
// //2026.3.16
// #include<iostream>
// #include<algorithm>
// using namespace std;

// const int N = 1e5 + 10;
// int a[N];

// int main()
// {
//     int n; cin >> n;
//     for(int i=1; i<=n; i++)
//     {
//         cin >> a[i];
//     }

//     sort(a+1, a+1+n);

//     long long ret = 0;
//     for(int i=1; i<=n; i++)
//     {
//         ret += abs(a[i] - a[(1 + n) / 2]);
//     }

//     cout << ret <<endl;

    
//     return 0;
// }

// //方法二（结论）
// #include<iostream>
// #include<algorithm>
// using namespace std;

// const int N = 1e5 + 10;
// int a[N];

// int main()
// {
//     int n; cin >> n;
//     for(int i=1; i<=n; i++)
//     {
//         cin >> a[i];
//     }

//     sort(a+1, a+1+n);

//     long long ret = 0;
//     for(int i=1; i<=n/2; i++)
//     {
//         ret += abs(a[i] - a[n-i+1]);
//     }
    
//     cout << ret <<endl;

//     return 0;
// }

//2026.3.17 复盘
//方法1
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e5 + 10;
int a[N];

int main()
{
    int n; cin >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
    }

    sort(a+1, a+n+1);

    long long x = 0;
    int mid = a[(n + 1)/2]; //是中间位置的下标！！！
    for(int i=1; i<=n; i++)
    {
        x += abs(a[i] - mid);
    }

    cout << x;

    return 0;
}

//方法2
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e5 + 10;
int a[N];

int main()
{
    int n; cin >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
    }

    sort(a+1, a+1+n);
    
    long long sum = 0;
    for(int i=1; i<=n/2; i++)
    {
        sum += abs(a[i] - a[n+1-i]); //最小距离等于首尾两数之差
    }

    cout << sum << endl;
    return 0;
    
}