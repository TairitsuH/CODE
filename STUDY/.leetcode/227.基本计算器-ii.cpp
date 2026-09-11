/*
 * @lc app=leetcode.cn id=227 lang=cpp
 *
 * [227] 基本计算器 II
 */

class Solution {
public:
    int calculate(string s)
    {
        stack<int> st;
        int n = s.size();
        int i = 0;
        char op = '+';
        while(i < n)
        {
            if(s[i] == ' ')
            {
                ++i;
            }
            else if(s[i] >= '0' && s[i] <= '9')
            {
                int tmp = 0;
                while(i < n && s[i] >= '0' && s[i] <= '9')
                {
                    tmp *= 10;
                    tmp += s[i] - '0';
                    ++i;
                }
                if(op == '+') st.push(tmp);
                else if(op == '-') st.push(-tmp);
                if(op == '*') st.top() *= tmp;
                if(op == '/') st.top() /= tmp;
            }
            else
            {
                op = s[i];
                ++i;
            }
        }

        int ret = 0;
        while(!st.empty())
        {
            ret += st.top();
            st.pop();
        }

        return ret;
    }
};
// @lc code=end

//一刷：栈模拟题，模拟计算过程。注意分类讨论！考虑最后一个数的处理情况，而不是单纯移动指针。有点难度但不多TvT多练习就好