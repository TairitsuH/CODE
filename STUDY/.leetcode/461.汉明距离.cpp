/*
 * @lc app=leetcode.cn id=461 lang=cpp
 *
 * [461] 汉明距离
 */

// @lc code=start
class Solution {
public:
    int hammingDistance(int x, int y)
    {
        int num = x ^ y;
        int ret = 0;
        while(num)
        {
            num &= (num - 1);
            ret++;
        }

        return ret;
    }
};
// @lc code=end

//二刷：还需更加熟练每种操作
//一刷：位运算，先异或（相异为1），然后计算1的个数。
// class Solution {
// public:
//     int hammingDistance(int x, int y)
//     {
//         int num = x ^ y;

//         int cnt = 0;
//         while(num != 0)
//         {
//             num &= (num - 1);
//             cnt++;
//         }

//         return cnt;
//     }
// };