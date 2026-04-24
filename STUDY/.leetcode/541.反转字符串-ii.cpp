/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */

// @lc code=start
class Solution {
public:
    string reverseStr(string s, int k)
    {
        if(s.size() <= k)
        {
            reverse(s.begin(), s.end());
            return s;
        }

        int left = 0;
        int right = k;

        while(right <= s.size())
        {
            reverse(s.begin()+left, s.begin()+right);

            left += 2 * k;
            right += 2 * k;
        }

        if(left <= s.size() - 1)
        {
            reverse(s.begin()+left, s.end());
        }

        return s;
    }
};
// @lc code=end

//一刷：发现一边在心里给别人讲解思路一边写代码正确率很高诶！这次不用调试，改了一处小错误就过了^_^

