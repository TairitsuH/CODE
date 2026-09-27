/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> ret;
    vector<string> path;
    string model;
    bool col[10];
    bool dig1[20];
    bool dig2[20];

    void dfs(int n, int row)
    {
        if(row == n)
        {
            ret.push_back(path);
            return;
        }

        for(int j=0; j<n; ++j)
        {
            int d1 = row - j + n - 1;
            int d2 = row + j;
            
            //剪枝
            if(col[j] == false && dig1[d1] == false && dig2[d2] == false)
            {
                col[j] = true, dig1[d1] = true, dig2[d2] = true;
                string tmp = model;
                tmp[j] = 'Q';
                path.push_back(tmp);
                dfs(n, row+1);

                //回溯
                path.pop_back();
                col[j] = false, dig1[d1] = false, dig2[d2] = false;
            }
        }

    }

    vector<vector<string>> solveNQueens(int n)
    {
        for(int i=0; i<n; ++i) model += '.';

        dfs(n, 0);
        return ret;
    }
};
// @lc code=end
//一刷：递归/剪枝/回溯，开三个数组（列，主对角，副对角），每次递归处理一行；找规律一定要勤于画图！数组尽可能放在全局，减少传参

