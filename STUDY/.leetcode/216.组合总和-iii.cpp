/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> ret;
    vector<int> path;

    void dfs(int k, int n, int num, int sum)
    {
        if(num > 9 || path.size() == k)
        {
            if(path.size() == k && sum == n) ret.push_back(path);
            return;
        }

        for(int i=num; i<=9; ++i)
        {
            path.push_back(i);
            dfs(k, n, i+1, sum+i);
            path.pop_back();
        }
    }


    vector<vector<int>> combinationSum3(int k, int n)
    {
        dfs(k, n, 1, 0);
        return ret;
    }
};
// @lc code=end
//一刷：递归+回溯，注意只能在1~9之间选，另外注意入ret的条件需要双重判断

