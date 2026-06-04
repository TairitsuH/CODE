/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums)
    {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        int target = nums[0];
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            if(nums[mid] < target) //不能取等，否则过不了[2,1]样例
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }

        if(left == n - 1 && target < nums[left]) return target;
        return nums[left];
    }
};
// @lc code=end

//二刷：试了试把第一个元素设置为target，误打误撞过了，但还是不太理解原理
//一刷：思路是把数组分为两段，以数组最后一个元素为参照数，比较并缩短边界。好麻烦的边界条件TvT
// class Solution {
// public:
//     int findMin(vector<int>& nums)
//     {
//         int n = nums.size();
//         int left = 0;
//         int right = n - 1;
//         int target = nums[n - 1];
//         while(left < right)
//         {
//             int mid = left + (right - left) / 2;
//             if(nums[mid] > target)
//             {
//                 left = mid + 1;
//             }
//             else
//             {
//                 right = mid;
//             }
//         }

//         return nums[left];
//     }
// };