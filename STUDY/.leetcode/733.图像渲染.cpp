/*
 * @lc app=leetcode.cn id=733 lang=cpp
 *
 * [733] 图像渲染
 */

// @lc code=start
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
// @lc code=end
//一刷：递归dfsfloodfill，记得判断坐标的合法性和将初始坐标设置为color
