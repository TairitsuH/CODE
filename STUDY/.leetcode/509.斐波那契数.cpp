/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
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
// @lc code=end

//一刷：记忆化搜索，用备忘录（memo数组）存储每次计算的值，从暴搜O(2^N)优化为O(N)

