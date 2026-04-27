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
        int value = 0;
        for(auto num : nums)
        {
            value ^= num;
        }

        return value;
    }
};
// @lc code=end

//一刷：异或思路，自己和自己异或为0，自己和0异或为自己，自己和非0异或为1