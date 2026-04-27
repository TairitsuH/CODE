// //解法1（推荐）：枚举所有的月日，拼接成年份，若回文，判断合法性
// #include<iostream>
// using namespace std;

// int x,y;
// int day[] = {0,31,29,31,30,31,30,31,31,30,31,30,31};

// int main()
// {
//     cin >> x >> y;
//     int cnt = 0;

//     for(int i=1; i<=12; i++)
//     {
//         for(int j=1; j<=day[i]; j++)
//         {
//             int k = j%10*1000+j/10*100+i%10*10+i/10; //回文年份
//             int sum = k*10000 + i*100+j; //回文日期
//             if(x <=sum && sum <= y) cnt++; //判断合法性
//         }
//     }

//     cout << cnt;
//     return 0;
// }


#include<iostream>
using namespace std;
int a,b;
int cnt = 0;
int day[] = {0,31,29,31,30,31,30,31,31,30,31,30,31}; //不要忘记在下标为0的位置赋0！！！

int main()
{
    cin >> a >> b;
    for(int i=1; i<=12; i++)
    {
        for(int j=1; j<=day[i]; j++)
        {
            int year = j%10*1000 + j/10*100 + i%10*10 + i/10;
            int sum = year*10000 + i*100 + j;
            if(a <= sum && sum <= b) cnt++;
        }
    }

    cout << cnt;
    return 0;
}