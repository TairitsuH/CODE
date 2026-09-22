/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> ret;
    // vector<bool> check(7, 0); 类内部不能这样声明，会被误认为是函数
    bool check[7];
    vector<int> path;

    void dfs(vector<int>& nums)
    {
        //递归出口
        if(nums.size() == path.size())
        {
            ret.push_back(path);
            return;
        }

        //遍历nums
        for(int i=0; i<nums.size(); ++i)
        {
            if(check[i] == false)
            {
                path.push_back(nums[i]);
                check[i] = true;
                dfs(nums);

                //回溯+恢复现场：在递归子树后（宏观看问题！
                check[i] = false;
                path.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums)
    {
        dfs(nums);
        return ret;
    }
};
// @lc code=end
//一刷：递归，决策时，深搜，剪枝，回溯，理解了思路但是实现方面还差一大截

