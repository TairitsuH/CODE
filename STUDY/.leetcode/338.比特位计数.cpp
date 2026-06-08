/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 */

// @lc code=start
class Solution {
public:
    vector<int> countBits(int n)
    {
        vector<int> ret;

        for(int i=0; i<=n; i++)
        {
            int cnt = 0;
            int num = i;
            while(num != 0)
            {
                num &= (num - 1);
                cnt++;
            }

            ret.push_back(cnt);
        }

        return ret;
    }
};
// @lc code=end

//一刷：位运算，逐个剔除最后的1，直至为0，然后把1的个数存入数组中。