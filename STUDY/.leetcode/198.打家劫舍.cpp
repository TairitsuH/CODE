/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> f(n + 1);
        vector<int> g(n + 1);

        for(int i=1; i<=n; ++i)
        {
            f[i] = g[i-1] + nums[i-1];
            g[i] = max(f[i-1], g[i-1]);
        }

        return max(f[n], g[n]);
    }
};
// @lc code=end
//一刷：动态规划，简单状态，状态表示为从起点开始到当前位置的最大预约时长，用两个数组表示该位置选/不选
