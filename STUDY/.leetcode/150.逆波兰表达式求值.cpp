/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens)
    {
        stack<int> st;

        map<string, function<int(int, int)>> FuncStr = 
        {
            {"+", [](int x, int y){return x + y;}},
            {"-", [](int x, int y){return x - y;}},
            {"*", [](int x, int y){return x * y;}},
            {"/", [](int x, int y){return x / y;}}
        };

        for(auto& s : tokens)
        {
            if(FuncStr.count(s))
            {
                int right = st.top();
                st.pop();
                int left = st.top();
                st.pop();

                st.push(FuncStr[s](left, right));
            }
            else
            {
                st.push(stoi(s));
            }
        }

        return st.top();
    }
};
// @lc code=end

//二刷：栈模拟+function包装器+lambda+initializer_list
//一刷：栈模拟，注意边界条件
class Solution {
public:
    int evalRPN(vector<string>& tokens)
    {
        stack<int> st;
        int n = tokens.size();
        int i = 0;
        while(i < n)
        {
            if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/")
            {
                st.push(stoi(tokens[i]));
            }
            else
            {
                int right = st.top();
                st.pop();

                if(tokens[i] == "+") st.top() += right;
                else if(tokens[i] == "-") st.top() -= right;
                else if(tokens[i] == "*") st.top() *= right;
                else st.top() /= right;
            }

            ++i;
        }

        return st.top();
    }
};
