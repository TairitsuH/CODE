/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums)
    {
        int ret = 0;
        for(auto x : nums)
        {
            ret ^= x;
        }

        return ret;
    }
};
// @lc code=end

//二刷：位运算，全部异或一遍，相同的数会抵消为0，最后剩下的数就是没有重复的
//一刷：异或思路，自己和自己异或为0，自己和0异或为自己，自己和非0异或为1
// class Solution {
// public:
//     int singleNumber(vector<int>& nums)
//     {
//         int value = 0;
//         for(auto num : nums)
//         {
//             value ^= num;
//         }

//         return value;
//     }
// };