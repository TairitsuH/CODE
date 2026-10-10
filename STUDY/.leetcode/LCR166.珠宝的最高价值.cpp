class Solution {
public:
    int jewelleryValue(vector<vector<int>>& frame)
    {
        int m = frame.size();
        int n = frame[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        for(int i=1; i<=m; ++i)
        {
            for(int j=1; j<=n; ++j)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                dp[i][j] += frame[i - 1][j - 1];
            }
        }

        return dp[m][n];
    }
};

//动态规划，细节：注意max比较的对象/下标的映射关系/是否需要初始化/何时用到原数组