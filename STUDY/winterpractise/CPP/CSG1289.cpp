#include<iostream>
using namespace std;

int n, out = 1;

int main()
{
    cin >> n;
    if(n == 0) cout << 1;
    else
    {
        for(int i=1; i<=n; i++) out*=i;
        cout << out;
    }
    return 0;
}