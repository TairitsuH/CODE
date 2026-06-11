/*
 * @lc app=leetcode.cn id=495 lang=cpp
 *
 * [495] 提莫攻击
 */

// @lc code=start
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration)
    {
        int sum = duration;
        int n = timeSeries.size();
        for(int i=1; i<n; i++)
        {
            if(timeSeries[i] - timeSeries[i - 1] >= duration)
            {
                sum += duration;
            }
            else
            {
                sum += timeSeries[i] - timeSeries[i - 1];
            }
        }

        return sum;
    }
};
// @lc code=end

//二刷：初始化sum是为了处理最后一次攻击一定会持续duration秒
//一刷：时间差大于等于duration不会重叠，小于duration会重叠，注意最后要加上最后一次的时间。
// class Solution {
// public:
//     int findPoisonedDuration(vector<int>& timeSeries, int duration)
//     {
//         int sum = 0;
//         int n = timeSeries.size();

//         for(int i=0; i<n-1; i++)
//         {
//             if(timeSeries[i+1] - timeSeries[i] >= duration)
//             {
//                 sum += duration;
//             }
//             else
//             {
//                 sum += timeSeries[i+1] - timeSeries[i];
//             }
//         }

//         sum += duration;

//         return sum;
//     }
// };