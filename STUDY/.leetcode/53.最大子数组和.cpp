/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */
 
// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> dp(n + 1, INT_MIN);
        dp[0] = 0;

        for(int i=1; i<=n; ++i)
        {
            dp[i] = max(nums[i-1], dp[i-1] + nums[i-1]);
            cout << dp[1] << endl;
        }    

        int ret = INT_MIN;
        for(int i=1; i<=n; ++i) ret = max(ret, dp[i]);
        
        return ret;
    }
};
// @lc code=end

//一刷：动态规划，状态表示为以该位置为结尾最大的子数组和，注意最后遍历的时候不要把dp[0]遍历进去！
