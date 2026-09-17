#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> v1(n);
    for(int i=0; i<n; ++i)  cin >> v1[i];

    int m; cin >> m;
    while(m--)
    {
        int x; cin >> x;
        v1.push_back(x);
    }

    for(auto x : v1) cout << x << " ";

    return 0;
}