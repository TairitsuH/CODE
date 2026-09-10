/*
 * @lc app=leetcode.cn id=844 lang=cpp
 *
 * [844] 比较含退格的字符串
 */

// @lc code=start
class Solution {
public:
    bool backspaceCompare(string s, string t)
    {
        string s1, t1;
        for(auto c : s)
        {
            if(s1.size() && c == '#')
            {
                s1.pop_back();
            }
            else if(c != '#')
            {
                s1 += c;
            }
        }

        for(auto c : t)
        {
            if(t1.size() && c == '#')
            {
                t1.pop_back();
            }
            else if(c != '#')
            {
                t1 += c;
            }
        }

        return s1 == t1;
    }
};
// @lc code=end

//二刷：栈模拟，遇到#且非空则出栈，非#则入栈
//一刷：双指针。思路乱了，看了评论区题解，遇到#则fast后移，slow--（slow大于0）
// class Solution {
// public:
//     bool backspaceCompare(string s, string t)
//     {
//         int len1 = s.size();
//         int len2 = t.size();
//         int s1 = 0, s2 = 0;
    
//         for(int f=0; f<len1; f++)
//         {
//             if(s[f] != '#')
//             {
//                 s[s1] = s[f];
//                 s1++;
//             }
//             else
//             {
//                 if(s1 > 0) s1--;
//             }
//         }

//         for(int f=0; f<len2; f++)
//         {
//             if(t[f] != '#')
//             {
//                 t[s2] = t[f];
//                 s2++;
//             }
//             else
//             {
//                 if(s2 > 0) s2--;
//             }
//         }
//         s.resize(s1), t.resize(s2);
//         if(s == t) return true;
//         return false;
        
//     }
// };