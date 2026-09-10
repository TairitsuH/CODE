#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<int> a;
        while(n--)
        {
            int x; cin >> x;
            a.push_back(x);
        }

        sort(a.begin(), a.end(), greater());

        int i;
        for(i=1; i<a.size(); i++)
        {
            if(a[i] != a[i - 1])
            {
                cout << a[i] << endl;
                break;
            }
        }

        if(i == a.size()) cout << "none" << endl;

    }    
    return 0;
}