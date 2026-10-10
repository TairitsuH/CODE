/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

// @lc code=start
class Solution {
public:
    int numDecodings(string s)
    {
        //创建
        int n = s.size();
        vector<int> dp(n + 1);
        
        //初始化
        dp[0] = 1;

        if(s[0] == '0') return 0;
        dp[1] = 1;

        //填表
        for(int i=2; i<=n; ++i)
        {
            int tmp = (s[i - 2] - '0') * 10 + s[i - 1] - '0';

            if(tmp >= 10 && tmp <= 26) dp[i] += dp[i - 2];
            if(s[i - 1] != '0') dp[i] += dp[i - 1];
        }

        //返回
        return dp[n];
    }
};
// @lc code=end

//三刷：在二刷的解法基础上优化了return 0的步骤，更简洁了
//二刷：在一刷的基础上整合了判断合法条件，添加辅助结点，需要注意映射关系和dp值要保证后面节点正确
class Solution {
public:
    int numDecodings(string s)
    {
        int n = s.size();
        vector<int> dp(n + 1);
        
        dp[0] = 1; //设置为1确保接下来填值的正确性
        if(s[0] == '0') return 0;
        if(n == 1) return 1;
        dp[1] = 1;

        for(int i=2; i<=n; ++i)
        {
            int t = (s[i - 2] - '0') * 10 + s[i - 1] - '0';
            if(t > 26 && s[i - 1] == '0') return 0;
            if(t >= 10 && t <= 26) dp[i] += dp[i - 2];
            if(s[i - 1] != '0') dp[i] += dp[i - 1];
        }

        return dp[n];
    }
};

//一刷：斐波那契dp，细节很多，分类讨论也很多，一定要自己模拟画图！dp状态表示以i位置为结尾时编码的种类数
class Solution {
public:
    int numDecodings(string s)
    {
        int n = s.size();
        vector<int> dp(n);

        if(s[0] == '0') return 0; //条件不满足时直接返回
        if(n == 1) return 1; //数据范围
        dp[0] = 1;

        int t = (s[0] - '0') * 10 + s[1] - '0';
        if(t > 26 && s[1] == '0') return 0;
        if(t >= 10 && t <= 26) dp[1] += 1;
        if(s[1] != '0') dp[1] += 1;

        for(int i=2; i<n; ++i)
        {
            int t = (s[i - 1] - '0') * 10 + s[i] - '0';
            if(t > 26 && s[i] == '0') return 0;
            if(t >= 10 && t <= 26) dp[i] += dp[i - 2];
            if(s[i] != '0') dp[i] += dp[i - 1];
        }

        return dp[n - 1];
    }
};