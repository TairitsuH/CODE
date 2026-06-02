/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        if(nums.size() == 0) return {-1, -1};
        //左
        int left = 0;
        int right = nums.size() - 1;
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            if(nums[mid] >= target)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }

        if(nums[left] != target) return {-1, -1};
        int ret1 = left;

        //右
        left = 0;
        right = nums.size() - 1;
        while(left < right)
        {
            int mid = left + (right - left + 1) / 2;
            if(nums[mid] <= target)
            {
                left = mid;
            }
            else
            {
                right = mid - 1;
            }
        }

        return {ret1, left};
    }
};
// @lc code=end
//一刷：不错哦，只有一些小细节错了，变量名笔误和漏了讨论数组为空的条件，其他都很完美！
