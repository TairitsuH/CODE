#include<iostream>
using namespace std;

const int N = 1e6+10;
typedef long long LL;
LL n,m,l,r;
LL a[N];
LL f[N];

int main()
{
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
    }


    for(int i=0; i<=n; i++)
    {
        f[i] = f[i-1]+a[i];
    }
    cin >> m;
    while(m--)
    {
        cin >> l >> r;
        cout << f[r]-f[l-1] << endl;
    }
    return 0;
}