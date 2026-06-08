/*
 * @lc app=leetcode.cn id=260 lang=cpp
 *
 * [260] 只出现一次的数字 III
 */

// @lc code=start
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums)
    {
        long long val = 0;
        for(auto x : nums)
        {
            val ^= x;
        }

        //找val最后一个1的位置
        int low = val & (-val);

        int a = 0;
        for(auto x : nums)
        {
            if(x & low) //x对应位置也是1
            {
                a ^= x;
            }
        }

        int b = val ^ a; //val是a,b的异或
        
        return {a, b};
    }
};
// @lc code=end

//二刷：位运算解法。a，b不同，因此可以根据不同的位把数组分为2组，分别异或即可。
//一刷：没什么思路，直接用了计数，结果就是数组太大+超时了