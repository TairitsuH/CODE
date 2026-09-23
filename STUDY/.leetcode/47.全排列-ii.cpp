/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> ret;
    vector<int> path;
    bool check[7];

    void dfs(vector<int> nums)
    {
        if(nums.size() == path.size())
        {
            ret.push_back(path);
            return;
        }

        for(int i=0; i<nums.size(); ++i)
        {
            if(check[i] == false)
            {
                cout << nums[i] << endl;
                check[i] = true;

                path.push_back(nums[i]);
                dfs(nums);

                //回溯+恢复现场
                path.pop_back();
                check[i] = false;

                for(int j=i+1; j<nums.size(); ++j)
                {
                    if(nums[j] == nums[i]) ++i; //剪枝，跳过同层的相同节点
                }
            }
        }
    }


    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        dfs(nums);

        return ret;
    }
};
// @lc code=end
//一刷：先排序，同层剪枝(++i)+纵向剪枝(bool数组)
