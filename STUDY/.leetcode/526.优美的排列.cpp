/*
 * @lc app=leetcode.cn id=526 lang=cpp
 *
 * [526] 优美的排列
 */

// @lc code=start
class Solution {
public:
    int ret = 0;
    bool check[16];
    vector<int> path;

    void dfs(int n, int pos)
    {
        if(pos - 1 == n)
        {
            ++ret;
            return;
        }

        for(int i=1; i<=n; ++i)
        {
            if(check[i] == false && (pos % i == 0 || i % pos == 0))
            {
                check[i] = true;
                dfs(n, pos+1);
                check[i] = false;
            }
        }
    }

    int countArrangement(int n) 
    {
        dfs(n, 1);
        return ret;
    }
};
// @lc code=end
//一刷：递归回溯，用pos模拟数组下标，注意终止条件是pos-1！此时pos比n大；或者把出口放在循环内部

