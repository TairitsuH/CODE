/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee)
    {
        int n = prices.size();
        vector<int> f(n, 0);
        vector<int> g(n, 0);

        f[0] = -prices[0];

        for(int i=1; i<n; ++i)
        {
            f[i] = max(f[i-1], g[i-1]-prices[i]);
            g[i] = max(g[i-1], f[i-1]+prices[i]-fee);
        }

        return max(f[n-1], g[n-1]);
    }
};
// @lc code=end

//二刷：动态规划，注意画状态机时的箭头朝向和下标对应，一遍过(☆▽☆)
//一刷：动态规划，简单状态dp，注意下表映射和初始化，以及状态转移方程
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee)
    {
        int n = prices.size();
        vector<int> f(n+1, 0);
        vector<int> g(n+1, 0);

        f[0] = -prices[0];

        for(int i=1; i<n+1; ++i)
        {
            f[i] = max(f[i-1], g[i-1] - prices[i-1]);
            g[i] = max(g[i-1], f[i-1] + prices[i-1] - fee);
        }

        return max(g[n], f[n]);
    }
};
