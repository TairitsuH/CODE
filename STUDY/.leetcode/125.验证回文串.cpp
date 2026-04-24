/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */
// @lc code=start
class Solution {
public:
    bool isPalindrome(string s)
    {
        string ret = "";
        for(auto ch : s)
        {
            if(isdigit(ch))
            {
                ret += ch;
            }
            if(isalpha(ch))
            {
                ret += tolower(ch);
            }
        }

        string retrev = ret;
        reverse(retrev.begin(), retrev.end());

        if(retrev == ret) return true;

        return false;
    }
};
// @lc code=end

//一刷：不确定的函数一定要看文档！！