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
        vector<int> ret;
        int n = s.size();
        int m = words.size();
        int len = words[0].size();
        unordered_map<string, int> hw;
        for(auto& w : words)
        {
            ++hw[w];
        }

        for(int i=0; i<len; i++)
        {
            unordered_map<string, int> hs;
            int count = 0;
            for(int left=i, right=i; right<=n-len; right+=len)
            {
                //进
                string in = s.substr(right, len);
                ++hs[in];
                if(hw.count(in) && hs[in] <= hw[in]) ++count;


                //判断+出
                while(right - left + 1 > m * len)
                {
                    string out = s.substr(left, len);
                    if(hs[out] <= hw[out]) --count;
                    --hs[out];

                    left += len;
                }

                //更新
                if(count == m) ret.push_back(left);
            }
        }

        return ret;
    }
};
// @lc code=end

//三刷：还差一点细节需要注重处理：进窗口是从right开始而不是left，否则会死循环；进窗口后记得更新结果；循环的结束条件一定要自己模拟
//二刷：理解了思路，但是好多细节！好多坑！比如对于字符串的起始位置要多一层for循环来遍历，另外接口的使用也不太熟练
// class Solution {
// public:
//     vector<int> findSubstring(string s, vector<string>& words)
//     {
//         vector<int> ret;
//         unordered_map<string, int> hw;
//         for(auto& str : words)
//         {
//             ++hw[str];
//         }

//         int n = s.size();
//         int m = words.size();
//         int len = words[0].size();

//         for(int i=0; i<len; ++i)
//         {
//             int count = 0;
//             unordered_map<string, int> hs;
//             for(int left=i, right=i; right<=n-len; right+=len)
//             {  
//                 //进窗口
//                 string in = s.substr(right, len);
//                 ++hs[in];
//                 if(hw.count(in) && hs[in] <= hw[in]) ++count;

//                 //出窗口
//                 while(right - left + 1 > m * len)
//                 {
//                     string out = s.substr(left, len);
//                     if(hw.count(out) && hs[out] <= hw[out]) --count;
//                     --hs[out];
//                     left += len;
//                 }

//                 //更新结果
//                 if(count == m) ret.push_back(left);
//             }
//         }

//         return ret;
//     }
// };
//一刷：理解了思路但很多细节还需要打磨，一不小心就会错，不能脱离题解独立实现。
// class Solution {
// public:
//     vector<int> findSubstring(string s, vector<string>& words)
//     {
//         unordered_map<string, int> hash1; //样板
//         vector<int> ret;

//         for(auto& str : words)
//         {
//             hash1[str]++;
//         }

//         int n = words.size(); //字符串个数
//         int len = words[0].size(); //字符串单位长度

//         for(int i=0; i<len; i++) //注意循环结束的时机
//         {
//             unordered_map<string, int> hash2; //定义在循环内部，每次开始时重置
//             int count = 0;
//             for(int left=i, right=i; right+len<=s.size(); right+=len) //起始位置
//             {
//                 //进窗口+维护count
//                 string in = s.substr(right, len);
//                 hash2[in]++;
//                 if(hash1.count(in) && hash2[in] <= hash1[in]) //先检验hash1中是否存在！
//                 {
//                     count++;
//                 }

//                 //判断
//                 if(right - left + 1 > len * n)
//                 {
//                     //出窗口+维护count
//                     string out = s.substr(left, len);
//                     if(hash1.count(out) && hash2[out] <= hash1[out]) //先检验hash1中是否存在！
//                     {
//                         count--;
//                     }

//                     hash2[out]--;
//                     left += len;
//                 }

//                 //更新结果
//                 if(count == n)
//                 {
//                     ret.push_back(left);
//                 }
//             }
//         }

//         return ret;
//     }
// };