/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */

// @lc code=start
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        unordered_set<string> hash(wordList.begin(), wordList.end());
        unordered_set<string> hq;
        queue<string> q;
        int ret = 1;

        if(hash.count(endWord) == 0 || beginWord == endWord) return 0;

        q.push(beginWord);
        hq.insert(beginWord);

        while(q.size() > 0)
        {
            ++ret;
            int levelsize = q.size();
            for(int i=0; i<levelsize; ++i)
            {
                string s = q.front();
                q.pop();

                for(int j=0; j<s.size(); ++j)
                {
                    string tmp = s;
                    for(char c ='a'; c<='z'; ++c)
                    {
                        tmp[j] = c;
                        if(hash.count(tmp) == 1 && hq.count(tmp) == 0)
                        {
                            if(tmp == endWord) return ret;

                            q.push(tmp);
                            hq.insert(tmp);
                        }                        
                    }
                }
            }
        }

        return 0;
    }
};
// @lc code=end

//一刷：图论，路权为1的最小路径，注意要和lc433区分，本题的ret是从1开始的，注意循环的循环变量不要重复

