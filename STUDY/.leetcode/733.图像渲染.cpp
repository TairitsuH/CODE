/*
 * @lc app=leetcode.cn id=733 lang=cpp
 *
 * [733] 图像渲染
 */

// @lc code=start
class Solution {
public:
    typedef pair<int, int> PII;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int M, N;

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color)
    {
        int prev = image[sr][sc];
        if(prev == color) return image;

        M = image.size();
        N = image[0].size();
        queue<PII> q;
        q.push({sr, sc});
        image[sr][sc] = color; //立刻染色！

        while(!q.empty())
        {
            auto [m, n] = q.front();
            q.pop();

            for(int i=0; i<4; ++i)
            {
                int x = m + dx[i];
                int y = n + dy[i];

                if(x >= 0 && x < M && y >= 0 && y < N && image[x][y] == prev)
                {
                    image[x][y] = color; //入队时染色
                    q.push({x, y});
                }
            }
        }

        return image;
    }
};
// @lc code=end
//二刷：floodfill算法非递归bfs，注意在入队时染色而不是在每次宽搜后染色（否则会被多次入队增加时间复杂度）
//一刷：递归dfsfloodfill，记得判断坐标的合法性和将初始坐标设置为color
class Solution {
public:
    int mod = 0;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int M, N;

    void dfs(vector<vector<int>>& image, int m, int n, int color)
    {
        for(int i=0; i<4; ++i)
        {
            int x = m + dx[i];
            int y = n + dy[i];

            if(x >= 0 && x < M && y >= 0 && y < N && image[x][y] == mod)
            {
                image[x][y] = color;
                dfs(image, x, y, color);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color)
    {
        if(image[sr][sc] == color) return image;

        M = image.size();
        N = image[0].size();
        mod = image[sr][sc];

        image[sr][sc] = color;
        dfs(image, sr, sc, color);
        return image;
    }
};