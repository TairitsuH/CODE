/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */

// @lc code=start
class Solution {
public:
    int ret = 0;
    int M, N;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    bool check[50][50];
    int cnt = 0;

    void dfs(vector<vector<int>>& grid, int m, int n)
    {
        ++cnt;
        check[m][n] = true;

        for(int i=0; i<4; ++i)
        {
            int x = dx[i] + m;
            int y = dy[i] + n;

            if(x >= 0 && x < M && y >= 0 && y < N && !check[x][y] && grid[x][y] == 1)
            {
                dfs(grid, x, y);
            }
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        M = grid.size();
        N = grid[0].size();

        for(int i=0; i<M; ++i)
        {
            for(int j=0; j<N; ++j)
            {
                if(grid[i][j] == 1 && !check[i][j])
                {
                    cnt = 0;
                    dfs(grid, i, j);
                    ret = max(ret, cnt);
                }
            }
        }

        return ret;
    }
};
// @lc code=end

//一刷：递归floodfill，注意不要再在局部重复定义全局变量！会冲突！
