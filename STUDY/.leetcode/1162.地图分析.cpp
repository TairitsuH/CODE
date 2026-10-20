/*
 * @lc app=leetcode.cn id=1162 lang=cpp
 *
 * [1162] 地图分析
 */

// @lc code=start
class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    int maxDistance(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dst(m, vector<int>(n, -1));   
        queue<pair<int, int>> q;

        //1.记录海洋的位置
        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                if(grid[i][j] == 1)
                {
                    q.push({i, j});
                    dst[i][j] = 0;
                }
            }
        }

        //2.多元bfs+记录最大值
        int ret = 0;
        while(q.size() > 0)
        {
            auto[a, b] = q.front();
            q.pop();

            for(int i=0; i<4; ++i)
            {
                int x = a + dx[i];
                int y = b + dy[i];

                if(x >= 0 && y >= 0 && x < m && y < n && dst[x][y] == -1)
                {
                    dst[x][y] = dst[a][b] + 1;
                    q.push({x, y});
                    ret = max(ret, dst[x][y]);
                }
            }
        }

        return ret == 0 ? -1 : ret;
    }
};
// @lc code=end

//二刷：多元bfs，注意是计算海洋到陆地的最大距离，此时要先标记陆地再对海洋做bfs
//一刷：多源bfs，先标记陆地的位置，通过bfs填充海洋位置到陆地的距离，更新ret并返回
class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    int maxDistance(vector<vector<int>>& grid)
    {
        int M = grid.size();
        int N = grid[0].size();
        vector<vector<int>> dist(M, vector<int>(N, -1));
        queue<pair<int, int>> q;
        int ret = -1;

        //1.统计陆地+入队列
        for(int i=0; i<M; ++i)
        {
            for(int j=0; j<N; ++j)
            {
                if(grid[i][j] == 1)
                {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }

        //2.多源bfs
        while(q.size() > 0)
        {
            auto[a, b] = q.front();
            q.pop();

            for(int i=0; i<4; ++i)
            {
                int x = a + dx[i];
                int y = b + dy[i];

                if(x >= 0 && y >= 0 &&  x < M && y < N && dist[x][y] == -1)
                {
                    q.push({x, y});
                    dist[x][y] = dist[a][b] + 1;
                    ret = max(ret, dist[x][y]);
                }
            }
        }

        return ret;
    }
};
