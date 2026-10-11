/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));  
        dp[0][1] = 0;

        for(int i=1; i<=m; ++i)
        {
            for(int j=1; j<=n; ++j)
            {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]);
                dp[i][j] += grid[i - 1][j - 1];
            }
        }

        return dp[m][n];
    }
};
// @lc code=end

//动态规划，状态表示为从起点到达该位置的最小路径和，注意初始化：除了[0][1]设置为0，其余设为INT_MAX，保证后续推导的正确性