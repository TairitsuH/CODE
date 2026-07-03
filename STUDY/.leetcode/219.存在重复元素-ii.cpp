/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 */

// @lc code=start
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
        unordered_map<int, int> hash;

        for(int i=0; i<nums.size(); i++)
        {
            if(hash.count(nums[i]))
            {
                if(abs(hash[nums[i]] - i) <= k)
                {
                    return true;
                }

                hash[nums[i]] = i;
            }
            else
            {
                hash.insert({nums[i], i});
            }
        }

        return false;
    }
};
// @lc code=end

//二刷：重新过一遍思路，更加熟练了
//一刷：解法和217类似，需要更新和覆盖下标，因为求绝对值所以一定正确。注意set和map插入的参数不同！
// class Solution {
// public:
//     bool containsNearbyDuplicate(vector<int>& nums, int k)
//     {
//         unordered_map<int, int> hash;

//         for(int i=0; i<nums.size(); i++)
//         {
//             if(hash.count(nums[i]))
//             {
//                 if(abs(hash[nums[i]] - i) <= k)
//                 {
//                     return true;
//                 }

//                 hash[nums[i]] = i;
//             }

//             hash.insert({nums[i], i});
//         }

//         return false;
//     }
// };