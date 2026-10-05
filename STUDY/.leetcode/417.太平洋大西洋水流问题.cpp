/*
 * @lc app=leetcode.cn id=417 lang=cpp
 *
 * [417] 太平洋大西洋水流问题
 */

// @lc code=start
class Solution {
public:
    bool checkp[200][200];
    bool checka[200][200];
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int M, N;

    void dfsp(vector<vector<int>>& heights, int m, int n)
    {
        checkp[m][n] = true;

        for(int i=0; i<4; ++i)
        {
            int x = dx[i] + m;
            int y = dy[i] + n;

            if(x >= 0 && x < M && y >= 0 && y < N && !checkp[x][y] && heights[x][y] >= heights[m][n])
            {
                checkp[x][y] = true;
                dfsp(heights, x, y);
            }
        }
    }

    void dfsa(vector<vector<int>>& heights, int m, int n)
    {
        checka[m][n] = true;

        for(int i=0; i<4; ++i)
        {
            int x = dx[i] + m;
            int y = dy[i] + n;

            if(x >= 0 && x < M && y >= 0 && y < N && !checka[x][y] && heights[x][y] >= heights[m][n])
            {
                dfsa(heights, x, y);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights)
    {
        M = heights.size();
        N = heights[0].size();

        for(int j=0; j<N; ++j)
        {
            dfsp(heights, 0, j);
            dfsa(heights, M-1, j);
        }
        for(int i=0; i<M; ++i)
        {
            dfsp(heights, i, 0);
            dfsa(heights, i, N-1);
        }

        vector<vector<int>> ret;

        for(int i=0; i<M; ++i)
        {
            for(int j=0; j<N; ++j)
            {
                if(checkp[i][j] && checka[i][j])
                {
                    ret.push_back({i, j});
                }
            }
        }

        return ret;
    }
};
// @lc code=end
//一刷：floodfill+正难则反，注意不要重复定义M,N！最好不要定义为全局变量（bool数组），作为参数传入更简洁

