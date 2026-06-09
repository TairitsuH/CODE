/*
 * @lc app=leetcode.cn id=371 lang=cpp
 *
 * [371] 两整数之和
 */

// @lc code=start
class Solution {
public:
    int getSum(int a, int b)
    {
        while(b != 0)
        {
            long long x = a ^ b;
            long long pos = (a & b) << 1;

            a = x;
            b = pos;
        }

        return a;
    }
};
// @lc code=end

//一刷：a ^ b可以实现无进位相加，a & b可以实现仅进位，两者配合即可计算出结果。