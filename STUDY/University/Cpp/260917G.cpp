#include<iostream>
#include<vector>
using namespace std;

void Print(vector<int>& v)
{
    for(auto x : v) cout << x << " ";
    cout << endl;
}

int main()
{
    int n; cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; ++i) cin >> v[i];

    int m; cin >> m;
    while(m--)
    {
        char op; cin >> op;
        n = v.size();

        if(op == 'I')
        {
            int i, x; cin >> i >> x;
            if(i >= 1 && i <= n + 1 && n < 1000)
            {
                if(i == n + 1) v.push_back(x);
                else v.insert(v.begin() + i - 1, x);
                Print(v);
            } 
            else cout << "error" << endl;
        }
        else if(op == 'D')
        {
            int i; cin >> i;
            if(i >= 1 && i <= n) 
            {
                v.erase(v.begin() + i - 1);
                if(!v.empty())
                {
                    Print(v);
                }
                else cout << "empty" << endl;
            }
            else cout << "error" << endl;
        }
        else if(op == 'L')
        {
            int i; cin >> i;
            if(i >= 1 && i <= n)
            {
                int pos = i - 1;
                if(pos == 0) cout << "none" << endl;
                else
                {
                    cout << v[pos - 1] << endl;
                }
            }
            else
            {
                cout << "error" << endl;
            }
        }
        else
        {
            int i; cin >> i;
            if(i >= 1 && i <= n)
            {
                int pos = i - 1;
                if(pos == n - 1) cout << "none" << endl;
                else cout << v[pos + 1] << endl;
            }
            else cout << "error" << endl;
        }
    }
    return 0;
}