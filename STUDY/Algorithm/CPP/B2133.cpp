#include<iostream>
using namespace std;

const int N = 1000;
int n,s;

int sum(int i)
{
    int all = 0;
    for(int j=0; j<=i; j++)
    {
        all += j;
    }
    return all;
}

int main()
{
    cin >> n;
    for(int i=1; i<=N; i++)
    {
        s = sum(i);
        for(int j=1; j<=i; j++)
        {
            if(s-3*j == n)
            {
                cout << j << " " << i;
                goto end;
            }
        }
    }
    end:
    return 0;
}