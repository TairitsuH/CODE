/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        int n = strs.size();
        
        string ret = strs[0];
        for(int i=0; i<ret.size(); i++)
        {
            for(int j=1; j<n; j++)
            {
                int m = strs[j].size();
                if(i >= m || ret[i] != strs[j][i])
                {

                    
                    ret = ret.substr(0, i);
                    break;
                }  
            }
        }

        return ret;
    }
};
// @lc code=end

//三刷：统一比较字符串中的每一位，注意ret的更新需要写在if内部
//二刷：统一比较全部字符的每一位
// class Solution {
// public:
//     string longestCommonPrefix(vector<string>& strs)
//     {
//         int n = strs.size();
//         int m = strs[0].size();

//         for(int i=0; i<m; i++)
//         {
//             char ch = strs[0][i];
//             for(int j=1; j<n; j++)
//             {
//                 if(i == strs[j].size() || ch != strs[j][i])
//                 {
//                     return strs[0].substr(0, i);
//                 }
//             }
//         }

//         return strs[0];
//     }
// };

//一刷：两两比较，然后和其他字符串比较。注意字符串为空的情况！
// class Solution {
// public:
//     string longestCommonPrefix(vector<string>& strs)
//     {
//         int n = strs.size();
//         if(n == 1)
//         {
//             return strs[0];
//         }

//         string ret = "";
//         for(int i=0, j=0; i<strs[0].size(), j<strs[1].size(); i++, j++)
//         {
//             if(strs[0][i] == strs[1][j])
//             {
//                 ret += strs[0][i];
//             }
//             else
//             {
//                 break;
//             }
//         }

//         for(int i=2; i<n; i++)
//         {
//             string cmp = strs[i];
//             string tmp = "";
//             for(int j=0, k=0; j<ret.size(), k<cmp.size(); j++, k++)
//             {
//                 if(ret[j] == cmp[k])
//                 {
//                     tmp += ret[j];
//                 }
//                 else
//                 {
//                     break;
//                 }
//             }

//             ret = tmp; //不能放在else中，否则无法处理空字符串
//         }

//         return ret;
//     }
// };