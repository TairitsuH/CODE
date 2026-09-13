/*
 * @lc app=leetcode.cn id=946 lang=cpp
 *
 * [946] 验证栈序列
 */

// @lc code=start
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped)
    {
        stack<int> st;
        int n = pushed.size();
        int m = popped.size();
        if(n != m) return false;

        int pu = 0;
        int po = 0;
        while(pu < n)
        {
            while((!st.size() || st.top() != popped[po]) && pu < n)
            {
                st.push(pushed[pu++]);
            }

            while(st.size() && st.top() == popped[po])
            {
                st.pop();
                ++po;
            }
        }  

        return st.size() == 0;  
    }
};
// @lc code=end

//一刷：栈模拟，很考验条件判断的能力，一定要手动模拟！