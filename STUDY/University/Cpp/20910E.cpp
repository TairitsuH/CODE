#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n, q; cin >> n >> q;
    vector<int> a;
    while(n--)
    {
        int x; cin >> x;
        a.push_back(x);
    }

    while(q--)
    {
        int op; cin >> op;
        int n = a.size();
        int cnt = 0;

        if(op == 1)
        {
            int x; cin >> x;
            for(int i=0; i<n; i++)
            {
                    ++cnt;

                if(a[i] == x) 
                {
                    break;
                }
            }
        }
        else if(op == 2)
        {
            int x; cin >> x;
            for(int i=n-1; i>=0; i--)
            {
                    ++cnt;

                if(a[i] == x)
                {

                    break;
                }
            }
        }

        cout << cnt << endl;
    }
    return 0;
}