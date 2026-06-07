/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        int left = 0;
        int right = 0;
        int n = s.size();
        int maxlen = 0;
        vector<int> hash(128, 0); //128个字符，用数组模拟哈希表

        while(right < n)
        {
            hash[s[right]]++;

            while(hash[s[right]] == 2) //加1在前判断在后则为2
            {
                hash[s[left++]]--;
            }

            maxlen = max(maxlen, right - left + 1);
            right++;
        }

        return maxlen;
    }
};

// @lc code=end
//二刷：滑动窗口，子串在遇到重复元素后无需回退，仅需跳过重复元素即可
//一刷：暴力，根据128个字符可以创建一个128大小的整型数组作为哈希表，用于查重。逐位遍历找最大字串
// class Solution {
// public:
//     int lengthOfLongestSubstring(string s)
//     {
//         int n = s.size();
//         int maxlen = 0;

//         for(int i=0; i<n; i++)
//         {
//             vector<int> hash(128, 0);
//             int len = 0;

//             for(int p=i; p<n; p++)
//             {
//                 if(hash[s[p]] == 1)// 判断在前加1在后则为1
//                 {
//                     break;
//                 }

//                 len++;
//                 hash[s[p]]++;
//                 maxlen = max(maxlen, len);
//             }

//         }

//         return maxlen;
//     }
// };
