/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
class Solution {
public:
    int memo[101][101];
    int M, N;

    int dfs(int x, int y)
    {
        //越界
        if(x == 0 || y == 0) return 0;

        //起点
        if(x == 1 && y == 1)
        {
            memo[x][y] = 1;
            return 1;
        }

        //其余
        if(memo[x][y] != 0) return memo[x][y];

        return memo[x][y] = dfs(x - 1, y) + dfs(x, y - 1);
    }

    int uniquePaths(int m, int n)
    {
        M = m, N = n;
        return dfs(m, n);
    }
};
// @lc code=end
//二刷：最好memset一下，另外不要忘记在dfs前先去memo表里看看
//一刷：暴搜->优化为记忆化搜索，递归算法，通过path数组记录走到当前位置的总路径数，不断递归即可（注意为防止越界，数组实际上从1开始计数）

class Solution {
public:
    int path[101][101];
    int M, N;

    int dfs(int i, int j)
    {
        if(i == 0 || j == 0) return 0;
        if(i == 1 && j == 1) return 1;
        
        if(path[i][j] != -1) return path[i][j];
        
        path[i][j] = dfs(i - 1, j) + dfs(i, j - 1);

        return path[i][j];
    }

    int uniquePaths(int m, int n)
    {
        memset(path, -1, sizeof(path));
        return dfs(m, n);
    }
};