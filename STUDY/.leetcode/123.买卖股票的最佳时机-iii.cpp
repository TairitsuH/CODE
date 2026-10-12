/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        //创建
        #define MIN -0x3f3f3f
        int n = prices.size();
        vector<vector<int>> f(n, vector<int>(3, MIN));
        vector<vector<int>> g(n, vector<int>(3, MIN));

        //初始化
        f[0][0] = -prices[0];
        g[0][0] = 0;

        //填表
        for(int i=1; i<n; ++i)
        {
            for(int j=0; j<=2; ++j)
            {
                f[i][j] = max(f[i-1][j], g[i-1][j] - prices[i]);
                g[i][j] = g[i-1][j];
                if(j >= 1) g[i][j] = max(g[i][j], f[i-1][j-1] + prices[i]);
            }
        }

        //返回值
        int ret = 0;
        for(int j=0; j<=2; ++j) ret = max(g[n-1][j], ret);
        
        return ret;
    }
};

// @lc code=end

//一刷：动态规划，状态dp，通用解法，适用于指定次数交易，注意返回值的初始化/j的范围/max还是min