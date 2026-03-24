// #include<iostream>
// #include<cmath>
// using namespace std;

// int n,cnt1,cnt0,cntA,cntB;
// const int x = 20;
// int arr[x];
// int N;

// int ten_two(int i)
// {
//     int b = 0;
//     int x = i;
//     int p = 1;
//     while(x)
//     {
//         int y = x % 2;
//         b += y * p;
//         p *= 10;
//         x /= 2;
//     }
//     return b;
// }

// int main()
// {
//     cin >> n;
//     for(int i=1; i<=n; i++)
//     {
//         N = ten_two(i);
//         cnt1 = 0, cnt0 = 0;
//         while(N)
//         {
//             if(N%10 == 1) cnt1++;
//             else cnt0++;
//             N /= 10;
//         }
//         if(cnt1 > cnt0) cntA++;
//         else cntB++;
//     }

//     cout << cntA << " " << cntB << endl;
    
//     return 0;
// }

//利用按位与和右移操作符，可以不用转成二进制
#include<iostream>
using namespace std;

int A,B,cnt1,cnt0;

int main()
{
    int n,t,temp;
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        cnt0 = 0, cnt1 = 0;
        t = i;
        while(t)
        {
            temp = t & 1; //将t的二进制最低位和1比较，若相同则返回1
            t = t >> 1;
            if(temp) cnt1++;
            else cnt0++;
        }
        cnt1 > cnt0 ? A++ : B++;
    }
    cout << A << " " << B;
    return 0;
}