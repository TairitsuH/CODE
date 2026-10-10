/*
 * @lc app=leetcode.cn id=931 lang=cpp
 *
 * [931] 下降路径最小和
 */

// @lc code=start
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix)
    {
        int n = matrix.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 2, INT_MAX));    

        for(int j=0; j<n+2; ++j) dp[0][j] = 0;

        int ret = INT_MAX;
        for(int i=1; i<n+1; ++i)
        {
            for(int j=1; j<n+1; ++j)
            {
                dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i - 1][j + 1]});
                dp[i][j] += matrix[i - 1][j - 1];
                if(i == n) ret = min(ret, dp[i][j]);
            }
        }

        return ret;
    }
};
// @lc code=end
//二刷：动态规划，两端拓宽两列+上面拓宽一行，第一行初始化为0其余为INT_MAX。原来min可以通过传入数组来比较！或者也可以min(a,min(a,a))
//一刷：动态规划，数组两端拓宽一列，注意下标映射和初始化
class Solution {
public:
    int cmpmin(int a, int b, int c)
    {
        int tmp = 0;
        if(a > b) swap(a, b);
        if(b > c) swap(b, c);
        if(a > b) swap(a, b);
        return a;
    }

    int minFallingPathSum(vector<vector<int>>& matrix)
    {
        int n = matrix.size();
        if(n == 1) return matrix[0][0];
        int m = n + 2;
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));    
        for(int j=1; j<=n; ++j) dp[0][j] = matrix[0][j - 1];

        int ret = INT_MAX;
        for(int i=1; i<n; ++i)
        {
            for(int j=1; j<=n; ++j)
            {
                dp[i][j] = cmpmin(dp[i - 1][j - 1], dp[i - 1][j], dp[i - 1][j + 1]);
                dp[i][j] += matrix[i][j - 1];
                if(i == n - 1) ret = min(dp[i][j], ret);
            }
        }

        return ret;
    }
};