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
        int left = 0;
        int right = 0;
        int zero = 0;
        int maxlen = 0;
        int n = nums.size();

        while(right < n)
        {
            if(nums[right] == 0)
            {
                zero++;
            }

            while(zero > k)
            {
                if(nums[left++] == 0)
                {
                    zero--;
                }
            }

            maxlen = max(maxlen, right - left + 1);
            right++;
        }

        return maxlen;
    }
};
// @lc code=end
//一刷：滑动窗口，依据是0的个数
