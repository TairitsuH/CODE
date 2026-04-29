/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */
// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> vv(numRows);
        for(size_t i=0; i<numRows; i++)
        {
            vv[i].resize(i+1, 1);
        }

        for(size_t i=2; i<numRows; i++)
        {
            for(size_t j=1; j<vv[i].size()-1; j++)
            {
                vv[i][j] = vv[i-1][j] + vv[i-1][j-1];
            }
        }

        return vv;
    }
};
// @lc code=end

//二刷；边界条件和扩容还需加强
//一刷：对于函数的熟悉度还不够，扩容机制也不熟悉，还需巩固
// class Solution {
// public:
//     vector<vector<int>> generate(int numRows)
//     {
//         vector<vector<int>> vv(numRows);

//         for(size_t i=0; i<numRows; i++)
//         {
//             vv[i].resize(i+1, 1);
//         }

//         for(size_t i=2; i<numRows; i++)
//         {
//             for(size_t j=1; j<vv[i].size()-1; j++) //注意减1
//             {
//                 vv[i][j] = vv[i-1][j] + vv[i-1][j-1];
//             }
//         }

//         return vv;
//     }
// };