/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums)
    {
        int n = nums.size();
        int left = 0, right = n - 1;
        vector<int> ret(n);

        for(int i = n-1; i>=0; i--) //从两端向中间枚举
        {
            if(nums[left]*nums[left] > nums[right]*nums[right])
            {
                ret[i] = nums[left]*nums[left];
                left++;
            }
            else
            {
                ret[i] = nums[right]*nums[right];
                right--;
            }
        }
        return ret;
    }
};
// @lc code=end

//一刷：暴力，先计算再对原数组排序，时间复杂度O(nlogn)，空间复杂度O(logn)，但是并未利用升序数组的特点
// class Solution {
// public:
//     vector<int> sortedSquares(vector<int>& nums)
//     {
//         int n = nums.size();
//         for(int i=0; i<n; i++)
//         {
//             nums[i] = nums[i] * nums[i];
//         }
//         sort(nums.begin(), nums.end());
//         return nums;
//     }
// };
//（提示：正数平方后为升序数组，负数平方后为降序数组，有正有负则呈V形)
//二刷：利用双指针从首尾两端比较，放入新建数组中。（for循环里是i--！！被硬控了好久TvT）

