/*
 * @lc app=leetcode.cn id=542 lang=cpp
 *
 * [542] 01 矩阵
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat)
    {
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        int M = mat.size();
        int N = mat[0].size();
        int dist[M][N];
        memset(dist, -1, sizeof(dist));

        queue<pair<int, int>> q;

        for(int i=0; i<M; ++i)
        {
            for(int j=0; j<N; ++j)
            {
                if(mat[i][j] == 0)
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

                if(x >= 0 && y >= 0 && x < M && y < N && dist[x][y] == -1)
                {
                    dist[x][y] = dist[a][b] + 1;
                    mat[x][y] = dist[x][y];
                    q.push({x, y});
                }
            }
        }

        return mat;
    }
};
// @lc code=end

//多源bfs，先存储记录数组中为0的位置，再用dist数组代替bool数组、levelsize、ret的作用，实现一个个出入队列的功能

