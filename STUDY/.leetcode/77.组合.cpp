/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> ret;
    vector<int> path;

    void dfs(int n, int k, int num)
    {
        if(path.size() == k)
        {
            ret.push_back(path);
            return;
        }

        for(int i=num; i<=n+path.size()-k+1; ++i) //边界条件剪枝
        {
            path.push_back(i);
            dfs(n, k, i+1);
            path.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k)
    {
        dfs(n, k, 1);
        return ret;
    }
};

// @lc code=end
//一刷：递归，优化了bool数组和边界剪枝，决策树->设计函数->细节处理
