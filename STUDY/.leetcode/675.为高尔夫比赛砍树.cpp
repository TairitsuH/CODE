/*
 * @lc app=leetcode.cn id=675 lang=cpp
 *
 * [675] 为高尔夫比赛砍树
 */

// @lc code=start
class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int M, N;


    int bfs(vector<vector<int>>& forest, int m, int n, int tree)
    {
        bool visit[51][51] = {0};
        queue<pair<int, int>> q;

        q.push({m, n});
        visit[m][n] = true;
        int ret = 0;
        
        while(q.size() > 0)
        {
            ++ret;
            int levelsize = q.size();

            for(int i=0; i<levelsize; ++i)
            {
                auto [a, b] = q.front();
                q.pop();

                for(int i=0; i<4; ++i)
                {
                    int x = dx[i] + a;
                    int y = dy[i] + b;

                    if(x >= 0 && y >= 0 && x < M && y < N  && !visit[x][y] && forest[x][y] > 0)
                    {
                        if(forest[x][y] == tree) return ret;
                        q.push({x, y});
                        visit[x][y] = true;
                    }
                }
            }
        }

        return 0;
    }

    int cutOffTree(vector<vector<int>>& forest)
    {
        M = forest.size();
        N = forest[0].size();

        if(forest[0][0] == 0) return -1; //起点不存在

        //1.存树，排序
        map<int, pair<int, int>> height;
        for(int i=0; i<M; ++i)
        {
            for(int j=0; j<N; ++j)
            {
                if(forest[i][j] > 1) height[forest[i][j]] = {i, j};
            }
        }

        //2.计算最短路径
        int ret = bfs(forest, 0, 0, height.begin()->first);
        for(auto it=height.begin(); it!=height.end(); ++it)
        {
            auto [m, n] = it->second;
            auto tmp = it;
            if(++tmp != height.end())
            {
                int cnt = bfs(forest, m, n, tmp->first);
                if(cnt == 0) return -1;
                ret += cnt;
            }
        }

        return ret;
    }
};
// @lc code=end

//一刷：先找出砍树的路径，再按照顺序算出每棵树之间的大小顺序，注意细节：1是地面不是树，起点从(0, 0)开始

