class Solution {
public:
    long long m = 1e9 + 7;

    int waysToStep(int n)
    {
        if(n == 1) return 1;
        if(n == 2) return 2;
        if(n == 3) return 4; 

        //1.创建dp表
        vector<long long> dp(n + 1);

        //2.初始化
        dp[1] = 1, dp[2] = 2, dp[3] = 4;    

        //3.填表
        for(int i=4; i<=n; ++i)
        {
            dp[i] = dp[i - 3] % m + dp[i - 2] % m + dp[i - 1] % m;
        }

        //4.返回值
        return dp[n] % m;
    }
};

//一刷：动态规划，注意取模，空间优化适用面试讲解思路，笔试不强求（解题第一位）