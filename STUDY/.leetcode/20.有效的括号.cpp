/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    vector<string> ret;
    string path;

    void dfs(int left, int right, int n)
    {
        if(left == n && right == n)
        {
            ret.push_back(path);
            return;
        }

        if(left > right)
        {
            if(left < n)
            {
                path += '(';
                dfs(left + 1, right, n);
                path.pop_back();
            }
            
            path += ')';
            dfs(left, right + 1, n);
            path.pop_back();
        }
        else if(left == right)
        {
            path += '(';
            dfs(left + 1, right, n);
            path.pop_back();
        }
    }

    vector<string> generateParenthesis(int n)
    {
        dfs(0, 0, n);
        return ret;
    }
};
// @lc code=end
//二刷：递归，分类讨论，ret和path作为全局变量，注意left>right内部的分类讨论
//一刷：递归，使用left，right作为函数参数记录左/右括号数量
class Solution {
public:
    vector<string> ret;
    string path;
    void dfs(int left, int right, int n)
    {
        if(left == n && right == n)
        {
            ret.push_back(path);
            return;
        }

        if(left > right)
        {
            if(left < n)
            {
                path += '(';
                dfs(left + 1, right, n);
                path.pop_back();
            }
            
            path += ')';
            dfs(left, right + 1, n);
        }
        else
        {
            path += '(';
            dfs(left + 1, right, n);
        }

        path.pop_back();
    }

    vector<string> generateParenthesis(int n)
    {
        dfs(0, 0, n);
        return ret;
    }
};
//有效括号：1.左括号数量==右括号数量 2.从头开始的子串，左括号数>=右括号数

