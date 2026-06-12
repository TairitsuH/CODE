/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
*/

// @lc code=start
class Solution {
public:
    string countAndSay(int n)
    {
        string ret = "1";
        for(int i=1; i<n; i++)
        {
            string tmp;
            int len = ret.size();
            for(int left=0, right=0; right<len;)
            {
                int cnt = 0;

                while(ret[left] == ret[right] && right < len)
                {
                    right++;
                    cnt++;
                }

                tmp += to_string(cnt) + ret[left];
                left = right;
            }

            ret = tmp;
        }

        return ret;
    }
};
// @lc code=end

//二刷：自己梳理了一遍思路，再做就顺畅多了，之前主要是卡在了各种自增自减上，区间的范围很难敲定。
//可以统一一下下标改变的时机，会好写很多。
//一刷：模拟专题真是地狱难度TAT经常出现越界或者思路繁杂的情况，尽量不要在for循环写自增
//选取两个指针作为连续相同数字的首尾
// class Solution {
// public:
//     string countAndSay(int n)
//     {
//         string ret = "1";
//         for(int i=1; i<n; i++)
//         {
//             string tmp;
//             int len = ret.size();

//             for(int left=0, right=0; right < len;) //分号勿漏
//             {
//                 while(right < len && ret[left] == ret[right])
//                 {
//                     right++;
//                 }

//                 tmp += to_string(right - left) + ret[left];
//                 left = right;
//             }

//             ret = tmp;
//         }

//         return ret;
//     }
// };