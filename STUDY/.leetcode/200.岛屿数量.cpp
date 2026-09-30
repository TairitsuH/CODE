/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
public:
    bool check[300][300];
    int ret = 0;
    int M, N;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    void dfs(vector<vector<char>>& grid, int m, int n)
    {
        for(int i=0; i<4; ++i)
        {
            int x = dx[i] + m;
            int y = dy[i] + n;

            if(x >= 0 && x < M && y >= 0 && y < N && !check[x][y] && grid[x][y] == '1')
            {
                check[x][y] = true;
                dfs(grid, x, y);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid)
    {
        M = grid.size();
        N = grid[0].size();
        for(int i=0; i<M; ++i)
        {
            for(int j=0; j<N; ++j)
            {
                if(grid[i][j] == '1' && !check[i][j]) 
                {
                    check[i][j] = true;
                    dfs(grid, i, j);
                    ++ret;
                }
            }
        }

        return ret;
    }
};


// @lc code=end
//一刷：递归floodfill，注意更新结果要完善！

