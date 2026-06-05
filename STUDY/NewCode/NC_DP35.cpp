//https://www.nowcoder.com/practice/99eb8040d116414ea3296467ce81cbbc?tpId=230&tqId=2023819&sourceUrl=%2Fexam%2Foj%3Fpage%3D1%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D196
//【模板】二维前缀和
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n, m, q; cin >> n >> m >> q;
    vector<vector<long long>> vv(n + 1, vector<long long>(m + 1, 0));

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cin >> vv[i][j];
        }
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            vv[i][j] += vv[i-1][j] + vv[i][j-1] - vv[i-1][j-1];
        }
    }

    while(q--)
    {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        long long ret = vv[x2][y2] - vv[x1-1][y2] - vv[x2][y1-1] + vv[x1-1][y1-1];
        cout << ret << endl;
    }
    
    return 0;
}

//一刷：和一维前缀和不同，二维前缀和不能一边输入一边计算。需要在输入完数组后再处理。