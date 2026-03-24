/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        int n = nums.size();
        int sum = 0;
        int ret = INT32_MAX;
        int i = 0;
        for(int j=0; j<n; j++)
        {
            sum += nums[j];
            while(sum >= target)
            {
                int len = j - i + 1;
                ret = ret < len ? ret : len;
                sum -= nums[i];
                i++; //或者合并：sum -= nums[i++];
            }
        }
        return ret == INT32_MAX ? 0 : ret;
    }
};
// @lc code=end

//一刷：暴力，正确但超时了
// class Solution {
// public:
//     int minSubArrayLen(int target, vector<int>& nums)
//     {
//         int n = nums.size();
//         int minlen = 1e5 + 10;
//         for(int i=0; i<n; i++)
//         {
//             int sum = 0;
//             for(int j=0; j<n-i; j++)
//             {
//                 sum += nums[j+i];
//                 if(sum >= target)
//                 {
//                     minlen = min(minlen, j + 1);
//                     break;
//                 }
//             }
//         }
//         if(minlen > 1e5) return 0;
//         return minlen;
//     }
// };
//二刷：滑动窗口（有点类似双指针，但是更像窗口移动），很喜欢评论区大佬的解读（花钱和赚钱
//复盘：感觉滑动窗口的重点还是指针的初始位置，if或while的条件判断，以及指针的移动方式