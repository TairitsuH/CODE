/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        unordered_map<string, vector<string>> hash;
        
        for(auto& s : strs)
        {
            string tmp = s;
            sort(tmp.begin(), tmp.end());
            hash[tmp].push_back(s);
        }

        vector<vector<string>> ret;
        for(auto&[s, v] : hash)
        {
            ret.push_back(v);
        }

        return ret;
    }
};
// @lc code=end

//一刷：排序字符为key，原始字符为value，用哈希表存储。容器的操作还不太熟练。
