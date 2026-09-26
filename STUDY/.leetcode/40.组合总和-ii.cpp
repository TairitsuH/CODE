/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> ret;
    vector<int> path;
    
    void dfs(vector<int>& can, int target, int sum, int pos)
    {
        if(sum >= target || pos == can.size())
        {
            if(sum == target) ret.push_back(path);
            return;
        }

        for(int i=pos; i<can.size(); ++i)
        {
            path.push_back(can[i]);
            dfs(can, target, sum + can[i], i + 1);
            while(i < can.size()-1 && can[i] == can[i+1]) ++i; //过滤相同元素
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, 0);
        return ret;
    }
};
// @lc code=end

//一刷：递归+回溯，注意在每次循环递归结束后，跳过相同元素（避免重复
