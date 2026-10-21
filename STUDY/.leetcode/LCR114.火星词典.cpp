class Solution {
public:
    string alienOrder(vector<string>& words)
    {
        //1.建图+入度表
        unordered_map<char, unordered_set<char>> edges;
        unordered_map<char, int> in;

        //初始化+填图
        for(auto w : words)
        {
            for(auto c : w)
            {
                in[c] = 0;
            }
        }

        int n = words.size();
        for(int i=0; i<n; ++i)
        {
            for(int j=i+1; j<n; ++j)
            {
                string s1 = words[i];
                string s2 = words[j];
                int len1 = s1.size();
                int len2 = s2.size();
                
                int k = 0;
                for(k=0; k<min(len1, len2); ++k)
                {
                    char c1 = s1[k];
                    char c2 = s2[k];
                    if(c1 != c2)
                    {
                        if(!edges.count(c1)|| !edges[c1].count(c2)) //要先检查是否存在c1！
                        {
                            edges[c1].insert(c2);
                            ++in[c2];
                        }

                        break;
                    }
                }

                if(len1 > len2 && k == len2) return "";
            }
        }

        //2.入度为0的进队列
        string ret = "";
        queue<char> q;
        for(auto& [c, i] : in)
        {
            if(i == 0)
            {
                ret += c;
                q.push(c);
            }
        }

        //3.BFS拓扑排序
        while(q.size() > 0)
        {
            char t = q.front();
            q.pop();

            for(auto c : edges[t]) //注意
            {
                --in[c];
                if(in[c] == 0)
                {
                    ret += c;
                    q.push(c);
                }
            }
        }

        //4.检查结果，返回
        if(ret.size() == in.size()) return ret;
        return "";
    }
};

//二刷：BFS拓扑排序，几乎是一遍过，注意遍历edges的方式！使用[a, b]遍历能大大提升代码的简洁度
//一刷：拓扑排序，好难好难！容器内部很复杂，还存在长度不同的阴间用例
class Solution {
public:
    string alienOrder(vector<string>& words)
    {
        //1.建图+入度统计
        int n = words.size();
        unordered_map<char, unordered_set<char>> edges;
        unordered_map<char, int> in;

        //初始化in
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<words[i].size(); ++j)
            {
                char c = words[i][j];
                in[c] = 0;
            }
        }

        //填图，两两比较
        for(int i=0; i<n-1; ++i)
        {
            for(int j=i+1; j<n; ++j)
            {
                string s1 = words[i], s2 = words[j];
                int l1 = s1.size(), l2 = s2.size();

                //边+入度
                int k = 0;
                for(k=0; k<min(l1, l2); ++k)
                {
                    char c1 = s1[k], c2 = s2[k];
                    if(c1 != c2)
                    {
                        if(!edges[c1] && !edges[c1].count(c2))
                        {
                            edges[c1].insert(c2);
                            ++in[c2];
                        }

                        break;
                    }
                }

                if(k == s2.size() && k < s1.size()) return "";
            }
        }

        //2.入度为0的进队列
        string ret = "";
        queue<char> q;
        for(auto p : in)
        {
            if(p.second == 0)
            {
                ret += p.first;
                q.push(p.first);
            }
        }

        //3.拓扑排序
        while(q.size() > 0)
        {
            char c = q.front();
            q.pop();

            for(char cl : edges[c])
            {
                --in[cl];
                if(in[cl] == 0)
                {
                    ret += cl;
                    q.push(cl);
                }
            }
        }

        //检验，返回结果
        return ret.size() == in.size() ? ret : "";
    }
};