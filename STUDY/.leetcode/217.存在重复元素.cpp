/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */

// @lc code=start
class Solution {
public:
    bool containsDuplicate(vector<int>& nums)
    {
        unordered_set<int> hash;

        for(auto x : nums)
        {
            if(hash.count(x))
            {
                return true;
            }

            hash.insert(x);
        }

        return false;
    }
};
// @lc code=end

//二刷：注意什么时候用set，什么时候用map！
//一刷：哈希表，一边遍历一边存储
// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums)
//     {
//         unordered_set<int> heap;

//         for(auto x : nums)
//         {
//             if(heap.count(x))
//             {
//                 return true;
//             }
//             heap.insert(x);
//         }

//         return false;
//     }
// };