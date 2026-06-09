/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */

// @lc code=start
class Solution {
public:
    int hammingWeight(int n)
    {
        int cnt = 0;
        while(n)
        {
            n &= (n - 1);
            cnt++;
        }

        return cnt;
    }
};
// @lc code=end

//二刷：每次循环去掉最后一个1，用n &= (n - 1)实现。
//一刷：位运算
// class Solution {
// public:
//     int hammingWeight(int n) 
//     {
//         int cnt = 0;

//         while(n != 0)
//         {
//             n &= (n - 1);
//             cnt++;
//         }
        
//         return cnt;
//     }
// };