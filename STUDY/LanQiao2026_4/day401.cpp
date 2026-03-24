// //双指针：唯一的雪花
// //2026.3.15
// #include<iostream>
// #include<unordered_map>
// using namespace std;

// const int N = 1e5 + 10;
// int a[N];

// int main()
// {
//     int T; cin >> T;
//     while(T--)
//     {
//         int n; cin >> n;
//         for(int i=1; i<=n; i++)
//         {
//             cin >> a[i];
//         }

//         int left = 1, right = 1, ret = 0;
//         unordered_map<int, int> mp;
//         while(right <= n)
//         {
//             //进窗口
//             mp[a[right]]++;

//             //不合法时
//             while(mp[a[right]] > 1)
//             {
//                 mp[a[left]]--;
//                 left++;
//             }

//             ret = max(ret, right - left + 1);
            
//             right++;
//         }

//         cout << ret << endl;
        
//     }
//     return 0;
// }



//2026.3.16 复盘
#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;

const int N = 1e6 + 10;
int a[N];

int main()
{
    int T; cin >> T;
    while(T--)
    {
        int n; cin >> n;
        for(int i=0; i<n; i++)
        {
            cin >> a[i];
        }

        unordered_map <int, int> mp;
        int left = 1, right = 1, ret = 0;

        while(right < n)
        {

            mp[a[right]]++;

            while(mp[a[right]] > 1)
            {
                mp[a[left]]--;
                left++;
            }

            ret = max(ret, right - left + 1);

            right++; // 判断结束后再右移
        }
        cout << ret << endl;
    }
    return 0;
}