/*
 * @lc app=leetcode.cn id=1926 lang=cpp
 *
 * [1926] 迷宫中离入口最近的出口
 */

// @lc code=start
class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    bool visit[101][101];    

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance)
    {
        int M = maze.size();
        int N = maze[0].size();
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        visit[entrance[0]][entrance[1]] = true;
        int ret = 0;

        while(q.size() != 0)
        {
            ++ret;
            int levelsize = q.size();

            for(int k=0; k<levelsize; ++k)
            {
                auto[a, b] = q.front();
                q.pop(); 

                for(int i=0; i<4; ++i)
                {
                    int x = a + dx[i];
                    int y = b + dy[i];

                    if(x >= 0 && y >= 0 && x < M && y < N && maze[x][y] == '.' && !visit[x][y])
                    {
                        visit[x][y] = true;
                        if(x == M - 1 || y == N - 1 || x == 0 || y == 0) return ret;
                        q.push({x, y});
                    }
                }
            }
        }

        return -1;
    }
};
// @lc code=end

//一刷：路权为1的最短路径，注意ret更新的时机是每次while循环（每层），用bool数组标记是否走过，一层层往外扩

