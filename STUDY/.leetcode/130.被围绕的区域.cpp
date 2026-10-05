/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int M, N;

    void dfs(vector<vector<char>>& board, int m, int n)
    {
        board[m][n] = '.';

        for(int i=0; i<4; ++i)
        {
            int x = dx[i] + m;
            int y = dy[i] + n;

            if(x >= 0 && x < M && y >= 0 && y < N && board[x][y] == 'O')
            {
                board[x][y] = '.';
                dfs(board, x, y);
            }
        }
    }

    void solve(vector<vector<char>>& board)
    {
        M = board.size();
        N = board[0].size();

        for(int i=0; i<M; ++i)
        {
            if(board[i][0] == 'O') dfs(board, i, 0);
            if(board[i][N-1] == 'O') dfs(board, i, N - 1);
        }

        for(int j=0; j<N; ++j)
        {
            if(board[0][j] == 'O') dfs(board, 0, j);
            if(board[M-1][j] == 'O') dfs(board, M-1, j);
        }

        for(int i=0; i<M; ++i)
        {
            for(int j=0; j<N; ++j)
            {
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == '.') board[i][j] = 'O';
            }
        }
    }  
};
// @lc code=end

//一刷：floodfill算法，正难则反，先用.标记所有与边界相连的O，再遍历，将中间的O变为X，.变为O
