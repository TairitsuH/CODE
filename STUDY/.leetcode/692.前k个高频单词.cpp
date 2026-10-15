/*
 * @lc app=leetcode.cn id=692 lang=cpp
 *
 * [692] 前K个高频单词
 */

// @lc code=start
class Solution { 
public:
    struct Cmp
    {
        bool operator()(pair<string, int>& p1, pair<string, int>& p2)
        {
            if(p1.second == p2.second) return p1 < p2; //字典序
            return p1.second > p2.second; //频次
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k)
    {
        unordered_map<string, int> hash;
        for(int i=0; i<words.size(); ++i)    
        {
            ++hash[words[i]];
        }

        priority_queue<pair<string, int>, vector<pair<string, int>>, Cmp> heap; //频次：小根堆；字典序：大根堆
        for(auto& x : hash)
        {
            heap.push(x);
            if(heap.size() > k) heap.pop();
        }

        vector<string> ret(heap.size());
        for(int i=ret.size()-1; i>=0; --i) //逆序存储
        {
            ret[i] = heap.top().first;
            heap.pop();
        }

        return ret;
    }
};
// @lc code=end
//三刷：哈希表+优先队列
//二刷：思路没问题，但pair的使用还是不熟
class Solution {
public:
    struct Compare
    {
        bool operator()(const pair<string, int>& p1, const pair<string, int> p2) const
        {
            if(p1.second == p2.second)
            {
                return p1.first < p2.first;
            }
            return p1.second > p2.second;
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k)
    {
        map<string, int> hash;
        for(auto s : words)
        {
            hash[s]++;
        }

        vector<pair<string, int>> v(hash.begin(), hash.end());
        stable_sort(v.begin(), v.end(), Compare());

        vector<string> ret;
        for(int i=0; i<k; i++)
        {
            ret.push_back(v[i].first);
        }

        return ret;
    }
};
//一刷：仿函数部分一开始只对函数用了const，结果报错了。STL容器要求比较器的参数必须是const引用！
// class Solution {
// public:
//     struct Compare
//     {
//         bool operator()(const pair<string, int>& p1, const pair<string, int>& p2) const
//         {
//             if(p1.second != p2.second)
//             {
//                 return p1.second > p2.second;
//             }
//             return p1.first < p2.first;
//         }
//     };

//     vector<string> topKFrequent(vector<string>& words, int k)
//     {
//         map<string, int> mp;
//         for(auto& ch : words)
//         {
//             mp[ch]++;
//         }

//         vector<pair<string, int>> v(mp.begin(), mp.end());

//         stable_sort(v.begin(), v.end(), Compare());

//         vector<string> ret;

//         for(int i=0; i<k; i++)
//         {
//             ret.push_back(v[i].first);
//         }

//         return ret;
//     }
// };
