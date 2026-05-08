/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        return nums[len / 2];
    }
};
// @lc code=end

//一刷：在排序后返回中间位置的元素即可（因为元素个数总是大于一半）