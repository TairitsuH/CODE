/*
 * @lc app=leetcode.cn id=557 lang=cpp
 *
 * [557] 反转字符串中的单词 III
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s)
    {
        int left = 0;
        int right = 0;
        for(auto& ch : s)
        {
            if(ch == ' ')
            {
                reverse(s.begin() + left, s.begin() + right);
                left = right + 1;
            }

            right++;
        }

        reverse(s.begin() + left, s.end());

        return s;
    }
};
// @lc code=end

//一刷：注意left和right是下标，不能用right遍历字符串然后再赋值！这样就逻辑混乱了，应该新建一个ch来遍历
