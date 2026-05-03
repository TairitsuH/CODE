/*
 * @lc app=leetcode.cn id=260 lang=cpp
 *
 * [260] 只出现一次的数字 III
 */

// @lc code=start
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums)
    {
        long long minx = nums[0];
        long long maxx = nums[0];

        for(auto x : nums)
        {
            minx = min(minx, (long long)x);
            maxx = max(maxx, (long long)x);
        }

        size_t size = maxx - minx + 1;
        vector<int> cnt(size, 0);

        for(auto x : nums)
        {
            ++cnt[x - minx]; 
        }

        vector<int> ret;
        for(size_t i=0; i<cnt.size(); i++)
        {
            if(cnt[i] == 1)
            {
                ret.push_back(i + minx);
            }
        }

        return ret;
    }
};
// @lc code=end

//一刷：没什么思路，直接用了计数，结果就是数组太大+超时了