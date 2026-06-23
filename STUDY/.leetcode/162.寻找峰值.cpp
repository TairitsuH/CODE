/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */

// @lc code=start
class Solution {
public:
    int findPeakElement(vector<int>& nums)
    {
        int n = nums.size();
        int left = 0;
        int right = n - 1;

        while(left < right)
        {
            int mid = left + (right - left) / 2;
            if(nums[mid] >= nums[mid + 1])
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }

        return left;
    }
};
// @lc code=end
//一刷：二分查找（二段性，峰值在中间值较大的一侧）