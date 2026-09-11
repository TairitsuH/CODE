/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start
class Solution {
public:
    string removeDuplicates(string s)
    {
        string ret = "";
        for(auto c : s)
        {
            if(ret.size() && c == ret.back())
            {
                ret.pop_back();
            }
            else
            {
                ret += c;
            }
        }

        return ret;
    }
};
// @lc code=end
//二刷：栈思路，注意栈为空的情况
//一刷：用数组模拟栈的后进先出，从而实现消除重复项
// class Solution {
// public:
//     string removeDuplicates(string s)
//     {
//         string ret = "";
//         for(auto c : s)
//         {
//             if(ret.size() > 0 && c == ret.back())
//             {
//                 ret.pop_back();
//             }
//             else
//             {
//                 ret += c;
//             }
//         }    

//         return ret;
//     }
// };
