#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int m; cin >> m;
    vector<int> v;
    while(m--)
    {
        char op; cin >> op;
        int n = v.size();
        if(op == 'I')
        {
            int i, x; cin >> i >> x;
            if(i >= 1 && i <= n + 1 && n < 1000)
            {
                v.insert(v.begin() + i - 1, x);
                cout << "ok" << endl;
            }
            else
            {
                cout << "error" << endl;
            }
        }
        else if(op == 'D')
        {
            int i; cin >> i;
            if(i >= 1 && i <= n)
            {
                v.erase(v.begin() + i - 1);
                cout << "ok" << endl;
            }
            else
            {
                cout << "error" << endl;
            }
        }
        else if(op == 'Q')
        {
            int i; cin >> i;
            if(i >= 1 && i <= n)
            {
                cout << v[i - 1] << endl;
            }
            else
            {
                cout << "error" << endl;
            }
        }
        else if(op == 'F')
        {
            int x; cin >> x;
            int flag = 0;
            for(int i=0; i<n; ++i)
            {
                if(v[i] == x)
                {
                    cout << i + 1 << endl;
                    flag = 1;
                    break;
                }
            }
            if(flag == 0) cout << "none" << endl;
        }
        else
        {
            if(n > 0)
            {
                for(auto x : v) cout << x << " ";
            }
            else cout << "empty" << endl;

            cout << endl;
        }
    }
    return 0;
}
