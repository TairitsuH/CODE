/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> ret;
    vector<int> path;

    void dfs(vector<int>& can, int target, int pathsum, int pos)
    {
        if(pathsum >= target)
        {
            if(pathsum == target) ret.push_back(path);
            return;
        }



        for(int i=pos; i<can.size(); ++i)
        {
            path.push_back(can[i]);
            dfs(can, target, pathsum + can[i], i);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        dfs(candidates, target, 0, 0);
        return ret;
    }
};
// @lc code=end
//一刷：递归回溯，注意不能往回选，从当前位置继续向下递归才能做到元素不重复
