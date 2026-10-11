class Solution {
public:
    int massage(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> dp(n + 3);

        for(int i=3; i<n+3; ++i)
        {
            dp[i] = max(dp[i-3], dp[i-2]);
            dp[i] += nums[i-3];
        }    

        return max(dp[n+2], dp[n+1]); //最后两个预约都可能是结果
    }
};

//一刷：动态规划，状态表示为从起点到达该位置的最长预约时长，尤其需要注意状态转移方程和返回值！