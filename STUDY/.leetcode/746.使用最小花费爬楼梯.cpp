/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */

// @lc code=start
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost)
    {
        int n = cost.size();
        vector<int> dp(n + 1);
        dp[n - 1] = cost[n - 1];
        dp[n - 2] = cost[n - 2];

        for(int i=n-3; i>=0; --i)
        {
            dp[i] = min(dp[i + 1] + cost[i], dp[i + 2] + cost[i]);
        }

        return min(dp[1], dp[0]);
    }
};
// @lc code=end

//二刷：动态规划，以i位置为起点，dp存储从i位置到楼顶的最小花费
//一刷：动态规划，以i位置为重点，无需分类讨论，因为n>=2
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost)
    {
        //1.创建dp
        int n = cost.size();
        vector<int> dp(n + 1);

        //2.初始化
        dp[0] = 0;
        dp[1] = dp[0];

        //3.填表
        for(int i=2; i<=n; ++i)
        {
            dp[i] = min(dp[i - 2] + cost[i - 2], dp[i - 1] + cost[i - 1]);
        }

        //4.返回值
        return dp[n];
    }
};
