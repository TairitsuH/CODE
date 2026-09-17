#include<iostream>
#include<map>
using namespace std;

int main()
{
    int T; cin >> T;
    while(T--)
    {
        map<int, int> hash;
        int n; cin >> n; 
        for(int i=0; i<n; ++i)
        {
            int c, e; cin >> c >> e;
            hash[e] += c;
        }

        int m; cin >> m;
        for(int i=0; i<m; ++i)
        {
            int c, e; cin >> c >> e;
            hash[e] += c;
        }

        int cnt = 0;
        for(auto it : hash)
        {
            if(it.second != 0) ++cnt;
        }
        cout << cnt << endl;
        for(auto it : hash)
            if(it.second != 0) 
                cout << it.second << " " << it.first << endl;

    }
    return 0;
}