#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> v(n, 0);
    for(int i=0; i<n; ++i) cin >> v[i];
    int m; cin >> m;
    while(m--)
    {
        char op; cin >> op;
        n = v.size();
        if(op == 'A')
        {
            int x; cin >> x;
            int flag = 1;
            for(auto num : v)
            {
                if(x == num)
                {
                    cout << "exists" << endl;
                    flag = 0;
                    break;
                }
            }
            if(flag == 1)
            {
                v.push_back(x);
                cout << "ok" << endl;
                // for(auto x : v) cout << x << " ";
                // cout << endl;
            }
        }
        else
        {
            int x; cin >> x;
            int flag = 0;
            for(int i=0; i<n; ++i)
            {
                if(x == v[i])
                {
                    cout << i + 1 << endl;
                    flag = 1;
                    break;
                }
            }

            if(flag == 0) cout << "none" << endl;
        }
    }
    return 0;
}