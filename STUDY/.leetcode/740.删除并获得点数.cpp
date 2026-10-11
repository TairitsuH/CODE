/*
 * @lc app=leetcode.cn id=740 lang=cpp
 *
 * [740] 删除并获得点数
 */

// @lc code=start
class Solution {
public:
    int deleteAndEarn(vector<int>& nums)
    {
        int n = nums.size();    
        vector<int> arr(1e4 + 1);
        for(int i=0; i<n; ++i) ++arr[nums[i]];
        int m = arr.size();

        vector<int> f(m);
        vector<int> g(m);
        for(int i=1; i<m; ++i)
        {
            f[i] = g[i - 1] + arr[i] * i;
            g[i] = max(f[i - 1], g[i - 1]);
        }

        return max(f[m-1], g[m-1]);
    }
};
// @lc code=end
//一刷：动态规划，先预处理原数组（arr计数，下表映射），再转化为lc打家劫舍问题（简单状态dp）
