/*
 * @lc app=leetcode.cn id=227 lang=cpp
 *
 * [227] 基本计算器 II
 */

class Solution {
public:
    int calculate(string s)
    {
        int i = 0;
        int n = s.size();
        char op = '+';
        vector<int> v;
        while(i < n)
        {
            //数字
            if(s[i] >= '0' && s[i] <= '9')
            {
                int tmp = 0;
                while(i < n && s[i] >='0' && s[i] <= '9')
                {
                    tmp *= 10;
                    tmp += s[i] - '0';
                    ++i;
                }
                if(op == '+')
                {
                    v.emplace_back(tmp);
                }
                else if(op == '-')
                {
                    v.emplace_back(-tmp);
                }
                else if(op == '*')
                {
                    v.back() *= tmp;
                }
                else
                {
                    v.back() /= tmp;
                }
            }
            else if(s[i] == ' ')
            {
                ++i;
            }
            else
            {
                op = s[i];
                ++i;
            }
        }

        int ret = 0;
        for(auto x : v)
        {
            ret += x;
        }

        return ret;
    }
};
// @lc code=end
//二刷：数组模拟栈，最后的累加更简洁。分类讨论清晰了很多
//一刷：栈模拟题，模拟计算过程。注意分类讨论！考虑最后一个数的处理情况，而不是单纯移动指针。有点难度但不多TvT多练习就好
// class Solution {
// public:
//     int calculate(string s)
//     {
//         stack<int> st;
//         int n = s.size();
//         int i = 0;
//         char op = '+';
//         while(i < n)
//         {
//             if(s[i] == ' ')
//             {
//                 ++i;
//             }
//             else if(s[i] >= '0' && s[i] <= '9')
//             {
//                 //先把数字提取出来
//                 int tmp = 0;
//                 while(i < n && s[i] >= '0' && s[i] <= '9') //循环内部已经把i移到下一个位置了，不需要再动i
//                 {
//                     tmp *= 10;
//                     tmp += s[i] - '0';
//                     ++i;
//                 }
//                 if(op == '+') st.push(tmp);
//                 else if(op == '-') st.push(-tmp);
//                 if(op == '*') st.top() *= tmp;
//                 if(op == '/') st.top() /= tmp;
//             }
//             else
//             {
//                 op = s[i];
//                 ++i;
//             }
//         }

//         int ret = 0;
//         while(!st.empty())
//         {
//             ret += st.top();
//             st.pop();
//         }

//         return ret;
//     }
// };