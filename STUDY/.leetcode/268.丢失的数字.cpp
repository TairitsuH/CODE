/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 丢失的数字
 */

// @lc code=start
class Solution {
public:
    int missingNumber(vector<int>& nums)
    {
        int ret = 0;
        int n = nums.size();

        for(int i=0; i<n; i++)
        {
            ret ^= nums[i];
            ret ^= i + 1;
        }

        return ret;
    }
};
// @lc code=end
//二刷：异或思想和其他解法
//高斯求和
// class Solution {
// public:
//     int missingNumber(vector<int>& nums)
//     {
//         int n = nums.size();
//         int sum = n * (n + 1) / 2;
//         for(auto x : nums)
//         {
//             sum -= x;
//         }

//         return sum;
//     }
// };
//哈希表
// class Solution {
// public:
//     int missingNumber(vector<int>& nums)
//     {
//         unordered_map<int, int> hash;
//         int n = nums.size();
//         int ret = 0;

//         for(auto x : nums)
//         {
//             hash[x]++;
//         }

//         for(int i=0; i<=n; i++)
//         {
//             if(hash.count(i) == 0)
//             {
//                 ret = i;
//                 break;
//             }
//         }

//         return ret;
//     }
// };
//一刷：异或思想，逐一匹配即可
// class Solution {
// public:
//     int missingNumber(vector<int>& nums)
//     {
//         int ret = 0, pos = 1;
//         int n = nums.size();

//         for(int i=0; i<n; i++)
//         {
//             ret ^= nums[i];
//             ret ^= pos++;
//         }

//         return ret;
//     }
// };