/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

// @lc code=start
class Solution {
public:
    int maxProfit(int k, vector<int>& prices)
    {
        #define MIN -0x3f3f3f
        int n = prices.size();
        vector<vector<int>> f(n, vector<int>(k+1, MIN));
        vector<vector<int>> g(n, vector<int>(k+1, MIN));

        f[0][0] = -prices[0];
        g[0][0] = 0;

        for(int i=1; i<n; ++i)
        {
            for(int j=0; j<=k; ++j)
            {
                f[i][j] = max(f[i-1][j], g[i-1][j] - prices[i]);
                g[i][j] = g[i-1][j];
                if(j > 0) g[i][j] = max(g[i][j], f[i-1][j-1] + prices[i]);
            }
        }

        int ret = 0;
        for(int j=0; j<=k; ++j) ret = max(ret, g[n-1][j]);

        return ret;
    }
};
// @lc code=end

//一刷：动态规划，状态dp，和lc123解法相同，注意返回值/初始化/define防越界

