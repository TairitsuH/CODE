/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start

class Solution {
public:
    double pow(double x, long long n)
    {
        if(n == 0) return 1; //注意返回1

        double getx = pow(x, n / 2);
        if(n % 2 == 0) return getx * getx;
        else return getx * getx * x;
    }

    double myPow(double x, int n)
    {
        if(n < 0) x = 1 / x;
        return pow(x, abs((long long)n));
    }
};
// @lc code=end
//二刷：快速幂递归，注意n为负数时要转为正数传参
//一刷：快速幂（递归），根据指数的特点快速相乘。注意细节：1.n可能为负数 2.n过于小时需用longlong存
class Solution {
public:
    double pow(double x, long long n)
    {
        if(n == 0) return 1;

        double getx = pow(x, n / 2);

        if(n % 2 == 0)
        {
            return getx * getx;
        }
        else
        {
            return getx * getx * x;
        }
    }

    double myPow(double x, int n)
    {
        if(n < 0) x = 1 / x;
        return pow(x, (long long)n);
    }
};
