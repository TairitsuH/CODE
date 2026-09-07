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
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int m = num1.size();
        int n = num2.size();
        vector<int> v(m + n - 1, 0); //注意开空间的大小

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                v[i + j] += (num1[i] - '0') * (num2[j] - '0');
            }
        }

        //处理进位
        int cur = 0;
        int next = 0;
        string ret = "";
        while(cur < m + n - 1 || next)
        {
            if(cur < m + n - 1)
            {
                next += v[cur++];
            }
            ret += next % 10 + '0';
            next /= 10;
        }

        //处理前导零（对乘数为零的特殊处理）
        while(ret.size() > 1 && ret.back() == '0')
        {
            ret.pop_back();
        }

        reverse(ret.begin(), ret.end());

        return ret;
    }
};

// @lc code=end

//二刷：无进位相乘后相加->处理进位->处理前导零（乘数为0的情况）
//一刷：注意前导零和结果为0时需要保留一位！思路有点复杂，主要还是按照高精度乘法做的
// class Solution {
// public:
//     string multiply(string num1, string num2)
//     {
//         int len = num1.size() + num2.size() + 1;
//         vector<int> ret(len, 0);

//         //用数组存储相乘结果
//         for(int i=num1.size()-1; i>=0; i--)
//         {
//             int p = num1.size() - 1 - i;
//             for(int j=num2.size()-1; j>=0; j--)
//             {
//                 ret[p++] += (num1[i]-'0') * (num2[j]-'0');
//             }
//         }

//         //处理进位
//         int next = 0;
//         for(int i=0; i<len; i++)
//         {
//             ret[i] += next;
//             next = ret[i] / 10;
//             ret[i] %= 10;
//         }

//         string retstr = "";
//         if(next != 0)
//         {
//             ret[len - 1] = next;
//             retstr += to_string(ret[len - 1]);
//         }

//         //处理前导零
//         while(ret[len - 1] == 0 && len > 1)
//         {
//             len--;
//         }

//         //倒序放入数组
//         for(int i=len-1; i>=0; i--)
//         {
//             retstr += to_string(ret[i]);
//         }

//         return retstr;
//     }
// };

