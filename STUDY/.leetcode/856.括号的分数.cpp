/*
 * @lc app=leetcode.cn id=856 lang=cpp
 *
 * [856] 括号的分数
 */

// @lc code=start
class Solution {
public:
    int scoreOfParentheses(string s)
    {
        stack<int> st;
        st.push(0);
        for(auto c : s)
        {
            if(c == '(') st.push(0);
            else
            {
                int tmp = 0;
                if(st.top() == 0) tmp = 1;
                else tmp = st.top() * 2;

                st.pop();
                st.top() += tmp;
            }
        }

        int ret = st.top();
        return ret;
    }
};
// @lc code=end
//一刷：栈模拟，出现括号+数字，想办法统一（用数字表示括号），0表示当前层分数，遇到（的同时入栈
