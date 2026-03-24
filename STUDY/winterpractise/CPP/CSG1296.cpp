#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n, m; cin >> n >> m;
    int maxe = 1;
    int T = n + m;
    vector<int> a(T);
    while(T--)
    {
        int e, x;
        cin >> e >> x;
        a[e] += x;
        maxe = max(maxe, e);
    }
    
    for(int i=1; i<=maxe; i++)
    {
        if(a[i] != 0)
        {
            cout << i << " " << a[i] << endl;
        }
    }
    return 0;
}