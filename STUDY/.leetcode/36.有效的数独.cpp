/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
class Solution {
public:
    bool row[9][10];
    bool col[9][10];
    bool grid[3][3][10];

    
    bool isValidSudoku(vector<vector<char>>& board)
    {
        for(int i=0; i<9; ++i)
        {
            for(int j=0; j<9; ++j)
            {
                if(board[i][j] == '.') continue;
                
                int x = board[i][j] - '0';
                
                if(row[i][x] == true || col[j][x] == true || grid[i/3][j/3][x] == true) return false;
                
                row[i][x] = true;
                col[j][x] = true;
                grid[i/3][j/3][x] = true;
            }
        }

        return true;
    }
};
// @lc code=end

//一刷：用三个数组（哈希表）表示行/列/每个九宫格，遍历数组逐个填入