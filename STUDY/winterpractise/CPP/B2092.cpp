//超时了！！思路是对的
// #include<iostream>
// using namespace std;

// const int N = 6000;
// int arr[N] = {1};
// int n;
// int cnt;

// int main()
// {
//     cin >> n;
//     for(int i=1; i<=n; i++)
//     {
//         for(int j=1; j<=n; j++)
//         {
//             arr[i*j] = 1 - arr[i*j];
//         }
//     }

//     for(int i=1; i<=n; i++)
//     {
//         if(arr[i] == 1) cout << i << " ";
//     }

//     return 0;
// }

#include<iostream>
using namespace std;

int n;

int main()
{
    cin >> n;
    for(int i=1; i*i<=n; i++) cout << i*i << " ";
    return 0;
}