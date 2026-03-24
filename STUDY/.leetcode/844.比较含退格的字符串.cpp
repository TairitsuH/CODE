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
        int len1 = s.size();
        int len2 = t.size();
        int s1 = 0, s2 = 0;
    
        for(int f=0; f<len1; f++)
        {
            if(s[f] != '#')
            {
                s[s1] = s[f];
                s1++;
            }
            else
            {
                if(s1 > 0) s1--;
            }
        }

        for(int f=0; f<len2; f++)
        {
            if(t[f] != '#')
            {
                t[s2] = t[f];
                s2++;
            }
            else
            {
                if(s2 > 0) s2--;
            }
        }
        s.resize(s1), t.resize(s2);
        if(s == t) return true;
        return false;
        
    }
};
// @lc code=end

//一刷：思路乱了，看了评论区题解，遇到#则fast后移，slow--（slow大于0）