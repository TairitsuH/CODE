/*
 * @lc app=leetcode.cn id=1004 lang=cpp
 *
 * [1004] 最大连续1的个数 III
 */

// @lc code=start
class Solution {
public:
    int longestOnes(vector<int>& nums, int k)
    {
        int n = nums.size();
        int len = 0;
        int zero = 0;
        int left, right;

        for(left=0, right=0; right<n; right++)
        {
            if(nums[right] == 0)
            {
                ++zero;
            }
            while(zero > k)
            {
                len = max(len, right - left);

                if(nums[left] == 0)
                {
                    --zero;
                }
                ++left;
            }
        }

        len = max(len, right - left);
        return len;
    }
};
// @lc code=end
//二刷：“变量职责分离”和“循环不变量”，不要对k进行修改，也不要修改循环中的变量
//一刷：滑动窗口，依据是0的个数
// class Solution {
// public:
//     int longestOnes(vector<int>& nums, int k)
//     {
//         int left = 0;
//         int right = 0;
//         int zerocnt = 0;
//         int len = 0;
//         int n = nums.size();

//         while(right < n)
//         {
//             if(nums[right] == 0)
//             {
//                 zerocnt++;
//             }

//             while(zerocnt > k)
//             {
//                 if(nums[left++] == 0)
//                 {
//                     zero--;
//                 }
//             }

//             len = max(len, right - left + 1);
//             right++;
//         }

//         return len;
//     }
// };