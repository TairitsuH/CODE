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

        vector<int> fx(n), gx(n);
        vector<int> ret;

        fx[0] = nums[0];
        gx[n - 1] = nums[n - 1];
        for(int i=1; i<n; i++)
        {
            fx[i] = nums[i];
            gx[n - i - 1] = nums[n - i - 1];

            fx[i] *= fx[i - 1];
            gx[n - i - 1] *= gx[n - i];
        }

        for(int i=0; i<n; i++)
        {
            if(i == 0)
            {
                ret.push_back(gx[1]);
            }
            else if(i == n - 1)
            {
                ret.push_back(fx[n - 2]);
            }
            else
            {
                ret.push_back(fx[i - 1] * gx[i + 1]);
            }
        }

        return ret;
    }
};
// @lc code=end

//一刷：用前缀乘积的方式计算区间乘积
