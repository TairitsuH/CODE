/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums)
    {
        int n = nums.size();
        return max(nums[0] + steal(nums, 2, n-2), steal(nums, 1, n-1));
    }

    int steal(vector<int>& nums, int left, int right)
    {
        if(left > right) return 0;

        int n = nums.size();
        vector<int> f(n, 0);
        vector<int> g(n, 0);

        for(int i=left; i<=right; ++i)
        {
            f[i] = g[i - 1] + nums[i];
            g[i] = max(f[i - 1], g[i - 1]);
        }

        return max(f[right], g[right]);
    }
};
// @lc code=end
//二刷：动态规划，注意返回值和函数参数！left和right容易相当然写成n
//一刷：动态规划，分类讨论决定第一个位置偷/不偷，注意从left出发不用初始化/left+1出发需要f[0] = nums[0]
class Solution {
public:
    int f[100];
    int g[100];
    int rob(vector<int>& nums)
    {
        int n = nums.size();
        return max(nums[0] + rob1(nums, 2, n - 2), rob1(nums, 1, n - 1)); //第一个位置偷/不偷
    }

    int rob1(vector<int>& nums, int left, int right)
    {
        if(left > right) return 0;

        for(int i=left; i<=right; ++i)
        {
            f[i] = g[i - 1] + nums[i];
            g[i] = max(g[i-1], f[i-1]);
        }

        return max(f[right], g[right]);
    }
};
