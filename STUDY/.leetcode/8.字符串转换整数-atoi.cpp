/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */
// @lc code=start
class Solution {
public:
    int myAtoi(string s)
    {
        int flag = 1;
        int symbol = 0;
        string ret = "";
        for(size_t i=0; i<s.size(); i++)
        {
            if(symbol == 0 && s[i] == ' ')
            {
                continue;
            }
            else if(symbol == 0 && s[i] == '-')
            {
                flag = -1;
                symbol = 1;
            }
            else if(symbol == 0 && s[i] == '+')
            {
                flag = 1;
                symbol = 1;
            }
            else if(s[i] >= '0' && s[i] <= '9')
            {
                while(i < s.size() && s[i] == '0') i++;

                while(i < s.size() && s[i] >= '0' && s[i] <= '9')
                {
                    ret += s[i];
                    i++;
                }
                break;
            }
            else
            {
                return 0;
            }
        }

        if(ret == "") return 0;

        if(ret.size() > 10)
        {
            if(flag == 1) return pow(2, 31) - 1;
            else return -pow(2, 31);
        }
        else
        {
            long long num = stoll(ret);
            if(flag == 1 && num > pow(2, 31) - 1)
            {
                return pow(2, 31) - 1;
            }
            if(flag == -1 && num > pow(2, 31))
            {
                return -pow(2, 31);
            }
            return flag * num;
        }
    }
};
// @lc code=end

//一刷：没招了，面向测试用例的编程。题意描述的很不清晰，基本都是照着测试用例调试改正的，整体不算难，考验耐心