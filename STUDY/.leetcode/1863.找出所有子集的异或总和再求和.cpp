/*
 * @lc app=leetcode.cn id=1863 lang=cpp
 *
 * [1863] 找出所有子集的异或总和再求和
 */

// @lc code=start
class Solution {
public:
    int ret = 0;
    vector<int> path;
    void dfs(vector<int>& nums, int pos)
    {
        int tmp = 0;
        for(auto x : path) tmp ^= x;
        ret += tmp;

        for(int i=pos; i<nums.size(); ++i)
        {
            path.push_back(nums[i]);
            dfs(nums, i + 1);
            path.pop_back();
        }
    }

    int subsetXORSum(vector<int>& nums)
    {
        dfs(nums, 0);
        return ret;
    }
};
// @lc code=end
//一刷：递归，先找到所有的子集，然后计算并相加异或结果

