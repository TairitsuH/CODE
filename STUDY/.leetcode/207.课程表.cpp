/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        //1.邻接表:边+入度
        unordered_map<int, vector<int>> edges;
        vector<int> in(numCourses);

        //映射关系
        for(int i=0; i<prerequisites.size(); ++i)
        {
            int x = prerequisites[i][0];
            int y = prerequisites[i][1];

            edges[y].push_back(x);
            in[x]++;
        }

        //2.入度为0的进队列
        queue<int> q;
        for(int i=0; i<numCourses; ++i)
        {
            if(in[i] == 0) q.push(i);
        }

        //3.拓扑排序
        while(q.size() > 0)
        {
            int t = q.front();
            q.pop();

            for(auto e : edges[t])
            {
                //更新入度
                --in[e];
                //入度为0的进队列
                if(in[e] == 0) q.push(e); 
            }
        }

        //遍历，返回结果
        for(int i=0; i<numCourses; ++i)
        {
            if(in[i] != 0) return false;
        }

        return true;
    }
};
// @lc code=end
//一刷：拓扑排序，建立邻接表，循环：入度为0的入队列->更新度，最后遍历看是否有剩余节点，返回结果；拓扑排序适用于有向无环图，也可用于判断是否成环

