/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start

class Solution {
public:
    string minWindow(string s, string t)
    {
        int hash1[128] = {0};
        int kinds = 0;
        for(auto ch : t)
        {
            if(hash1[ch] == 0)
            {
                kinds++;
            }

            hash1[ch]++;
        }

        int begin = -1;
        int len = INT_MAX;

        int hash2[128] = {0};
        for(int left=0, right=0, count=0; right < s.size(); right++)
        {
            //进窗口
            char in = s[right];
            hash2[in]++;
            if(hash2[in] == hash1[in])
            {
                count++;
            }

            //判断
            while(count == kinds)
            {                
                //更新结果
                if(right - left + 1 < len)
                {
                    begin = left;
                    len = right - left + 1;
                }

                //出窗口
                char out = s[left];
                if(hash2[out] == hash1[out])
                {
                    count--;
                }

                hash2[out]--;
                left++;
            }
        }
        
        if(begin == -1) return "";

        // string ret = "";
        // for(int i=retleft; i < retleft+len; i++)
        // {
        //     ret += s[i];
        // }

        // return ret;
        
        return s.substr(begin, len);
    }
};
// @lc code=end

//一刷：最后组合ret的时候注意循环截止条件是retleft+len，更新结果时注意取最小子串。（也可以用substr返回