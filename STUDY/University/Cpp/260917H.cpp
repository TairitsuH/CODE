#include<iostream>
#include<map>
using namespace std;

int main()
{
    int T; cin >> T;
    while(T--)
    {
        map<int, int> rbmap;
        int n; cin >> n; 
        for(int i=0; i<n; ++i)
        {
            int c, e; cin >> c >> e;
            rbmap[e] += c;
            if(rbmap[e] == 0) rbmap.erase(e);
        }

        int m; cin >> m;
        for(int i=0; i<m; ++i)
        {
            int c, e; cin >> c >> e;
            rbmap[e] += c;
            if(rbmap[e] == 0) rbmap.erase(e);
        }

        cout << rbmap.size() << endl;
        for(auto it : rbmap)
                cout << it.second << " " << it.first << endl;

    }
    return 0;
}