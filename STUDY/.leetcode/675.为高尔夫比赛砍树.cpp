/*
 * @lc app=leetcode.cn id=675 lang=cpp
 *
 * [675] 为高尔夫比赛砍树
 */

// @lc code=start
class Solution {
public:
    int M, N;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    bool visit[51][51];

    int bfs(vector<vector<int>>& forest, int bx, int by, int ex, int ey)
    {
        if(bx == ex && by == ey) return 0;

        memset(visit, false, sizeof(visit));
        queue<pair<int, int>> q;
        q.push({bx, by});
        visit[bx][by] = true;
        int ret = 0;

        while(q.size() > 0)
        {
            ++ret;
            int levelsize = q.size();

            for(int i=0; i<levelsize; ++i)
            {
                auto [a, b] = q.front();
                q.pop();

                for(int j=0; j<4; ++j)
                {
                    int x = dx[j] + a;
                    int y = dy[j] + b;

                    if(x >= 0 && y >= 0 && x < M && y < N && forest[x][y] > 0 && !visit[x][y])
                    {
                        if(x == ex && y == ey) return ret;
                        q.push({x, y});
                        visit[x][y] = true;
                    }
                }
            }
        }

        return -1;
    }

    int cutOffTree(vector<vector<int>>& forest) 
    {
        //1.排序，找出路径
        M = forest.size();
        N = forest[0].size();
        vector<pair<int, int>> path;
        for(int i=0; i<M; ++i)
        {
            for(int j=0; j<N; ++j)
            {
                if(forest[i][j] > 1) path.push_back({i, j});
            }
        }

        sort(path.begin(), path.end(), [&](pair<int, int> p1, pair<int, int> p2)
        {
            return forest[p1.first][p1.second] < forest[p2.first][p2.second];
        });


        //2.逐步找出最小路径
        int bx = 0, by = 0;
        int ret = 0;

        for(auto [ex, ey] : path)
        {
            int cnt = bfs(forest, bx, by, ex, ey);
            if(cnt == -1) return cnt;
            ret += cnt;
            bx = ex, by = ey;
        }

        return ret;
    }
};
// @lc code=end

//二刷：先找出砍树的路径，再按照顺序算出每棵树之间的大小顺序，注意细节：1是地面不是树，起点从(0, 0)开始，注意循环变量不要重复！细节很多！

