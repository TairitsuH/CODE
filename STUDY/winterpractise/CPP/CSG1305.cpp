#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i ++)
    {
        a[i] = (i == 0 ? 0 : a[i - 1]) + (int)(100 * sin(n + i)) % 3;
    }

    while(m--)
    {
        int x; cin >> x;
     
        auto it1 = lower_bound(a.begin(), a.end(), x);
        auto it2 = upper_bound(a.begin(), a.end(), x);

        if(it1 != a.end()) cout << it1-a.begin() << " ";
        else cout << "-1" << " ";

        if(it2 != a.end()) cout << it2-a.begin() << endl;
        else cout << "-1" << endl;
    }
    return 0;
}