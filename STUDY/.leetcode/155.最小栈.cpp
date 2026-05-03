/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
class MinStack {
public:
    MinStack()
    {}
    
    void push(int val)
    {
        _num.push(val);
        if(_minnum.empty() || _minnum.top() >= val)
        {
            _minnum.push(val);
        }
    }
    
    void pop()
    {
        if(_num.top() == _minnum.top())
        {
            _minnum.pop();
        }

        _num.pop();
    }
    
    int top()
    {
        return _num.top();
    }
    
    int getMin()
    {
        return _minnum.top();
    }

private:
    stack<int> _num;
    stack<int> _minnum;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

//一刷：思路是创建两个栈，一个正常存储，一个存储栈底和小于等于栈底的数

