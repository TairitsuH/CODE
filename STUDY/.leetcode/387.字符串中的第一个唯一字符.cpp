/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 */

// @lc code=start
class Solution {
public:
    int firstUniqChar(string s)
    {
        int arr[26] = {0};
        for(auto ch : s)
        {
            arr[ch - 'a']++;
        }

        for(int i=0; i<s.size(); i++)
        {
            if(arr[s[i] - 'a'] == 1)
            {
                return i;
            }
        }

        return -1;
    }
};
// @lc code=end

//二刷：如果是整型可以直接异或0，非整型再用计数排序
//一刷：计数排序的思路，通过放入数组统计出现次数（类似哈希），再遍历字符串找第一个次数为1的字符即可
//就是特别需要注意数组下标TvT
// class Solution {
// public:
//     int firstUniqChar(string s)
//     {
//         int arr[26] = {0};
//         for(auto ch : s)
//         {
//             arr[ch - 'a']++;
//         }

//         for(int i=0; i<s.size(); i++)
//         {
//             if(arr[s[i] - 'a'] == 1)
//             {
//                 return i;
//             }
//         }

//         return -1;
//     }
// };