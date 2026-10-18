/*
 * @lc app=leetcode.cn id=990 lang=cpp
 *
 * [990] 等式方程的可满足性
 */

// @lc code=start
class Solution {
public:
    bool equationsPossible(vector<string>& equations)
    {
        vector<int> ufs(26, -1);

        auto FindRoot = [&ufs](int x)
        {
            int root = x;
            while(ufs[root] >= 0) root = ufs[root];
            return root;
        };

        for(auto s : equations)
        {
            int x1 = s[0] - 'a';
            int x2 = s[3] - 'a';
            if(s[1] == '=')
            {
                int root1 = FindRoot(x1);
                int root2 = FindRoot(x2);

                if(root1 == root2) continue;

                ufs[root1] += ufs[root2];
                ufs[root2] = root1;
            }  
        }    

        for(auto s : equations)
        {
            int x1 = s[0] - 'a';
            int x2 = s[3] - 'a';
            if(s[1] == '!')
            {
                int root1 = FindRoot(x1);
                int root2 = FindRoot(x2);
                if(root1 == root2) return false;
            }
        }

        return true;
    }
};
// @lc code=end

//一刷：先遍历一遍用并查集存储等式方程的两端，再遍历检验!=的准确性，注意元素是int！

