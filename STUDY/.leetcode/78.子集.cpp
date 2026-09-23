/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> ret;
    vector<int> path;

    void dfs(vector<int>& nums, int pos)
    {
        ret.push_back(path);

        for(int i=pos; i<nums.size(); ++i)
        {
            path.push_back(nums[i]);
            dfs(nums, i + 1); //下一次递归从i+1的位置开始进数组
            path.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums)
    {
        dfs(nums, 0);
        return ret;
    }
};
// @lc code=end

//二刷：递归/回溯，解法二，每次进函数时push_back（循环内持续递归，穷尽每一种结果
//一刷：递归/回溯，顺序为画出决策树->分析函数头->子过程->递归出口->细节处理即可（根据选/不选判断
class Solution {
public:
    vector<vector<int>> ret;
    vector<int> push;
    bool check[7];

    void dfs(vector<int>& nums)
    {
        if(nums.size() == push.size())
        {
            ret.push_back(push);
            return;
        }

        for(int i=0; i<nums.size(); ++i)
        {
            if(check[i] == false)
            {
                check[i] = true;
                push.push_back(nums[i]);

                dfs(nums);

                //回溯+恢复现场
                check[i] = false;
                push.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums)
    {
        dfs(nums);
        return ret;
    }
};
