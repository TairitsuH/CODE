/*
 * @lc app=leetcode.cn id=921 lang=cpp
 *
 * [921] 使括号有效的最少添加
 */

// @lc code=start
class Solution {
public:
    int minAddToMakeValid(string s)
    {
        int left = 0, right = 0;
        for(auto c : s)
        {
            if(c == '(') ++left;
            else
            {
                if(left > 0) --left;
                else ++right;
            }
        }    

        return left + right;
    }
};
// @lc code=end
//一刷：栈/模拟栈，遇到左括号计数+1，遇到右括号看是否有左括号匹配，有则--left，没有则++right

