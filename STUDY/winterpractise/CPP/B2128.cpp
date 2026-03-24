#include<iostream>
using namespace std;

int n, cnt = 1;

int main()
{
    cin >> n;
    if(n == 2) cout << cnt;
    else
    {
        for(int i=3; i<=n; i++)
        {
            int flag = 0;
            for(int j=2; j*j<=i+1; j++)
            {
                if(i%j == 0)
                {
                    flag = 1;
                    break;
                }
            }
            if(flag == 0) cnt++;
        }
        cout << cnt;
    }
    return 0;
}