#include<iostream>
using namespace std;

long long a,b;

int main()
{
    cin >> a >> b;
    for(int i=a; i<=b; i++)
    {
        if(i%2 == 0) //是偶数
        {
            continue;
        }

        int w = i, s = 0;
         while(w) //产生回文数
        {
            s = s*10 + w%10;
            w /= 10;
        }

        if(s != i) //判断回文数
        {
            continue;
        }

        int flag = 1;
        for(int j=2; j*j<=i; j++)
        {
            if(i % j == 0)
            {
                flag = 0;
                break;
            }
        }
        if(flag == 1)
        {
            cout << i << endl;
        }
    }
    return 0;
}