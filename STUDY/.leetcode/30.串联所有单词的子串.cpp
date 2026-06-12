/*
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] 串联所有单词的子串
 */

// @lc code=start
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words)
    {
        unordered_map<string, int> hash1; //样板
        vector<int> ret;

        for(auto& str : words)
        {
            hash1[str]++;
        }

        int n = words.size(); //字符串个数
        int len = words[0].size(); //字符串单位长度

        for(int i=0; i<len; i++)
        {
            unordered_map<string, int> hash2;
            int count = 0;
            for(int left=i, right=i; right+len<=s.size(); right+=len)
            {
                //进窗口+维护count
                string in = s.substr(right, len);
                hash2[in]++;
                if(hash1.count(in) && hash2[in] <= hash1[in])
                {
                    count++;
                }

                //判断
                if(right - left + 1 > len * n)
                {
                    //出窗口+维护count
                    string out = s.substr(left, len);
                    if(hash1.count(out) && hash2[out] <= hash1[out])
                    {
                        count--;
                    }

                    hash2[out]--;
                    left += len;
                }

                //更新结果
                if(count == n)
                {
                    ret.push_back(left);
                }
            }
        }

        return ret;
    }
};
// @lc code=end

//一刷：理解了思路但很多细节还需要打磨，一不小心就会错，不能脱离题解独立实现。
