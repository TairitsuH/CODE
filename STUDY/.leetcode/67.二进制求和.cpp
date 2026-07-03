/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b)
    {
        string ret = "";
        int m = a.size();
        int n = b.size();
        int next = 0;

        for(int cur1 = m - 1, cur2 = n - 1; cur1 >= 0 || cur2 >= 0; cur1--, cur2--)
        {
            if(cur1 >= 0)
            {
                next += a[cur1] - '0';
            }
            if(cur2 >= 0)
            {
                next += b[cur2] - '0';
            }

            ret += next % 2 + '0';
            next /= 2;
        }

        while(next > 0)
        {
            ret += next % 2 + '0';
            next /= 2;
        }

        reverse(ret.begin(), ret.end());

        return ret;
    }
};
// @lc code=end

//一刷：需要逆置ret，另外注意for循环中判断结束的条件是||！
