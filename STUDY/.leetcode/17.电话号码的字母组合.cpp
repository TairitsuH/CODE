/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */
// @lc code=start


class Solution {
public:
    vector<string> mapp = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ret;

    void dfs(string& digits, int index, string push)
    {
        if(index == digits.size())
        {
            ret.push_back(push);
            return;
        }

        int pos = digits[index] - '0';
        string& str = mapp[pos];

        for(auto ch : str)
        {
            // push += ch;
            //不需要pop_back，因为push+ch是临时创建的
            dfs(digits, index+1, push+ch);
        }
    }

    vector<string> letterCombinations(string digits)
    {
        dfs(digits, 0, "");
        return ret;
    }
};
// @lc code=end

//二刷：试了下普通递归，可以理解^_^ 就是类的权限方面还需注意，同时数组不能放在全局要放在类作用域里。
//一刷：太麻烦了，题解区用的是循环+递归，可以一学
// vector<string> str = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

// class Solution {
// public:
//     vector<string> letterCombinations(string digits)
//     {
//         vector<string> ret;
//         int len = digits.size();
//         if(len == 1)
//         {
//             int i = stoi(digits);
//             for(int j=0; j<str[i].size(); j++)
//             {
//                 string s = "";
//                 s += str[i][j];
//                 ret.push_back(s);
//             }
//         }
//         else if(len == 2)
//         {
//             int i = stoi(digits);
//             for(int j=0; j<str[i/10].size(); j++)
//             {
//                 for(int k=0; k<str[i%10].size(); k++)
//                 {
//                     string s = "";
//                     s += str[i/10][j];
//                     s += str[i%10][k];

//                     ret.push_back(s);
//                 }
//             }
//         }
//         else if(len == 3)
//         {
//             int i = stoi(digits);
//             for(int j=0; j<str[i/100].size(); j++)
//             {
//                 for(int k=0; k<str[i/10%10].size(); k++)
//                 {
//                     for(int l=0; l<str[i%10].size(); l++)
//                     {
//                         string s = "";
//                         s += str[i/100][j];
//                         s += str[i/10%10][k];
//                         s += str[i%10][l];

//                         ret.push_back(s);
//                     }
//                 }
//             }
//         }
//         else
//         {
//             int i = stoi(digits);

//             for(int m=0; m<str[i/1000].size(); m++)
//             {
//                 for(int j=0; j<str[i/100%10].size(); j++)
//                 {
//                     for(int k=0; k<str[i/10%10].size(); k++)
//                     {
//                         for(int l=0; l<str[i%10].size(); l++)
//                         {
//                             string s = "";
//                             s += str[i/1000][m];
//                             s += str[i/100%10][j];
//                             s += str[i/10%10][k];
//                             s += str[i%10][l];

//                             ret.push_back(s);
//                         }
//                     }
//                 }
//             }
//         }

//         return ret;
//     }
// };