/*
 * @lc app=leetcode.cn id=433 lang=cpp
 *
 * [433] 最小基因变化
 */

// @lc code=start
class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank)
    {
        unordered_set<string> hash(bank.begin(), bank.end());
        unordered_set<string> hq;
        queue<string> q;
        string gene = "ACGT";
        int ret = 0;

        if(startGene == endGene) return 0;
        if(hash.count(endGene) == 0) return -1;

        q.push(startGene);
        hq.insert(startGene);

        while(q.size() > 0)
        {
            ++ret;

            int levelsize = q.size();
            for(int k=0; k<levelsize; ++k)
            {
                string tmp = q.front();
                q.pop();

                for(int i=0; i<endGene.size(); ++i)
                {
                    string s = tmp;
                    for(int j=0; j<gene.size(); ++j)
                    {
                        s[i] = gene[j];
                        if(hash.count(s) == 1 && hq.count(s) == 0)
                        {
                            if(s == endGene) return ret;
                            hq.insert(s);
                            q.push(s);
                        }
                    }
                }
            }
        }   

        return -1; 
    }
};
// @lc code=end

//二刷：图论，路权为1的最短路径问题，注意用levelsize来存储q.size()！因为q.size()实时在变化，一定要提前存储一下！藏得很深的bug！
//一刷：图论，路权为1的最短路径问题，bfs的解法，注意需要枚举字符串中的每一个字符，不能在判断到不同字符才进行修改（bank路径不一定有）
//注意一些细节问题！
class Solution {
public:
    char gene[4] = {'A', 'C', 'G', 'T'};

    int minMutation(string startGene, string endGene, vector<string>& bank)
    {
        unordered_set<string> hash(bank.begin(), bank.end());
        unordered_set<string> hq;
        queue<string> q;
        q.push(startGene);
        hq.insert(startGene);
        int ret = 0;

        //细节
        if(startGene == endGene) return 0;
        if(hash.count(endGene) == 0) return -1;

        while(q.size())
        {
            ++ret;
            int levelsize = q.size();
            for(int i=0; i<levelsize; ++i)
            {
                string tmp = q.front();
                q.pop();

                for(int j=0; j<endGene.size(); ++j)
                {
                    char prev = tmp[j]; //细节问题

                    for(int k=0; k<4; ++k)
                    {
                        if(gene[k] == prev) continue;
                        tmp[j] = gene[k];
                        if(hash.count(tmp) == 1 && hq.count(tmp) == 0)
                        {
                            if(tmp == endGene) return ret;
                            hq.insert(tmp);
                            q.push(tmp);
                        }
                        tmp[j] = prev; //恢复
                    }
                }
            }
        }

        return -1;
    }
};
