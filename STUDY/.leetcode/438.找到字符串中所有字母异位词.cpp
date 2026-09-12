/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> ret;
        vector<int> hash1(26);   
        vector<int> hash2(26);
        int n = s.size();
        int m = p.size();
        int cnt = 0; //记录有效字符个数

        for(auto c : p)
        {
            ++hash1[c - 'a'];
            ++cnt;
        }

        int count = 0;

        for(int left=0, right=0; right<n; right++)
        {
            int x = s[right] - 'a';
            if(hash2[x] < hash1[x]) ++count;
            ++hash2[x];

            //出窗口
            while(right - left + 1 > m)
            {
                int y = s[left] - 'a';
                if(hash1[y] > 0 && hash2[y] <= hash1[y])
                {
                    --count;
                }

                --hash2[y];
                ++left;
            }

            if(count == cnt)
            {
                ret.emplace_back(left);
            }
        } 

        return ret;
    }
};

// @lc code=end
//四刷：数组模拟哈希表+滑动窗口+比较逻辑优化（有效字符个数），出窗口的时机不变
//三刷：两个哈希表+滑动窗口
// class Solution {
// public:
//     vector<int> findAnagrams(string s, string p)
//     {
//         vector<int> ret;
//         unordered_map<char, int> hash1;    
//         unordered_map<char, int> hash2;
//         int n = s.size();
//         int m = p.size();

//         for(auto c : p)
//         {
//             ++hash1[c];
//         }

//         for(int left=0, right=0; right<n; right++)
//         {
//             ++hash2[s[right]];
//             while(right - left + 1 > m)
//             {
//                 --hash2[s[left]];
//                 if(hash2[s[left]] == 0) hash2.erase(s[left]);
//                 ++left;
//             }

//             if(right - left + 1 == m && hash1 == hash2)
//             {
//                 ret.emplace_back(left);
//             }
//         } 

//         return ret;
//     }
// };
//二刷：通过两个数组模拟哈希表记录有效字符。忘记-a，数组下标易错。
// class Solution {
// public:
//     vector<int> findAnagrams(string s, string p)
//     {
//         int hash1[26] = {0};
//         int hash2[26] = {0};
//         vector<int> ret;

//         for(auto ch : p)
//         {
//             hash2[ch - 'a']++;
//         }

//         int m = p.size();
//         int count = 0;
//         for(int left=0, right=0; right < s.size(); right++)
//         {
//             //进窗口
//             hash1[s[right] - 'a']++;
//             if(hash1[s[right] - 'a'] <= hash2[s[right] - 'a'])
//             {
//                 count++;
//             }

//             //出窗口
//             if(right - left + 1 > m)
//             {
//                 if(hash1[s[left] - 'a'] <= hash2[s[left] - 'a'])
//                 {
//                     count--;
//                 }

//                 hash1[s[left] - 'a']--;
//                 left++;
//             }

//             //更新结果
//             if(count == m)
//             {
//                 ret.push_back(left);
//             } 
//         }

//         return ret;
//     }
// };
//一刷：不算难，用了两个哈希表，一个存p的出现次数，一个作为滑动窗口存s的，但是时间复杂度有点高，后面可以试着用数组优化
// class Solution {
// public:
//     vector<int> findAnagrams(string s, string p)
//     {
//         unordered_map<char, int> hash1;
//         unordered_map<char, int> hash2;
//         vector<int> ret;

//         for(auto ch : p)
//         {
//             hash2[ch]++;
//         }

//         int m = p.size();
//         for(int left=0, right=0; right < s.size(); right++)
//         {
//             hash1[s[right]]++;

//             while(right - left + 1 > m)
//             {
//                 hash1[s[left]]--;
//                 if(hash1[s[left]] == 0)
//                 {
//                     hash1.erase(s[left]);
//                 }
//                 left++;
//             }

//             if(right - left + 1 == m && hash1 == hash2)
//             {
//                 ret.push_back(left);
//             }
//         }

//         return ret;
//     }
// };