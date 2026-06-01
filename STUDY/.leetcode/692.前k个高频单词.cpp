/*
 * @lc app=leetcode.cn id=692 lang=cpp
 *
 * [692] 前K个高频单词
 */

// @lc code=start
class Solution {
public:
    struct Compare
    {
        bool operator()(const pair<string, int>& p1, const pair<string, int>& p2) const
        {
            if(p1.second != p2.second)
            {
                return p1.second > p2.second;
            }
            return p1.first < p2.first;
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k)
    {
        map<string, int> mp;
        for(auto& ch : words)
        {
            mp[ch]++;
        }

        vector<pair<string, int>> v(mp.begin(), mp.end());

        stable_sort(v.begin(), v.end(), Compare());

        vector<string> ret;

        for(int i=0; i<k; i++)
        {
            ret.push_back(v[i].first);
        }

        return ret;
    }
};
// @lc code=end
//一刷：仿函数部分一开始只对函数用了const，结果报错了。STL容器要求比较器的参数必须是const引用！

