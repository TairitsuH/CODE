/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> hash;

        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            int key = target - nums[i];
            if(hash.count(key))
            {
                return {i, hash[key]};
            }

            hash.insert({nums[i], i});
        }

        return {-1, -1};
    }
};
// @lc code=end

//二刷：哈希表，存储cur之前的数，再在哈希表中找组合，时空复杂度都是O(N)
//一刷：暴力枚举，和之前的数配对看是否满足目标值，时间复杂度O(N^2)
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target)
//     {
//         int n = nums.size();

//         for(int i=1; i<n; i++)
//         {
//             for(int j=0; j<i; j++)
//             {
//                 if(target - nums[i] == nums[j])
//                 {
//                     return {i, j};
//                 }
//             }
//         }

//         return {-1, -1};
//     }
// };
