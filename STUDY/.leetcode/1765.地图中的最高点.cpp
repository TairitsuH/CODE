/*
 * @lc app=leetcode.cn id=1765 lang=cpp
 *
 * [1765] 地图中的最高点
 */

// @lc code=start
class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater)
    {
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<int>> dst(m, vector<int>(n, -1));
        queue<pair<int, int>> q;

        //1.标记水域（1->0）+ 入队列
        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                if(isWater[i][j] == 1)
                {
                    q.push({i, j});
                    dst[i][j] = 0;
                }
            }
        }    

        //2.多元bfs
        while(q.size() > 0)
        {
            auto [a, b] = q.front();
            q.pop();

            for(int i=0; i<4; ++i)
            {
                int x = a + dx[i];
                int y = b + dy[i];

                if(x >= 0 && y >= 0 && x < m && y < n && dst[x][y] == -1 && isWater[x][y] == 0)
                {
                    dst[x][y] = dst[a][b] + 1;
                    q.push({x, y});
                }
            }
        }

        return dst;
    }
};
// @lc code=end
//二刷：多元bfs，注意审题，水域和陆地在原数组中是相反的，另外dst的作用包括了记录是否已经遍历过，需要判断是否为-1，否则会死循环
//一刷：多源bfs，注意iswater数组中值表示的含义
class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater)
    {
        int M = isWater.size();
        int N = isWater[0].size();
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        vector<vector<int>> dist(M, vector<int>(N, -1));
        queue<pair<int, int>> q; 

        for(int i=0; i<M; ++i)
        {
            for(int j=0; j<N; ++j)
            {
                if(isWater[i][j] == 1)
                {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }

        while(q.size() > 0)
        {
            auto [a, b] = q.front();
            q.pop();

            for(int i=0; i<4; ++i)
            {
                int x = dx[i] + a;
                int y = dy[i] + b;

                if(x >= 0 && y >= 0 && x < M && y < N && isWater[x][y] == 0 && dist[x][y] == -1)
                {
                    dist[x][y] = dist[a][b] + 1;
                    q.push({x, y});
                }
            }
        }

        return dist;
    }
};
