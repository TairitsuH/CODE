/*
 * @lc app=leetcode.cn id=1765 lang=cpp
 *
 * [1765] 地图中的最高点
 */

// @lc code=start
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
// @lc code=end
//一刷：多源bfs，注意iswater数组中值表示的含义

