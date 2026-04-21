/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 */

// @lc code=start
class Solution {
public:
    string addStrings(string num1, string num2)
    {
        string str;

        int pos1 = num1.size() - 1;
        int pos2 = num2.size() - 1;
        int next = 0; //处理进位
        while(pos1 >= 0 || pos2 >= 0) //都为0时才停止
        {
            int ret1 = pos1 >= 0 ? num1[pos1] - '0' : 0;
            int ret2 = pos2 >= 0 ? num2[pos2] - '0' : 0;

            int ret = ret1 + ret2 + next;
            next = ret / 10;
            ret %= 10;

            str += ret + '0';
            pos1--;
            pos2--;
        }

        if(next == 1) str += '1';

        reverse(str.begin(), str.end());
        return str;
    }
};
// @lc code=end

//一刷：思路类似高精度加法OvO
//while的条件一定要深思！区分进循环和出循环，while需要写进循环的条件！
