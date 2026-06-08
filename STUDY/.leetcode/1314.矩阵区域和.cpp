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
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> vv(m+1, vector<int>(n+1, 0));
        vector<vector<int>> ret(m, vector<int>(n));

        //矩阵和
        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                vv[i][j] = mat[i - 1][j - 1] + vv[i - 1][j] + vv[i][j - 1] - vv[i - 1][j - 1];
            }
        }

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                int x1 = (i - k < 0 ? 0 : i - k) + 1;
                int y1 = (j - k < 0 ? 0 : j - k) + 1;
                int x2 = (i + k > m - 1 ? m - 1 : i + k) + 1;
                int y2 = (j + k > n - 1 ? n - 1 : j + k) + 1;

                int sum = vv[x2][y2] - vv[x2][y1 - 1] - vv[x1 - 1][y2] + vv[x1 - 1][y1 - 1];

                ret[i][j] = sum;
            }
        }

        return ret;
    }
};
// @lc code=end

//二刷：注意下标！在sum的位置卡了好久TvT。x1和y1都要-1处理！
//一刷：思路是二维前缀和，注意越界的情况和下标映射，有点像扫雷
// class Solution {
// public:
//     vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k)
//     {
//         int r = mat.size();
//         int c = mat[0].size();

//         vector<vector<int>> vv(r + 1, vector<int>(c + 1, 0));
//         vector<vector<int>> ret(r, vector<int>(c, 0));

//         //二维前缀和
//         for(int i=1; i<=r; i++)
//         {
//             for(int j=1; j<=c; j++)
//             {
//                 vv[i][j] = vv[i - 1][j] + vv[i][j - 1] - vv[i - 1][j - 1] + mat[i - 1][j - 1];
//             }
//         }

//         //填矩阵
//         for(int i=0; i<r; i++)
//         {
//             for(int j=0; j<c; j++)
//             {
//                 int x1 = max(i - k, 0) + 1;
//                 int y1 = max(j - k, 0) + 1;
//                 int x2 = min(i + k, r - 1) + 1;
//                 int y2 = min(j + k, c - 1) + 1;

//                 ret[i][j] = vv[x2][y2] - vv[x1 - 1][y2] - vv[x2][y1 - 1] + vv[x1 - 1][y1 - 1];
//             }
//         }

//         return ret;
//     }
// };