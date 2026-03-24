/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */
#include<iostream>
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums)
    {
        int n = nums.size();
        int slow = 0;
        for(int fast=0; fast<n; fast++)
        {
            if(nums[fast] != 0)
            {
                swap(nums[slow], nums[fast]);
                slow++;
            }
        }
    }
};
// @lc code=end
//复盘；slow指向的是数组中从左往右第一个0的位置，fast跳过0寻找之后不为0的数并与slow交换
