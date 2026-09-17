#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> v1(n, 0);
    for(int i=0; i<n; ++i) cin >> v1[i];

    int m; cin >> m;
    vector<int> v2(m, 0);
    for(int i=0; i<m; ++i) cin >> v2[i];

    vector<int> ret;
    
    int p1 = 0, p2 = 0;
    while(p1 < n && p2 < m)
    {
        while(p1 < n && p2 < m && v1[p1] <= v2[p2]) //两个判断条件都要写！
        {
            ret.push_back(v1[p1]);
            ++p1;
        }

        while(p1 < n && p2 < m && v1[p1] > v2[p2])
        {
            ret.push_back(v2[p2]);
            ++p2;
        }
    }

    while(p1 < n)
    {
        ret.push_back(v1[p1]);
        ++p1;
    }

    while(p2 < m)
    {
        ret.push_back(v2[p2]);
        ++p2;
    }

    for(auto x : ret) cout << x << " ";

    return 0;
}
