#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> a(n+1);
    for(int i=1; i<=n; i++)
    {
        int x; cin >> x;
        a[i] = a[i-1] + x;
    }

    int b, c;
    for(; cin >> b >> c; )
    {
        cout << a[c+1] - a[b] << endl;
    }
    return 0;
}

//一刷：前缀和，存储方式是从a[1]开始，画图模拟
//二刷：试了一下用vector,可以创建可变长数组
//备注：C++ 代码面对大量数据读取，输出操作，最好用scanf和printf，耗时会小很多

// #include<iostream>
// using namespace std;

// const int N = 1e5 + 10;
// int a[N]; //默认全为0

// int main()
// {
//     int n; cin >> n;
//     for(int i=1; i<=n; i++)
//     {
//         int x;
//         cin >> x;
//         a[i] = a[i-1] + x;
//     }

//     int c, b;
//     for(; cin >> b >> c; )
//     {
//         cout << a[c + 1] - a[b] << endl; 
//     }

//     return 0;
// }

// //复盘
// #include<iostream>
// #include<vector>
// using namespace std;
// int main()
// {
//     int n; cin >> n;
//     vector<int> a(n + 1, 0);
//     for(int i=1; i<=n; i++)
//     {
//         int x; cin >> x;
//         a[i] = a[i-1] + x;
//     }

//     int b, c;
//     for(; cin >> b >> c; )
//     {
//         cout << a[c+1] - a[b] << endl;
//     }
//     return 0;
// }