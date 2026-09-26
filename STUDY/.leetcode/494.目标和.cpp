/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
class Solution {
public:
    int cnt = 0;    

    void dfs(vector<int>& nums, int target, int pos, int path)
    {
        if(pos == nums.size())
        {
            if(path == target) ++cnt;
            return;
        }

        int x = nums[pos];
        dfs(nums, target, pos+1, path+x);
        dfs(nums, target, pos+1, path-x);
    }

    int findTargetSumWays(vector<int>& nums, int target)
    {
        dfs(nums, target, 0, 0);
        return cnt;
    }
};
// @lc code=end
//一刷：递归/回溯，注意不需要用for循环，每条路径都包含每一个元素，不要想当然！

