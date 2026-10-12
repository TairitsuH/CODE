/*
 * @lc app=leetcode.cn id=174 lang=cpp
 *
 * [174] 地下城游戏
 */

// @lc code=start
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon)
    {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX)); //注意初始化！不要跳步

        dp[m-1][n] = 1;

        for(int i=m-1; i>=0; --i)
        {
            for(int j=n-1; j>=0; --j)
            {
                dp[i][j] = min(dp[i+1][j], dp[i][j+1]);
                dp[i][j] = max(1, dp[i][j] - dungeon[i][j]);
            }
        }

        return dp[0][0];
    }
};
// @lc code=end

//二刷：动态规划，注意初始化的部分需要考虑数组大小，数组初始值，特殊位置的初始值（保证映射关系和推导过程正确
//一刷：动态规划，新颖的解法，状态表示为以该位置为起点到终点所需的生命值
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon)
    {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));

        dp[m][n-1] = dp[m-1][n] = 1;

        for(int i=m-1; i>=0; --i)
        {
            for(int j=n-1; j>=0; --j)
            {
                dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]);                
                dp[i][j] = max(dp[i][j] - dungeon[i][j], 1);
            }
        }

        return dp[0][0];
    }
};
