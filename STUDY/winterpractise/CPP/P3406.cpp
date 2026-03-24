#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e6 + 10;
typedef long long LL;
LL f[N];

int main()
{
    int n, m; cin >> n >> m;
    int x; cin >> x;

    for(int i=2; i<=m; i++)
    {
        int y; cin >> y;
        if(x > y)
        {
            f[y]++;
            f[x]--;
        }
        else
        {
            f[y]--;
            f[x]++;
        }

        x = y;
    }

    for(int i=1; i<=n; i++)
    {
        f[i] += f[i-1];
    }

    LL ret = 0;
    for(int i=1; i<n; i++)
    {
        int a, b, c; cin >> a >> b >> c;
        ret += min(a*f[i], c+b*f[i]);
    }

    cout << ret;
    return 0;
}