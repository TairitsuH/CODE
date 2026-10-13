/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
class Solution {
public:
    int fib(int n)
    {
        if(n == 0) return 0;
        if(n == 1 || n == 2) return 1;

        vector<int> dp(n+1, 0);
        dp[1] = dp[2] = 1;
        
        for(int i=3; i<n+1; ++i)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }    

        return dp[n];
    }
};
// @lc code=end

//二刷：动态规划，斐波那契类型求值
//一刷：记忆化搜索，用备忘录（memo数组）存储每次计算的值，从暴搜O(2^N)优化为O(N)
class Solution {
public:
    int memo[31]; //下标对应斐波那契数
    
    int dfs(int n)
    {
        if(memo[n] != -1) return memo[n];

        if(n == 0 || n == 1)
        {
            memo[n] = n;
            return memo[n];
        }

        memo[n] = dfs(n - 1) + dfs(n - 2);

        return memo[n];
    }

    int fib(int n)
    {
        memset(memo, -1, sizeof(memo));
        return dfs(n); 
    }
};
