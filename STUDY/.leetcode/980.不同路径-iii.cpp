/*
 * @lc app=leetcode.cn id=980 lang=cpp
 *
 * [980] 不同路径 III
 */

// @lc code=start
class Solution {
public:
    int M, N;
    int steps = 0;
    bool check[20][20];
    int ret = 0;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    void dfs(vector<vector<int>>& grid, int m, int n, int path)
    {
        for(int i=0; i<4; ++i)
        {
            int x = dx[i] + m;
            int y = dy[i] + n;

            if(x >= 0 && x < M && y >= 0 && y < N && !check[x][y])
            {
                if(grid[x][y] == 0)
                {
                    check[x][y] = true;
                    dfs(grid, x, y, path + 1);
                    check[x][y] = false;
                }
                //写在里面！在下一步判断
                else if(grid[x][y] == 2 && path == steps)
                {
                    ++ret;
                    return;
                }
            }
        }
    }

    int uniquePathsIII(vector<vector<int>>& grid) 
    {
        int x, y;
        M = grid.size();
        N = grid[0].size();

        for(int i=0; i<M; ++i)
        {
            for(int j=0; j<N; ++j)
            {
                if(grid[i][j] == 0) ++steps;
                if(grid[i][j] == 1) x = i, y = j;
            }
        }

        dfs(grid, x, y, 0);
        return ret;
    }
};
// @lc code=end

//一刷：递归dfs，注意递归出口在循环内部
