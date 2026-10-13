/*
 * @lc app=leetcode.cn id=329 lang=cpp
 *
 * [329] 矩阵中的最长递增路径
 */

// @lc code=start
class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int memo[201][201];
    int M, N;

    int dfs(vector<vector<int>>& matrix, int m, int n)
    {
        if(memo[m][n] != 0) return memo[m][n];
        int ret = 1;
        for(int i=0; i<4; ++i)
        {
            int x = m + dx[i];
            int y = n + dy[i];

            if(x >= 0 && x < M && y >= 0 && y < N && matrix[x][y] > matrix[m][n])
            {
                ret = max(ret, dfs(matrix, x, y) + 1);
            }
        }

        memo[m][n] = ret;

        return ret;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix)
    {
        M = matrix.size();
        N = matrix[0].size();

        int ret = 0;
        for(int i=0; i<M; ++i)
        {
            for(int j=0; j<N; ++j)
            {
                ret = max(ret, dfs(matrix, i, j));
            }
        }    

        return ret;
    }
};
// @lc code=end

//一刷：暴搜->记忆化搜索+矩阵填数，不需要用check数组保存！（不会重复走同一块格子）

