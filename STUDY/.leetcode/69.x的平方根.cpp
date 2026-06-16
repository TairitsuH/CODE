class Solution {
public:
    int mySqrt(int x) {
        // 由于两个较大的数相乘可能会超过 int 最大范围，因此用 long long
        long long i = 0;
        
        for (i = 0; i <= x; i++) {
            // 如果两个数相乘正好等于 x，直接返回 i
            if (i * i == x) {
                return i;
            }
            // 如果第一次出现两个数相乘大于 x，说明结果是前一个数
            if (i * i > x) {
                return i - 1;
            }
        }
        
        // 为了处理 OJ 题需要控制所有路径都有返回值
        return -1;
    }
};
//二分查找，本质模板题