#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> v(n, 0);
    for(int i=0; i<n; i++) cin >> v[i];

    int m; cin >> m;
    while(m--)
    {
        char op; cin >> op;
        n = v.size();

        if(op == 'I')
        {
            int i, k; cin >> i >> k;
            if(i >= 1 && i <= n + 1 && n + k <= 1000)
            {
                for(int j=0; j<k; ++j)
                {
                    int x; cin >> x;
                    v.insert(v.begin() + i - 1, x);
                    ++i;
                }

                if(v.size() > 0)
                {
                    for(auto x : v) cout << x << " ";
                    cout << endl;
                }
                else cout << "empty" << endl;
            }
            else
            {
                for(int j=0; j<k; ++j) //要把剩下的数据读完！
                {
                    int x; cin >> x;
                }
                cout << "error" << endl;
            }
        }
        else
        {
            int i, k; cin >> i >> k;
            if(i >= 1 &&  i + k <= n + 1)
            {
                for(int j=0; j<k; ++j)
                {
                    v.erase(v.begin() + i - 1);
                }

                if(v.size() > 0)
                {
                    for(auto x : v) cout << x << " ";
                    cout << endl;
                }
                else cout << "empty" << endl;
            }
            else
            {
                cout << "error" << endl;
            }
        }
    }
    return 0;
}