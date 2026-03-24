#include<iostream>
#include<cmath>
using namespace std;

int m,n;

int is_prime(int i)
{
    int flag = 1;
    if(i == 2) return 1;
    for(int j=2; j*j<=i; j++)
    {
        if(i % j == 0) return 0;
    }
    return 1;
}

int main()
{
    cin >> m >> n;
    for(int i=m; i<=n; i++)
    {
        int num = i;
        if(is_prime(num)) cout << num;
        else
        {
            for(int k = num-1; k>=2; k--)
            {
                if(is_prime(k) && num%k==0) 
                {
                    cout << k;
                    break;
                }
            }
        }
        if(i < n) cout << ",";
    }
    return 0;
}