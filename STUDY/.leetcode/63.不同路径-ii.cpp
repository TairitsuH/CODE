/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        dp[0][1] = 1;
        for(int i=1; i<=m; ++i)
        {
            for(int j=1; j<=n; ++j)
            {
                if(obstacleGrid[i - 1][j - 1] == 1)
                {
                    obstacleGrid[i - 1][j - 1] = 0;
                    continue;
                }

                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }    

        return dp[m][n];
    }
};
// @lc code=end

//动态规划，状态表示为从起点到达该位置有多少条路径，细节在于初始化和障碍物置0
