/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
*/

// @lc code=start
class Solution {
public:
    string countAndSay(int n)
    {
        string ret = "1";
        for(int i=1; i<n; i++)
        {
            string tmp;
            int len = ret.size();

            for(int left=0, right=0; right < len;) //分号勿漏
            {
                while(right < len && ret[left] == ret[right])
                {
                    right++;
                }

                tmp += to_string(right - left) + ret[left];
                left = right;
            }

            ret = tmp;
        }

        return ret;
    }
};
// @lc code=end

//一刷：模拟专题真是地狱难度TAT经常出现越界或者思路繁杂的情况