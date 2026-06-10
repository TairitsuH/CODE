/*
 * @lc app=leetcode.cn id=137 lang=cpp
 *
 * [137] 只出现一次的数字 II
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums)
    {
        int ret = 0;

        for(int i=0; i<32; i++)
        {
            int sum = 0;

            for(auto x : nums)
            {
                sum += ((x >> i) & 1);
            }

            sum %= 3;
            if(sum == 1)
            {
                ret |= (1 << i);
            }
        }

        return ret;
    }
};
// @lc code=end
//二刷：注意位运算的对应操作，没必要死记硬背，可以自己推出来。
//一刷：位运算算法，重复n次就%n
// class Solution {
// public:
//     int singleNumber(vector<int>& nums)
//     {
//         int ret = 0;
//         for(int i=0; i<32; i++)
//         {
//             int sum = 0;
//             for(auto x : nums)
//             {
//                 if(((x >> i) & 1) == 1)
//                 {
//                     sum++;
//                 }
//             }

//             sum %= 3;
//             if(sum == 1)
//             {
//                 ret |= 1 << i;
//             }
//         }

//         return ret;
//     }
// };