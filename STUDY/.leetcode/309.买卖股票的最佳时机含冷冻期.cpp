/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 买卖股票的最佳时机含冷冻期
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();
        vector<int> f(n, 0);  
        vector<int> g(n, 0);  
        vector<int> h(n, 0);  

        f[0] = -prices[0];

        for(int i=1; i<n; ++i)
        {
            f[i] = max(f[i-1], g[i-1]-prices[i]);
            g[i] = max(h[i-1], g[i-1]);
            h[i] = f[i-1] + prices[i];
        }

        return max(g[n-1], h[n-1]);
    }
};
// @lc code=end

//二刷：动态规划，按照自己的理解整理了整个步骤，非常顺畅！一遍过ψ(｀∇´)ψ
//一刷：动态规划，注意下标映射，状态复杂的题使用状态机画图表示！
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(3, 0));

        dp[0][0] = -prices[0];

        for(int i=1; i<n+1; ++i)
        {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] - prices[i-1]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][2]);
            dp[i][2] = dp[i-1][0] + prices[i-1];
        }    

        return max(dp[n][1], dp[n][2]);
    }
};
