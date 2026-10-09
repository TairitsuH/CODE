/*
 * @lc app=leetcode.cn id=1137 lang=cpp
 *
 * [1137] 第 N 个泰波那契数
 */

// @lc code=start
class Solution {
public:
    int tribonacci(int n) 
    {
        //1.创建dp表
        //2.初始化
        //3.填表
        //4.返回值

        //空间优化
        if(n == 0) return 0;
        if(n == 1) return 1;
        if(n == 2) return 1;

        int a = 0, b = 1, c = 1, d = 0;
        for(int i=3; i<=n; ++i)
        {
            d = a + b + c;
            a = b;
            b = c;
            c = d;
        }

        return d;
    }
};
// @lc code=end
//二刷：dp+空间优化（滚动数组）
//一刷：动态规划入门题，牢记步骤即可
class Solution {
public:
    int tribonacci(int n) 
    {
        //1.创建dp表
        //2.初始化
        //3.填表
        //4.返回值

        vector<int> dp(38); //如果开n+1大小，需要分类讨论n为01的情况，否则初始化会越界

        dp[0] = 0, dp[1] = 1, dp[2] = 1;

        for(int i=3; i<=n; ++i)
        {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }

        return dp[n];
    }
};
