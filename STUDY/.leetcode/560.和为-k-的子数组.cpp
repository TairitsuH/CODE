/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k)
    {
        unordered_map<int, int> hash;
        int sum = 0, cnt = 0;
        hash[0] = 1;
        
        for(auto x : nums)
        {
            sum += x;
            if(hash.count(sum - k) == 1)
            {
                cnt += hash[sum - k];
            }

            hash[sum]++;
        }

        return cnt;
    }
};
// @lc code=end

//二刷：了解了大致思路，也从暴力推导了一遍，最重要的还是逆向思维，由前缀和，k想到sum - k再通过哈希表优化枚举而得。
//一刷：前缀和+哈希表的做法，统计子数组和为k的个数即统计从0开始的子区间等于sums[i] - k的个数。
//先算出每个位置的前缀和，再计算这个位置的前缀和-k（sum - k），借此找到这个位置之前符合条件的子数组个数，加入ret中即可
// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k)
//     {
//         unordered_map<int, int> hash;
//         int sum = 0, ret = 0;
//         hash[0] = 1; //前缀和本身等于k的情况（sum - k = 0）

//         for(auto x : nums)
//         {
//             sum += x;
//             if(hash.count(sum - k) != 0)
//             {
//                 ret += hash[sum - k];
//             }

//             hash[sum]++;
//         }

//         return ret;
//     }
// };