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
        unordered_map<int, int> hash; //存储余数+出现次数

        int sum = 0, ret = 0;
        hash[0] = 1; //0位置初始化为1，因为0是可以整除任何数的元素

        for(auto x : nums)
        {
            sum += x;
            int r = (sum % k + k) % k;
            if(hash.count(r))
            {
                ret += hash[r]; //sum范围内所有余数为r的子区间都满足
            }

            hash[r]++;
        }

        return ret;
    }
};
// @lc code=end

//二刷：根据同余定理(a - b) % n == 0 <-> a % n == b % n, 和负数取模(a % n + n) % n的规则，选择用前缀和+哈希表的方式解题：
//如果sum % k和x % k的余数相同，那么所求的子区间(sum - x) % k == 0。
// class Solution {
// public:
//     int subarraysDivByK(vector<int>& nums, int k)
//     {
//         unordered_map<int, int> hash;

//         int n = nums.size();
//         int sum = 0, ret = 0;
//         hash[0] = 1; //余数为0的时候算一个子区间，初始设置为1

//         for(auto x : nums)
//         {
//             sum += x;

//             if(hash.count((sum % k + k) % k) != 0) //同余定理
//             {
//                 ret += hash[(sum % k + k) % k];
//             }

//             hash[(sum % k + k) % k]++;
//         }

//         return ret;
//     }
// };
// class Solution {
// public:
//     int subarraysDivByK(vector<int>& nums, int k)
//     {
//         int sum = 0, ret = 0;
//         unordered_map<int, int> hash;
//         hash[0] = 1; //0这个数的余数

//         for(auto x : nums)
//         {
//             sum += x;
//             if(hash.count((sum % k + k) % k) == 1)
//             {
//                 ret += hash[(sum % k + k) % k];
//             }

//             hash[(sum % k + k) % k]++;
//         }

//         return ret;
//     }
// };
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