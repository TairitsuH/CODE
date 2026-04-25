/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */

// @lc code=start
class Solution {
public:
    string multiply(string num1, string num2)
    {
        int len = num1.size() + num2.size() + 1;
        vector<int> ret(len, 0);

        //用数组存储相乘结果
        for(int i=num1.size()-1; i>=0; i--)
        {
            int p = num1.size() - 1 - i;
            for(int j=num2.size()-1; j>=0; j--)
            {
                ret[p++] += (num1[i]-'0') * (num2[j]-'0');
            }
        }

        //处理进位
        int next = 0;
        for(int i=0; i<len; i++)
        {
            ret[i] += next;
            next = ret[i] / 10;
            ret[i] %= 10;
        }

        string retstr = "";
        if(next != 0)
        {
            ret[len - 1] = next;
            retstr += to_string(ret[len - 1]);
        }

        //处理前导零
        while(ret[len - 1] == 0 && len > 1)
        {
            len--;
        }

        //倒序放入数组
        for(int i=len-1; i>=0; i--)
        {
            retstr += to_string(ret[i]);
        }

        return retstr;
    }
};
// @lc code=end

//一刷：注意前导零和结果为0时需要保留一位！思路有点复杂，主要还是按照高精度乘法做的

