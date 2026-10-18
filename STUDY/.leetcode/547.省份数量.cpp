/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 省份数量
 */

// @lc code=start
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected)
    {
        int n = isConnected.size();
        vector<int> ufs(n, -1);

        auto FindRoot = [&ufs](int x)
        {
            int root = x;
            while(ufs[root] >= 0) root = ufs[root];
            return root;
        };

        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                if(isConnected[i][j] == 1)
                {
                    int root1 = FindRoot(i);
                    int root2 = FindRoot(j);

                    if(root1 != root2)
                    {
                        ufs[root1] += ufs[root2];
                        ufs[root2] = root1;
                    }
                }
            }
        }

        int ret = 0;
        for(auto x : ufs) 
        {
            if(x < 0) ++ret;
        }

        return ret;
    }
};
// @lc code=end

//并查集，用lambda设计FindRoot函数，链接两个城市，最后返回集合数量

