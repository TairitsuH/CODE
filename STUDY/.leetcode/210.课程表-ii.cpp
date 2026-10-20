/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */

// @lc code=start
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<int> ret;

        //1.创建邻接表+入度    
        unordered_map<int, vector<int>> edges;
        vector<int> in(numCourses);

        for(int i=0; i<prerequisites.size(); ++i)
        {
            int x = prerequisites[i][0];
            int y = prerequisites[i][1];
            edges[y].push_back(x);
            ++in[x];
        }

        //2.入度为0的入队列
        queue<int> q;
        for(int i=0; i<numCourses; ++i)
        {
            if(in[i] == 0)
            {
                q.push(i);
                ret.push_back(i);
            }
        }

        //3.拓扑排序+ret补全
        while(q.size() > 0)
        {
            int t = q.front();
            q.pop();

            for(auto e : edges[t])
            {
                --in[e];
                if(in[e] == 0)
                {
                    ret.push_back(e);
                    q.push(e);
                }
            }
        }

        //4.检查并返回
        if(ret.size() != numCourses) return {};
        return ret;
    }
};
// @lc code=end
//一刷：拓扑排序，在lc207课程表1的基础上增加了记录结果的操作

