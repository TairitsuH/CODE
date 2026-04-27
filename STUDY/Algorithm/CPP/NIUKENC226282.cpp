#include<iostream>
using namespace std;

const int N = 1e5+10;
typedef long long LL;
int n,m,l,r;
LL a[N];
LL f[N];

int main()
{
    cin >> n >> m;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
    }

    for(int j=1; j<=n; j++)
    {
        f[j] = f[j-1] + a[j];
    }

    while(m--)
    {
        cin >> l >> r;
        cout << f[r] - f[l-1] << endl;
    }
    return 0;
}