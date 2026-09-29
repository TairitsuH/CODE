/*
 * @lc app=leetcode.cn id=1219 lang=cpp
 *
 * [1219] 黄金矿工
 */

// @lc code=start
class Solution {
public:

    int ret = 0;
    int M, N;
    bool check[15][15];

    void dfs(vector<vector<int>>& grid, int m, int n, int cnt)
    {
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        for(int i=0; i<4; ++i)
        {
            int x = m + dx[i];
            int y = n + dy[i];

            if(x >= 0 && x < M && y >=0 && y < N && grid[x][y] != 0 && !check[x][y])
            {
                check[x][y] = true;
                dfs(grid, x, y, cnt + grid[x][y]);
                check[x][y] = false;
            }
        }

        ret = max(ret, cnt);
    }

    int getMaximumGold(vector<vector<int>>& grid)
    {
        M = grid.size();
        N = grid[0].size();

        for(int i=0; i<M; ++i)
        {
            for(int j=0; j<N; ++j)
            {
                if(grid[i][j] != 0)
                {
                    check[i][j] = true;
                    dfs(grid, i, j, grid[i][j]);
                    check[i][j] = false;
                }
            }
        }    

        return ret;
    }
};
// @lc code=end

//一刷：递归dfs，注意1 <= grid.length, grid[i].length <= 15的意思是两个变量的取值范围为[1, 15]！逗号不分割语句！

