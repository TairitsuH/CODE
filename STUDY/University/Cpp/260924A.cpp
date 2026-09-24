#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main()
{
    int T; cin >> T;
    while(T--)
    {
        stack<long long> st;
        int n; cin >> n;

        vector<long long> v;
        for(long long i=0; i<n; ++i)
        {
            long long x; cin >> x;
            v.push_back(x);
        }

        long long pos = 0;
        for(long long i=1; i<=n; ++i)
        {
            st.push(i);

            while(!st.empty() && st.top() == v[pos])
            {
                st.pop();
                ++pos;
            }
        }

        if(!st.empty()) cout << "No" << endl;
        else cout << "Yes" << endl;

    }
    return 0;
}