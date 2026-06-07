/*
 * @lc app=leetcode.cn id=974 lang=cpp
 *
 * [974] 和可被 K 整除的子数组
 */

// @lc code=start
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k)
    {
        int sum = 0, ret = 0;
        unordered_map<int, int> hash;
        hash[0] = 1; //0这个数的余数

        for(auto x : nums)
        {
            sum += x;
            if(hash.count((sum % k + k) % k) == 1)
            {
                ret += hash[(sum % k + k) % k];
            }

            hash[(sum % k + k) % k]++;
        }

        return ret;
    }
};
// @lc code=end

//二刷：根据同余定理和负数取模的规则，选择用前缀和+哈希表的方式解题。
//一刷：暴力解法，可以过70/76但是超时了
// class Solution {
// public:
//     int subarraysDivByK(vector<int>& nums, int k)
//     {
//         int n = nums.size();
//         int ret = 0;

//         for(int i=0; i<n; i++)
//         {
//             int left = i, right = i;
//             int sum = 0;
//             while(right < n)
//             {   
//                 sum += nums[right];
//                 if(sum % k == 0)
//                 {
//                     ret++;
//                 }

//                 right++;
//             }
//         }

//         return ret;
//     }
// };