//解法2：枚举所有的年份，得出相应日期，判断合法性
#include<iostream>
using namespace std;

int a,b,y_1,y_2;
int day[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int cnt = 0;

int main()
{
    cin >> a >> b;
    y_1 = a / 10000; y_2 = b / 10000;
    for(int i=y_1; i<=y_2; i++)
    {
        int m = i%10*10 + i/10%10;
        int d = i/100%10*10 + i/1000;
        int sum = i*10000 + m*100 + d;
        if(sum >=a && sum <=b)
        {
            if(m == 2)
            {
                if((i%4==0 && i%100!=0) || i%400==0)
                {
                    if(d>=1 && d<=29) cnt++;
                }
                else goto no;
            }
            else
            {
                no:
                if(m>=1 && m<=12 && d<=day[m] && d>=1)
                cnt++;
            }
        }
    }

cout << cnt << endl;

    return 0;
}