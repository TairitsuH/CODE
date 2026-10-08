#include<iostream>
using namespace std;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        string s; cin >> s;
        int n = s.size();
        int len = -1;

        for(int i=0; i<n; ++i)
        {
            for(int j=i+1; j<n; ++j)
            {
                int add = 0;
                while(i + add < n && j - i > add && s[i+add] == s[j+add]) ++add;

                if(add > 0) len = max(len, add);
            }
        }

        cout << len << endl;
    }
    return 0;
}