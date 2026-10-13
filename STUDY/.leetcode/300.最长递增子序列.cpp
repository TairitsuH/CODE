/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {
        //创建+初始化
        int n = nums.size();
        vector<int> dp(n, 1);

        //填表
        for(int i=n-1; i>=0; --i)
        {
            for(int j=i+1; j<n; ++j)
            {
                if(nums[j] > nums[i]) dp[i] = max(dp[i], dp[j] + 1);
            }
        }    

        int ret = 1;
        for(int i=0; i<n; ++i) ret = max(dp[i], ret);

        return ret;
    }
};
// @lc code=end

//二刷：动态规划，状态标识为以该位置为起点到结尾的最大递增子序列长度
//一刷：在递归的基础上优化为记忆化搜索，前提是决策树中出现重复部分
class Solution {
public:
    int dfs(vector<int>& nums, vector<int>& memo, int pos)
    {
        if(memo[pos] != 0) return memo[pos];
        
        int n = nums.size();
        int maxlen = 1;
        for(int i=pos+1; i<n; ++i)
        {
            if(nums[i] > nums[pos])
            {
                maxlen = max(dfs(nums, memo, i) + 1, maxlen);
            }
        }

        memo[pos] = maxlen;

        return maxlen;
    }

    int lengthOfLIS(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> memo(n, 0);

        int ret = 0;
        for(int i=0; i<n; ++i)
        {
            ret = max(ret, dfs(nums, memo, i));
        }

        return ret;
    }
};
