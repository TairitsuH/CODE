/*
 * @lc app=leetcode.cn id=724 lang=cpp
 *
 * [724] 寻找数组的中心下标
 */

// @lc code=start
class Solution {
public:
    int pivotIndex(vector<int>& nums) 
    {
        int n = nums.size();

        for(int i=1; i<n; i++)
        {
            nums[i] += nums[i-1];
        }

        for(int i=0; i<n; i++)
        {
            int left, right;
            i == 0 ? left = 0 : left = nums[i - 1]; 

            i == n - 1 ? right = 0 : right = nums[n - 1] - nums[i];

            if(left == right) return i;
        }

        return -1;
    }
};
// @lc code=end

//一刷：前缀和的思想，枚举每个下标都要计算左右区间的和，因此用前缀和预处理来优化