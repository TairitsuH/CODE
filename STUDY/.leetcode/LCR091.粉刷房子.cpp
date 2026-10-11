class Solution {
public:
    int minCost(vector<vector<int>>& costs)
    {
        int n = costs.size();
        vector<vector<int>> dp(n+1, vector<int>(3));

        for(int i=1; i<n+1; ++i)
        {
            dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + costs[i-1][0];
            dp[i][1] = min(dp[i-1][2], dp[i-1][0]) + costs[i-1][1];
            dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + costs[i-1][2];
        }

        return min({dp[n][0], dp[n][1], dp[n][2]});
    }
};

//一刷：动态规划+简单状态dp，状态表示为粉刷到当前格子所需要的最小花费（开三列，每列代表一种颜色）