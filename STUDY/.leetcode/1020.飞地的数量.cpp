/*
 * @lc app=leetcode.cn id=1020 lang=cpp
 *
 * [1020] 飞地的数量
 */

// @lc code=start
class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    int numEnclaves(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<bool>> visit(m, vector<bool>(n));

        //1.对边界上的1进行bfs标记    
        for(int i=0; i<m; ++i)
        {
            if(grid[i][0] == 1)
            {
                visit[i][0] = true;
                q.push({i, 0});
            }
            if(grid[i][n-1] == 1)
            {
                visit[i][n-1] = true;
                q.push({i, n-1});
            }
        }

        for(int j=0; j<n; ++j)
        {
            if(grid[0][j] == 1)
            {
                visit[0][j] = true;
                q.push({0, j});
            }
            if(grid[m-1][j] == 1)
            {
                visit[m-1][j] = true;
                q.push({m-1, j});
            }
        }

        //2.多源bfs
        while(q.size() > 0)
        {
            auto [a, b] = q.front();
            q.pop();

            for(int i=0; i<4; ++i)
            {
                int x = dx[i] + a;
                int y = dy[i] + b;

                if(x >= 0 && y >= 0 && x < m && y < n && !visit[x][y] && grid[x][y] == 1)
                {
                    q.push({x, y});
                    visit[x][y] = true;
                }
            }
        }

        //3.遍历数组，统计1的数量
        int ret = 0;
        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                if(grid[i][j] == 1 && !visit[i][j])
                {
                    ++ret;
                }
            }
        }

        return ret;
    }
};
// @lc code=end
//二刷：多源bfs，注意开大数组应放在全局/用vector，否则空间不足
//一刷：多源bfs，正难则反，把边缘的1放入队列后，统一扩展并用bool数组标记，最后再遍历统计没有标记的1的数量
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid)
    {
        int M = grid.size();
        int N = grid[0].size();
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        queue<pair<int, int>> q;
        vector<vector<bool>> check(M, vector<bool>(N, 0));

        //1.入队列
        for(int i=0; i<M; ++i) 
        {
            if(grid[i][0] == 1)
            {
                check[i][0] = true;
                q.push({i, 0});
            }
            if(grid[i][N-1] == 1)
            {
                check[i][N-1] = true;
                q.push({i, N-1});
            }
        }   

        for(int j=0; j<N; ++j)
        {
            if(grid[0][j] == 1)
            {
                check[0][j] = true;
                q.push({0, j});
            }
            if(grid[M-1][j] == 1)
            {
                check[M-1][j] = true;
                q.push({M-1, j});
            }
        }

        //2.多源bfs
        while(q.size() > 0)
        {
            auto [a, b] = q.front();
            q.pop();

            for(int i=0; i<4; ++i)
            {
                int x = dx[i] + a;
                int y = dy[i] + b;

                if(x >= 0 && y >= 0 && x < M && y < N && !check[x][y] && grid[x][y] == 1)
                {
                    q.push({x, y});
                    check[x][y] = true;
                }
            }
        }

        //3.统计剩下的1
        int ret = 0;
        for(int i=0; i<M; ++i)
        {
            for(int j=0; j<N; ++j)
            {
                if(grid[i][j] == 1 && !check[i][j]) ++ret;
            }
        }

        return ret;
    }
};
