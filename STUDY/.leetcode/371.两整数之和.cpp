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
            unsigned int sum = a ^ b;
            unsigned int carry = a & b;
            a = sum;
            b = (carry << 1);
        }

        return a;
    }
};
// @lc code=end

//二刷：注意carry要左移一位，unsigned int可以保证符号位逻辑左移受保护
//一刷：a ^ b可以实现无进位相加，a & b可以实现仅进位，两者配合即可计算出结果。
// class Solution {
// public:
//     int getSum(int a, int b)
//     {
//         while(b != 0)
//         {
//             unsigned int x = a ^ b;
//             unsigned int pos = (a & b) << 1;

//             a = x;
//             b = pos;
//         }

//         return a;
//     }
// };