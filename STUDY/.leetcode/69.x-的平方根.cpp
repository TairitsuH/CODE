/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根 
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x)
    {
        if(x < 1) return 0;

        long long left = 1;
        long long right = x / 2;
        while(left < right)
        {
            long long mid = left + (right - left + 1) / 2;
            if(mid * mid > x)
            {
                right = mid - 1;
            }
            else
            {
                left = mid;
            }
        }

        return left;
    }
};
// @lc code=end
//二刷：在1~x/2之间用二分查找，时间复杂度为O(logN)，注意用long long存储mid防越界。
//一刷：暴力枚举，时间复杂度为O(N)
// class Solution {
// public:
//     int mySqrt(int x)
//     {
//         long long i;
//         for(i=1; i*i<=x; i++)
//         {}

//         return i - 1;
//     }
// };