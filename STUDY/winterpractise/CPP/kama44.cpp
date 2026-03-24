#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int m, n; cin >> n >> m;

    vector<int> a(m, 0); //列
    vector<int> b(n, 0); //行

    for(int i=0; i<n; i++)
    {
        int sum = 0;
        for(int j=0; j<m; j++)
        {
            int x; cin >> x;
            a[j] += x;
            b[i] += x;
        }
        if(i != 0) b[i] += b[i-1];
    } 
    for(int j=1; j<m; j++)
    {
        a[j] += a[j-1];
    }

    int minsep = 1e9;
    for(int i=0; i<m-1; i++)
    {
        int sep = abs(a[i] - (a[m-1]-a[i]));
        minsep = min(minsep, sep);
    }

    for(int i=0; i<n-1; i++)
    {
        int sep = abs(b[i] - (b[n-1]-b[i]));
        minsep = min(minsep, sep);
    }

    cout << minsep << endl;
    
    return 0;
}

//一刷：一开始没思路，看了下评论区想到可以用前缀和解决。
//  但是出现了很多问题，比如行列混淆，minsep初始值设置的太小等等，
//  不过最后都一一解决了TvT
