/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
public:
    vector<string> ret;
    string path;

    void dfs(int n, int left, int right)
    {
        if(left == n && right == n)
        {
            ret.push_back(path);
            return;
        }

        if(left >= right)
        {
            if(left < n)
            {
                path += '(';
                dfs(n, left + 1, right);
                path.pop_back();
            }
            
            path += ')';
            dfs(n, left, right + 1);
            path.pop_back();
        }
    }

    vector<string> generateParenthesis(int n)
    {
        dfs(n, 0, 0);
        return ret; 
    }
};
// @lc code=end
//一刷：递归dfs，注意有效括号==数量+从头开始左>=右


