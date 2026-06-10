/*
 * @lc app=leetcode.cn id=1576 lang=cpp
 *
 * [1576] 替换所有的问号
 */

// @lc code=start
class Solution {
public:
    string modifyString(string s)
    {
        int n = s.size();
        for(int i=0; i<n; i++)
        {
            if(s[i] == '?')
            {
                for(char j='a'; j <= 'z'; j++)
                {
                    if((i == 0 || s[i - 1] != j) && (i == n - 1 || s[i + 1] != j))
                    {
                        s[i] = j;
                        break;
                    }
                }
            }
        }

        return s;
    }
};
// @lc code=end

//一刷：遇到?后依次用a~z尝试替换即可，注意下标为0和n-1的边界情况

