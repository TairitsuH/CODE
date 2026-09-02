/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */
// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums)
    {
        int n = nums.size();
        for(int left=-1, right=0; right < n; right++)
        {
            if(nums[right] != 0)
            {
                left++;
                swap(nums[left], nums[right]);
            }
        }
    }
};

// @lc code=end
//四刷：双指针,left起始位置设置为-1会更好做，另外一定要画图！
//三刷：dest设置在最后一个非零数的位置
// class Solution {
// public:
//     void moveZeroes(vector<int>& nums)
//     {
//         for(int cur=0, dest =-1; cur<nums.size(); cur++)
//         {
//             if(nums[cur] != 0)
//             {
//                 dest++;
//                 swap(nums[cur], nums[dest]);
//             }
//         }  
//     }
// };
//二刷：确定好快慢指针的动向
// class Solution {
// public:
//     void moveZeroes(vector<int>& nums)
//     {
//         int slow = 0;
//         int fast = 0;
//         while(fast < nums.size())
//         {
//             if(nums[fast] != 0)
//             {
//                 swap(nums[slow], nums[fast]);
//                 slow++;
//             }

//             fast++;
//         }
//     }
// };
//一刷；slow指向的是数组中从左往右第一个0的位置，fast跳过0寻找之后不为0的数并与slow交换
// class Solution {
// public:
//     void moveZeroes(vector<int>& nums)
//     {
//         int n = nums.size();
//         int slow = 0;
//         for(int fast=0; fast<n; fast++)
//         {
//             if(nums[fast] != 0)
//             {
//                 swap(nums[slow], nums[fast]);
//                 slow++;
//             }
//         }
//     }
// };