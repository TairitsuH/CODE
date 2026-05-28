/*
 * @lc app=leetcode.cn id=1658 lang=cpp
 *
 * [1658] 将 x 减到 0 的最小操作数
 */

// @lc code=start
class Solution {
public:
    int minOperations(vector<int>& nums, int x)
    {
        int left = 0, right = 0, minlen = INT_MAX;
        long long sum = 0;
        int arrsum = 0;
        int n = nums.size();

        // 求和
        for (auto i : nums)
        {
            arrsum += i;
        }
        long long key = arrsum - x;
        if(key < 0) return -1; //所有的数加起来都比x小，则不成立（滑动窗口仅支持大于零的元素）

        while (right < n)
        {
            sum += nums[right];
            
            while (sum > key) //注意>的判断要在==前
            {
                sum -= nums[left++];
            }
        
            if (sum == key)
            {
                int len = n - (right - left + 1);
                minlen = min(minlen, len);
            }

            right++;
        }

        return minlen == INT_MAX ? -1 : minlen;
    }
};

// @lc code=end
//一刷：正难则反，滑动窗口。找中间和为arrsum-x的最大区间，剩下的元素即为和为x的最小个数
