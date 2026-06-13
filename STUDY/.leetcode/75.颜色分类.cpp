/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums)
    {
        int n = nums.size();
        for(int left=-1, right=n, i=0; i < right;)
        {
            if(nums[i] == 0)
            {
                swap(nums[++left], nums[i++]);
            }
            else if(nums[i] == 2)
            {
                swap(nums[--right], nums[i]); //不要i++！
            }
            else
            {
                i++;
            }
        }
    }
};
// @lc code=end

//一刷：数组分三块，三指针进行排序，注意left和right的起始位置！