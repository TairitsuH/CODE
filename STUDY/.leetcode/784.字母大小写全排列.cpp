/*
 * @lc app=leetcode.cn id=784 lang=cpp
 *
 * [784] 字母大小写全排列
 */

// @lc code=start
class Solution {
public:
    vector<string> ret;
    string str;

    void dfs(string path, int pos)
    {
        for(int i=pos; i<str.size(); ++i)
        {
            if(str[i] >= 'a' && str[i] <= 'z')
            {
                path[i] = str[i] - 'a' + 'A';
                dfs(path, i+1);
                path[i] = str[i];
            }
            if(str[i] >= 'A' && str[i] <= 'Z')
            {
                path[i] = str[i] - 'A' + 'a';
                dfs(path, i+1);
                path[i] = str[i];   
            }
        }

        ret.push_back(path);
        return;
    }

    vector<string> letterCasePermutation(string s)
    {
        str = s;
        dfs(s, 0);
        return ret;
    }
};
// @lc code=end

//一刷：递归+回溯：可以使用全局str代替传参，另外每次递归有变/不变两种选择，最后都会被push_back，因此不需要考虑额外将初始的s放入ret中

