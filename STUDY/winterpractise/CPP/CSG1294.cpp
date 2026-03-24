#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

int main()
{
    int n,m; cin >> n >> m;
    vector<int> a(n);

    for(int i = 0; i < n; i ++)
    a[i] = (int)(sin(n + i) * 1000000);

    while(m--)
    {
        int s,e,l,r; cin >> s >> e >> l >> r;

    if(a.size() == 0) 
    {
        cout << "null" << endl;
        continue;
    }

        if(s < a.size())
        {
            a.erase(a.begin()+s, a.begin()+min(e, (int)a.size()));
        }


        int flag = 0;

        if(l == r || l > a.size()-1) cout << "null" << endl;
        else
        {
            for(int j=l; j<min(r, (int)a.size()); j++) 
            {
                flag = 1;
                cout << a[j] << " ";
            }
            if(flag == 0) cout << "null";

            cout << endl;
        }

    }

    return 0;
}