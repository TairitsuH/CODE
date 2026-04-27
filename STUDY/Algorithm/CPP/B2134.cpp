#include<iostream>
#include<cmath>
using namespace std;

int S;

bool is_prime(int a)
{
    int flag = 1;
    for(int i=2; i<=sqrt(a+1); i++)
    {
        if(a%i == 0)
        {
            flag = 0;
        }
    }
    return (flag == 1);
}

int main()
{
    cin >> S;
    for(int i=S/2; i>=2; i--)
    {
        if(i == 2) cout << i*(S-i);
        else
        {
            if(is_prime(i) && is_prime(S-i))
            {
                cout << i*(S-i);
                break;
            }
        }
    }
    return 0;
}