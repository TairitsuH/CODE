/*
 * @lc app=leetcode.cn id=529 lang=cpp
 *
 * [529] 扫雷游戏
 */

// @lc code=start
class Solution {
public:
    int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
    int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};
    int M, N;

    void dfs(vector<vector<char>>& board, int m, int n)
    {
        //统计雷个数
        int cnt = 0;
        for(int i=0; i<8; ++i)
        {
            int x = dx[i] + m;
            int y = dy[i] + n;

            if(x >= 0 && x < M && y >= 0 && y < N && board[x][y] == 'M') ++cnt;
        }

        //修改本方格
        if(cnt == 0) board[m][n] = 'B';
        else
        {
            board[m][n] = '0' + cnt;
            return;
        }

        //非数字继续递归
        for(int i=0; i<8; ++i)
        {
            int x = dx[i] + m;
            int y = dy[i] + n;
            if(x >= 0 && x < M && y >= 0 && y < N && board[x][y] == 'E')
            {
                dfs(board, x, y);
            }
        }
    }

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click)
    {
        M = board.size();
        N = board[0].size();

        if(board[click[0]][click[1]] == 'M')    
        {
            board[click[0]][click[1]] = 'X';
            return board;
        }

        dfs(board, click[0], click[1]);
        return board;
    }
};
// @lc code=end
//一刷：递归floodfill算法，真的没有那么难[]~(￣▽￣)~*！除了一些笔误/编译错误都没问题！创新点在于dx和dy变成周围一圈，
//另外关于扫雷规则：遇到数字停止递归/周围无雷则继续递归

