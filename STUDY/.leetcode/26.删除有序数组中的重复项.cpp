/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        int fast = 0;
    }
};
// @lc code=end

//二刷：对边界情况的分析还需要更仔细。
//一刷：忽略了非严格递增（有重复元素的类递增数组），按照无序做了（新建数组记录次数）TvT
#include<iostream>
#include<vector>
using namespace std;
 // @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        int n = nums.size();
        int slow = 1;
        for(int fast = 1; fast<n; fast++) //从1开始，因为第一个数不会重复，无须判断
        {
            if(nums[fast] != nums[fast-1]) //和前面的数作比较
            {
                nums[slow] = nums[fast];
                slow++;
            }
        }
        return slow;
    }
};