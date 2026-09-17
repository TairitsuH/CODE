#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> v(n, 0);
    v.reserve(1000);

    for(int i=0; i<n; ++i)
    {
        cin >> v[i];
    }


    int m; cin >> m;
    while(m--)
    {
        char op; cin >> op;
        n = v.size();
        
        if(op == 'I')
        {
            int i, x; cin >> i >> x;
            if(i >= 1 && i <= n + 1 && v.size() < 1000)
            {
                v.insert(v.begin()+i-1, x);

                if(v.size() > 0)
                {
                    for(int i=0; i<v.size(); ++i)
                    {
                        cout << v[i];
                        if(i != v.size() - 1) cout << " ";
                    }
                    cout << endl;
                }

                else cout << "empty" << endl;
            }
            
            else cout << "error" << endl;
        }
        else if(op == 'D')
        {
            int i; cin >> i;
            if(i >= 1 && i <= n)
            {
                v.erase(v.begin() + i-1);

                if(v.size() > 0)
                {
                    for(int i=0; i<v.size(); ++i)
                    {
                        cout << v[i];
                        if(i != v.size() - 1) cout << " ";
                    }
                    cout << endl;
                }

                else cout << "empty" << endl;
            }

            else cout << "error" << endl;
        }
        else if(op == 'Q')
        {
            int i; cin >> i;
            if(i >= 1 && i <= n)
            {
                if(v.size() > i-1) cout << v[i-1] << endl;
            }

            else cout << "error" << endl;
        }
    }

    return 0;
}