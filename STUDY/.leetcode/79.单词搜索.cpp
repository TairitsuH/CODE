/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
class Solution {
public:
    string s;
    bool check[6][6];
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int M = 0, N = 0;

    bool dfs(vector<vector<char>>& board, int m, int n, int pos)
    {
        if(pos == s.size()) return true;

        for(int i=0; i<4; ++i)
        {
            int x = m + dx[i]; //不要写成m += dx[i]!!!!
            int y = n + dy[i];
            if(x >= 0 && x < M && y >= 0 && y < N && board[x][y] == s[pos] && check[x][y] == false)
            {
                check[x][y] = true;
                if(dfs(board, x, y, pos + 1)) return true;
                check[x][y] = false;
            }
        }

        return false;
    }


    bool exist(vector<vector<char>>& board, string word)
    {
        s = word;
        M = board.size();
        N = board[0].size();

        for(int i=0; i<M; ++i)
        {
            for(int j=0; j<N; ++j)
            {
                if(board[i][j] == word[0])
                {
                    check[i][j] = true;
                    if(dfs(board, i, j, 1)) return true;
                    check[i][j] = false;
                }
            }
        }

        return false;
    }
};
// @lc code=end

//二刷：用了方向数组，尤其注意不要改变原坐标的值！新坐标另外存储！否则会破坏后续循环！
//一刷：递归/回溯，用了四个if来移动有点冗余，下次试试方向数组。细节：check的更新时机，判断下标是否越界等等
//记得提交的时候注释掉cout调试！否则很耗时！
class Solution {
public:
    string s;
    bool check[6][6];

    bool dfs(vector<vector<char>>& board, int m, int n, int pos)
    {
        if(pos == s.size()) return true;

        if(m > 0 && board[m - 1][n] == s[pos] && check[m - 1][n] == false) 
        {
            check[m - 1][n] = true;
            bool ret = dfs(board, m - 1, n, pos + 1);
            check[m - 1][n] = false;
            if(ret) return true;
        }
        if(m < board.size() - 1 && board[m + 1][n] == s[pos] && check[m + 1][n] == false)
        {
            check[m + 1][n] = true;
            bool ret = dfs(board, m + 1, n, pos + 1);
            check[m + 1][n] = false;
            if(ret) return true;
        }
        if(n > 0 && board[m][n - 1] == s[pos] && check[m][n - 1] == false)
        {
            check[m][n - 1] = true;
            bool ret = dfs(board, m, n - 1, pos + 1);
            check[m][n - 1] = false;
            if(ret) return true;
        }
        if(n < board[0].size() - 1 && board[m][n + 1] == s[pos] && check[m][n + 1] == false)
        {
            check[m][n + 1] = true;
            bool ret = dfs(board, m, n + 1, pos + 1);
            check[m][n + 1] = false;
            if(ret) return true;
        }

        return false;
    }


    bool exist(vector<vector<char>>& board, string word)
    {
        int m = board.size();
        int n = board[0].size(); 
        if(m * n < word.size()) return false;

        s = word;
        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                if(board[i][j] == word[0])
                {
                    check[i][j] = true;
                    bool ret = dfs(board, i, j, 1);
                    if(ret) return true;
                    check[i][j] = false;
                }
            }
        }

        return false;
    }
};
