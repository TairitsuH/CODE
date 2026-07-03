/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        string ret = "";

        for(int i=0; i<n; i++)
        {
            //奇数
            int left = i;
            int right = i;
            ret = Palindrone(s, ret, i, left, right);

            //偶数
            left = i;
            right = i + 1;
            ret = Palindrone(s, ret, i, left, right);
        }

        return ret;
    }

    string Palindrone(string s, string ret, int i, int left, int right)
    {
        int n = s.size();

        while(left >= 0 && right < n && s[left] == s[right])
        {
            left--;
            right++;
        }

        if(ret.size() < right - left - 1)
        {
            ret = s.substr(left+1, right - (left + 1)); //注意substr的用法，第一个参数是起始下标，第二个参数是截取的个数
        }

        return ret;
    }
};
// @lc code=end

//一刷：暴力，枚举数组的每一个下标，以此为中心展开查找回文字符串。