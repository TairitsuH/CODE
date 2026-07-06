/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除了自身以外数组的乘积
 */

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> fx(n, 1);
        vector<int> gx(n, 1);

        for(int i=1; i<n; i++)
        {
            fx[i] = fx[i - 1] * nums[i - 1];
        }

        for(int i=n-2; i>=0; i--)
        {
            gx[i] = gx[i + 1] * nums[i + 1];
        }

        vector<int> ret;
        for(int i=0; i<n; i++)
        {
            int left = fx[i];
            int right = gx[i];

            ret.push_back(left * right);
        }

        return ret;
    }
};
// @lc code=end

//二刷：一遍过，用了前缀和后缀乘积的方式解决（适用于频繁多次求区间积）
//一刷：用前缀乘积的方式计算区间乘积
// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums)
//     {
//         int n = nums.size();

//         vector<int> fx(n), gx(n);
//         vector<int> ret;

//         fx[0] = nums[0];
//         gx[n - 1] = nums[n - 1];
//         for(int i=1; i<n; i++)
//         {
//             fx[i] = nums[i];
//             gx[n - i - 1] = nums[n - i - 1];

//             fx[i] *= fx[i - 1];
//             gx[n - i - 1] *= gx[n - i];
//         }

//         for(int i=0; i<n; i++)
//         {
//             if(i == 0)
//             {
//                 ret.push_back(gx[1]);
//             }
//             else if(i == n - 1)
//             {
//                 ret.push_back(fx[n - 2]);
//             }
//             else
//             {
//                 ret.push_back(fx[i - 1] * gx[i + 1]);
//             }
//         }

//         return ret;
//     }
// };