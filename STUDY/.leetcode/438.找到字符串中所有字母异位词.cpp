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
        unordered_map<char, int> hash1;
        unordered_map<char, int> hash2;
        vector<int> ret;

        for(auto ch : p)
        {
            hash2[ch]++;
        }

        int m = p.size();
        for(int left=0, right=0; right < s.size(); right++)
        {
            hash1[s[right]]++;

            while(right - left + 1 > m)
            {
                hash1[s[left]]--;
                if(hash1[s[left]] == 0)
                {
                    hash1.erase(s[left]);
                }
                left++;
            }

            if(right - left + 1 == m && hash1 == hash2)
            {
                ret.push_back(left);
            }
        }

        return ret;
    }
};
// @lc code=end
//一刷：不算难，用了两个哈希表，一个存p的出现次数，一个作为滑动窗口存s的，但是时间复杂度有点高，后面可以试着用数组优化
