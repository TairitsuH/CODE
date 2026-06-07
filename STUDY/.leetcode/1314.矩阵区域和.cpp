/*
 * @lc app=leetcode.cn id=1314 lang=cpp
 *
 * [1314] 矩阵区域和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k)
    {
        int r = mat.size();
        int c = mat[0].size();

        vector<vector<int>> vv(r + 1, vector<int>(c + 1, 0));
        vector<vector<int>> ret(r, vector<int>(c, 0));

        //二维前缀和
        for(int i=1; i<=r; i++)
        {
            for(int j=1; j<=c; j++)
            {
                vv[i][j] = vv[i - 1][j] + vv[i][j - 1] - vv[i - 1][j - 1] + mat[i - 1][j - 1];
            }
        }

        //填矩阵
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                int x1 = max(i - k, 0) + 1;
                int y1 = max(j - k, 0) + 1;
                int x2 = min(i + k, r - 1) + 1;
                int y2 = min(j + k, c - 1) + 1;

                ret[i][j] = vv[x2][y2] - vv[x1 - 1][y2] - vv[x2][y1 - 1] + vv[x1 - 1][y1 - 1];
            }
        }

        return ret;
    }
};
// @lc code=end

//一刷：思路是二维前缀和，注意越界的情况和下标映射