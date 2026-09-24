#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> line = {0, 1, 0, -1};
vector<int> row = {1, 0, -1, 0};

bool dfs(int l, int r, int n, vector<vector<int>>& vv, vector<vector<int>>& visit, stack<pair<int, int>>& st)
{
    st.push({l, r}); //?
    visit[l][r] = 1;

    if(l == n-1 && r == n-1) return true;

    for(int i=0; i<4; ++i)
    {
        int nl = l + line[i]; //在原先的基础上修改，不要改动原坐标
        int nr = r + row[i];

        if(nl >= 0 && nl < n && nr >= 0 && nr < n && vv[nl][nr] == 0 && visit[nl][nr] == 0) //注意坐标
        {
            if( dfs(nl, nr, n, vv, visit, st)) return true;
        }
    }

    st.pop();
    return false;
}

int main()
{
    int T; cin >> T;
    while(T--)
    {
        int n; cin >> n;
        stack<pair<int, int>> st;
        vector<vector<int>> vv(n, vector<int>(n));
        vector<vector<int>> visit(n, vector<int>(n, 0));
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                cin >> vv[i][j];
            }
        }
        

        if(dfs(0, 0, n, vv, visit, st))
        {
            vector<pair<int, int>> ret;
            while(!st.empty())
            {
                ret.push_back(st.top());
                st.pop();
            }
            
            for(auto x = ret.rbegin(); x != ret.rend(); ++x) cout << x->first << " " << x->second << endl;
        }
        else cout << "no path" << endl;

    }

    return 0;
}