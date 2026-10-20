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
                        if(edges[c1].count(c2) == 0)
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

//一刷：拓扑排序，好难好难！容器内部很复杂，还存在长度不同的阴间用例