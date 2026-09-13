/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */

// @lc code=start
class Solution {
public:
    string decodeString(string s)
    {
        int n = s.size();
        stack<string> sts;
        stack<int> sti;
        sts.push("");

        int i = 0;
        while(i < n)
        {
            if(s[i] >= '0' && s[i] <= '9')
            {
                int tmp = 0;
                while(s[i] >= '0' && s[i] <= '9')
                {
                    tmp *= 10;
                    tmp += s[i] - '0';
                    ++i;
                }
                sti.push(tmp);
            }
            else if(s[i] == '[')
            {
                ++i;
                string in;
                while(s[i] >= 'a' && s[i] <= 'z')
                {
                    in += s[i];
                    ++i;
                }
                sts.push(in);
            }
            else if(s[i] == ']')
            {
                int num = sti.top();
                sti.pop();
                string str = sts.top();
                sts.pop();

                string in;
                while(num--)
                {
                    in += str;
                }

                sts.top() += in;
                ++i;
            }
            else
            {
                string in;
                while(i < n && s[i] >= 'a' && s[i] <= 'z') //i < n防止越界
                {
                    in += s[i];
                    ++i;
                }
                sts.top() += in;
            }
        }

        return sts.top();
    }
};
// @lc code=end
//一刷：栈模拟，分类讨论要完全！不要贸然把两种情况合到一起，仔细读题。
