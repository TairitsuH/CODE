#include<iostream>
using namespace std;

void arrchange(int arr[], int y, int m, int d)
{
    while(y)
        {
            arr[y % 10]++;
            y /= 10;
        }        
        while(m)
        {
            arr[m % 10]++;
            m /= 10;
        }
        while(d)
        {
            arr[d % 10]++;
            d /= 10;
        }
}

void culcnt(int arr[], int* cnt)
{
    int i;
    int same = -1;
    for(i=0; i<=9; i++)
    {
        if(arr[i] != -1)
        {
            if(same == -1)same = arr[i];
            else
            {
                if(same != arr[i]) break;
            }
        }
    }
    if(i == 10) (*cnt)++;
}

int main()
{
    int y = 2239;
    int m = 9;
    int d = 3;
    int cnt = 0;
    while(1)
    {
        if(y >= 9876 && m >= 1 && d > 1) break;

        int arr[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
        arrchange(arr, y, m, d);

        culcnt(arr, &cnt);

        switch(m)
        {
            case 2:
            {
                if((y%100!=0 && y%4==0) || (y%400==0)) //闰年
                {
                    if(d < 29) d++;
                    else
                    {
                        m++;
                        d = 1;
                    }
                }
                else
                {
                    if(d < 28) d++;
                    else
                    {
                        m++;
                        d = 1;
                    }
                }
                break;
            }
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
            {
                if(d < 31) d++;
                else if(m < 12)
                {
                    m++;
                    d = 1;
                }
                else
                {
                    y++;
                    m = d = 1;
                }
                break;
            }
            case 4:
            case 6:
            case 9:
            case 11:
            {
                if(d < 30) d++;
                else
                {
                    m++;
                    d = 1;
                }
                break;
            }
        }        
    }
    cout << cnt;
    return 0;
}