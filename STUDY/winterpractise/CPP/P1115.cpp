#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e6+10;
typedef long long LL;
LL n;
LL a[N];
LL f[N];

int main()
{
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
        f[i] = f[i-1]+a[i];
    }

    LL ret = -1e20;
    LL premin = 0;
    for(int i=1; i<=n; i++)
    {
        ret = max(f[i]-premin, ret);
        premin = min(premin,f[i]);

    }
    cout << ret;
    return 0;
}