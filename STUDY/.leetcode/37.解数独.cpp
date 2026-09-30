/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

// @lc code=start
class Solution {
public:
    bool row[9][10];
    bool col[9][10];
    bool grid[9][9][10];
    int M, N;

    bool dfs(vector<vector<char>>& board)
    {
        for(int i=0; i<M; ++i)
        {
            for(int j=0; j<N; ++j)
            {
                if(board[i][j] != '.') continue;

                for(int k=1; k<=9; ++k)
                {
                    if(!row[i][k] && !col[j][k] && !grid[i/3][j/3][k])
                    {
                        board[i][j] = k + '0';
                        row[i][k] = col[j][k] = grid[i/3][j/3][k] = true;
                        if(dfs(board)) return true;
                        row[i][k] = col[j][k] = grid[i/3][j/3][k] = false;
                        board[i][j] = '.';
                    }
                }

                return false; //1~9没有合适的数字
            }
        }

        return true; //没有.了，全部填满
    }

    void solveSudoku(vector<vector<char>>& board)
    {
        M = board.size();
        N = board[0].size();
        for(int i=0; i<M; ++i)
        {
            for(int j=0; j<N; ++j)
            {
                char c = board[i][j];
                if(c != '.')
                {
                    int x = c - '0';
                    row[i][x] = true;
                    col[j][x] = true;
                    grid[i/3][j/3][x] = true;
                }
            }
        }

        dfs(board);
    }
};
// @lc code=end
//二刷：递归+回溯，思路还是没理顺，函数出口是循环全部走完（没有遇到.），函数剪枝出现在k循环后，表示没有找到合适的数字填入
//一刷：递归/回溯，重点理解返回值的作用和含义！
class Solution {
public:
    bool row[9][10];
    bool col[9][10];
    bool grid[3][3][10];

    bool dfs(vector<vector<char>>& board)
    {
        for(int i=0; i<9; ++i)
        {
            for(int j=0; j<9; ++j)
            {
                if(board[i][j] != '.') continue;
                
                for(int k=1; k<=9; ++k) //找到空位
                {
                    if(row[i][k] == false && col[j][k] == false && grid[i/3][j/3][k] == false)
                    {
                        board[i][j] = k + '0';
                        row[i][k] = col[j][k] = grid[i/3][j/3][k] = true;
                        bool ret = dfs(board);
                        if(ret == true) return true; //找到了对的方法
                        board[i][j] = '.'; //恢复现场！
                        row[i][k] = col[j][k] = grid[i/3][j/3][k] = false;
                    }
                }

                return false; //没有对的方法
            }
        }

        return true;
    }

    void solveSudoku(vector<vector<char>>& board)
    {
        for(int i=0; i<9; ++i)
        {
            for(int j=0; j<9; ++j)
            {
                if(board[i][j] == '.') continue;

                int x = board[i][j] - '0';
                row[i][x] = true;
                col[j][x] = true;
                grid[i/3][j/3][x] = true;
            }
        }  

        dfs(board);
    }
};