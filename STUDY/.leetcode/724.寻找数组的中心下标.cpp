/*
 * @lc app=leetcode.cn id=724 lang=cpp
 *
 * [724] 寻找数组的中心下标
 */

// @lc code=start
class Solution {
public:
    int pivotIndex(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> fx(n, 0);
        vector<int> gx(n, 0);

        fx[0] = nums[0];
        gx[n - 1] = nums[n - 1];

        for(int i=1; i<n; i++)
        {
            fx[i] = fx[i - 1] + nums[i];
        }

        for(int i=n-2; i>=0; i--)
        {
            gx[i] = gx[i + 1] + nums[i];
        }

        for(int i=0; i<n; i++)
        {
            int left = (i == 0 ? 0 : fx[i - 1]);
            int right = (i == n - 1 ? 0 : gx[i + 1]);

            if(left == right)
            {
                return i;
            }
        }

        return -1;
    }
};
// @lc code=end

//二刷：思路清晰，感觉渐渐熟悉了这种确定首尾，从第二位开始加，然后用left和right加三目判定的方式
//一刷：前缀和的思想，枚举每个下标都要计算左右区间的和，因此用前缀和预处理来优化
// class Solution {
// public:
//     int pivotIndex(vector<int>& nums) 
//     {
//         int n = nums.size();

//         for(int i=1; i<n; i++)
//         {
//             nums[i] += nums[i-1];
//         }

//         for(int i=0; i<n; i++)
//         {
//             int left, right;
//             i == 0 ? left = 0 : left = nums[i - 1]; 

//             i == n - 1 ? right = 0 : right = nums[n - 1] - nums[i];

//             if(left == right) return i;
//         }

//         return -1;
//     }
// };