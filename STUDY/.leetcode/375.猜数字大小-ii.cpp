/*
 * @lc app=leetcode.cn id=375 lang=cpp
 *
 * [375] 猜数字大小 II
 */

// @lc code=start
class Solution {
public:
    int memo[201][201];

    int dfs(int left, int right)
    {
        if(left >= right) return 0;

        if(memo[left][right] != 0) return memo[left][right];

        int mincost = INT_MAX;
        for(int i=left; i<=right; ++i)
        {
            int x = dfs(left, i-1);
            int y = dfs(i+1, right);
            mincost = min(max(x, y) + i, mincost);
        }

        memo[left][right] = mincost;

        return mincost;
    }

    int getMoneyAmount(int n)
    {
        return dfs(1, n);
    }
};
// @lc code=end

//二刷：记忆化搜索，题意还是没理解到位，主函数不需要再遍历取最大值了
//一刷：暴搜->记忆化搜索，难点在于题意理解和策略选择，类似"非二"分，枚举分区间的情况，选择花费最小的策略
class Solution {
public:
    int memo[201][201];

    int getMoneyAmount(int n)
    {
        return dfs(1, n); 
    }

    int dfs(int left, int right)
    {
        if(left >= right) return 0;
        if(memo[left][right] != 0) return memo[left][right];

        int ret = INT_MAX;
        for(int i=left; i<=right; ++i)
        {
            int x = dfs(left, i - 1);
            int y = dfs(i + 1, right);
            ret = min(max(x, y) + i, ret);
        }

        memo[left][right] = ret;

        return ret;
    }
};
