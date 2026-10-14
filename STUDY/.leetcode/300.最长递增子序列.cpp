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
        int n = nums.size();
        vector<int> dp(n, 0);

        dp[n-1] = 1;

        for(int i=n-2; i>=0; --i)
        {
            int maxlen = 1;
            for(int j=i+1; j<n; ++j)
            {
                if(nums[j] > nums[i]) maxlen = max(dp[j]+1, maxlen);
            }

            dp[i] = maxlen;
        }

        int ret = 0;
        for(int i=0; i<n; ++i) ret = max(ret, dp[i]);

        return ret;
    }
};
// @lc code=end
//四刷：动态规划，注意返回值是需要全部遍历一遍的！
//三刷：记忆化搜索，用memo存储nums对应下标开始到数组末尾的最大递增子序列长度，减少重复运算
class Solution {
public:
    int memo[2501];

    int dfs(vector<int>& nums, int pos)
    {
        if(memo[pos] != 0) return memo[pos];

        int maxlen = 1;
        for(int i=pos+1; i<nums.size(); ++i)
        {
            if(nums[i] > nums[pos]) maxlen = max(dfs(nums, i) + 1, maxlen);
        }

        memo[pos] = maxlen;

        return maxlen;
    }

    int lengthOfLIS(vector<int>& nums)
    {
        int n = nums.size();
        int ret = 0;

        for(int i=0; i<n; ++i) ret = max(dfs(nums, i), ret);
          
        return ret;
    }
};
//二刷：动态规划，状态标识为以该位置为起点到结尾的最大递增子序列长度
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
