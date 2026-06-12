/*
 * @lc app=leetcode.cn id=1419 lang=cpp
 *
 * [1419] 数青蛙
 */

// @lc code=start
class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs)
    {
        string t = "croak";
        int n = t.size();
        unordered_map<char, int> hash;
        vector<int> pos(t.size(), 0);

        //哈希表存下标
        for(int i=0; i<n; i++)
        {
            hash[t[i]] = i;
        }

        for(auto ch : croakOfFrogs)
        {
            //c字符
            if(ch == 'c')
            {
                if(pos[n - 1] != 0)
                {
                    pos[n - 1]--;
                }

                pos[0]++;
            }
            //其他字符
            else
            {
                if(pos[hash[ch] - 1] != 0)
                {
                    pos[hash[ch] - 1]--;
                    pos[hash[ch]]++;
                }
                else
                {
                    return -1;
                }
            }
        }

        for(int i=0; i<n-1; i++)
        {
            if(pos[i] != 0)
            {
                return -1;
            }
        }

        return pos[n - 1];
    }
};
// @lc code=end

//三刷：哈希映射，哈希表用于存储下标，数组用于存储青蛙的叫声。一遍过~
//二刷：哈希映射，减少了if和else的冗余
// class Solution {
// public:
//     int minNumberOfFrogs(string croakOfFrogs)
//     {
//         string s = "croak";
//         int n = s.size();
//         vector<int> hash(n); //数组模拟哈希表
//         unordered_map<char, int> index;
//         for(int i=0; i<n; i++)
//         {
//             index[s[i]] = i;
//         }

//         for(auto ch : croakOfFrogs)
//         {
//             if(ch == 'c')
//             {
//                 if(hash[n - 1] != 0)
//                 {
//                     hash[n - 1]--;
//                 }

//                 hash[index[ch]]++;
//             }
//             else
//             {
//                 if(hash[index[ch] - 1] != 0)
//                 {
//                     hash[index[ch] - 1]--;
//                     hash[index[ch]]++;
//                 }
//                 else
//                 {
//                     return -1;
//                 }
//             }
//         }

//         for(int i=0; i<n-1; i++)
//         {
//             if(hash[i] != 0)
//             {
//                 return -1;
//             }
//         }

//         return hash[n - 1];
//     }
// };
//一刷：用了多个if和else判断，很麻烦
// class Solution {
// public:
//     int minNumberOfFrogs(string croakOfFrogs)
//     {
//         string s = "croa";
//         unordered_map<char, int> hash;
//         int n = croakOfFrogs.size();
//         for(int i=0; i<n; i++)
//         {
//             if(croakOfFrogs[i] == 'c')
//             {
//                 if(hash['k'] > 0)
//                 {
//                     hash['k']--;
//                 }
                
//                 hash['c']++;
//             }
//             else if(croakOfFrogs[i] == 'r')
//             {
//                 if(hash['c'] > 0)
//                 {
//                     hash['c']--;
//                     hash['r']++;
//                 }
//                 else
//                 {
//                     return -1;
//                 }
//             }
//             else if(croakOfFrogs[i] == 'o')
//             {
//                 if(hash['r'] > 0)
//                 {
//                     hash['r']--;
//                     hash['o']++;
//                 }
//                 else
//                 {
//                     return -1;
//                 }
//             }
//             else if(croakOfFrogs[i] == 'a')
//             {
//                 if(hash['o'] > 0)
//                 {
//                     hash['o']--;
//                     hash['a']++;
//                 }
//                 else
//                 {
//                     return -1;
//                 }
//             }
//             else if(croakOfFrogs[i] == 'k')
//             {
//                 if(hash['a'] > 0)
//                 {
//                     hash['a']--;
//                     hash['k']++;
//                 }
//                 else
//                 {
//                     return -1;
//                 }
//             }
//         }

//         for(auto ch : s)
//         {
//             if(hash[ch] != 0)
//             {
//                 return -1;
//             }
//         }

//         return hash['k'];
//     }
// };
