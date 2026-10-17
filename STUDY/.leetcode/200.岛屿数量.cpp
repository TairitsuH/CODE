/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
public:
    int M, N;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    bool check[301][301];

    void bfs(vector<vector<char>>& grid, int m, int n)
    {
        check[m][n] = true;
        queue<pair<int, int>> q;
        q.push({m, n});

        while(q.size() > 0)
        {
            auto [a, b] = q.front();
            q.pop();

            for(int i=0; i<4; ++i)
            {
                int x = dx[i] + a;
                int y = dy[i] + b;

                if(x >=0 && x < M && y >= 0 && y <N && grid[x][y] == '1' && !check[x][y])
                {
                    check[x][y] = true;
                    q.push({x, y});
                }
            }
        }
    }   

    int numIslands(vector<vector<char>>& grid)
    {
        M = grid.size();
        N = grid[0].size();
        int ret = 0;

        for(int i=0; i<M; ++i)
        {
            for(int j=0; j<N; ++j)
            {
                if(grid[i][j] == '1' && !check[i][j])
                {
                    bfs(grid, i, j);
                    ++ret;
                }
            }
        }

        return ret;
    }
};
// @lc code=end
//三刷：floodfill算法，bfs+不修改原数组（用bool数组标记已经走过的位置）
//二刷：floodfill算法，非递归bfs，注意queue要用int存坐标，否则会存不下导致大用例出错！
class Solution {
public:
    int M, N;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    void bfs(vector<vector<char>>& grid, int m, int n)
    {
        queue<pair<int, int>> q;
        q.push({m, n});
        grid[m][n] = '0';

        while(q.size() > 0)
        {
            auto [a, b] = q.front();
            q.pop();

            for(int i=0; i<4; ++i)
            {
                int x = dx[i] + a;
                int y = dy[i] + b;
                if(x >= 0 && x < M && y >= 0 && y < N && grid[x][y] == '1')
                {
                    grid[x][y] = '0';
                    q.push({x, y});
                }
            }
        } 


    }

    int numIslands(vector<vector<char>>& grid)
    {
        M = grid.size();
        N = grid[0].size();
        int ret = 0;
        for(int i=0; i<M; ++i)
        {
            for(int j=0; j<N; ++j)
            {
                if(grid[i][j] == '1')
                {
                    cout << i << ' ' << j << endl;
                    ++ret;
                    bfs(grid, i, j);
                }
            }
        }

        return ret;
    }
};
//一刷：递归floodfill，注意更新结果要完善！
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
