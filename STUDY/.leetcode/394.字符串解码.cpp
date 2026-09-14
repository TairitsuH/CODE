/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */

// @lc code=start
class Solution {
public:
    string decodeString(string s)
    {
        int n = s.size();
        stack<string> str;
        stack<int> nums;
        str.push("");
        int i = 0;

        while(i < n)
        {
            if(s[i] >= '0' && s[i] <= '9')
            {
                int tmp = 0;
                while(i < n && s[i] >= '0' && s[i] <= '9')
                {
                    tmp *= 10;
                    tmp += s[i] - '0';
                    ++i;
                }

                nums.push(tmp);
            }
            else if(s[i] == '[')
            {
                ++i;
                string in;
                while(i < n && s[i] >= 'a' && s[i] <= 'z')
                {
                    in += s[i];
                    ++i;
                }

                str.push(in);
            }
            else if(s[i] == ']')
            {
                ++i;
                int ni = nums.top();
                nums.pop();
                string stri = str.top();
                str.pop();
                string in;
                while(ni--)
                {
                    in += stri;
                }
                
                str.top() += in;
            }
            else
            {
                string in;
                while(i < n && s[i] >= 'a' && s[i] <= 'z')
                {
                    in += s[i];
                    ++i;
                }
                str.top() += in;
            }
        } 

        return str.top();   
    }
};
// @lc code=end
//二刷：栈模拟，注意边界条件和入栈/出栈时机/i
//一刷：栈模拟，分类讨论要完全！不要贸然把两种情况合到一起，仔细读题。
// class Solution {
// public:
//     string decodeString(string s)
//     {
//         int n = s.size();
//         stack<string> sts;
//         stack<int> sti;
//         sts.push("");

//         int i = 0;
//         while(i < n)
//         {
//             if(s[i] >= '0' && s[i] <= '9')
//             {
//                 int tmp = 0;
//                 while(s[i] >= '0' && s[i] <= '9')
//                 {
//                     tmp *= 10;
//                     tmp += s[i] - '0';
//                     ++i;
//                 }
//                 sti.push(tmp);
//             }
//             else if(s[i] == '[')
//             {
//                 ++i;
//                 string in;
//                 while(s[i] >= 'a' && s[i] <= 'z')
//                 {
//                     in += s[i];
//                     ++i;
//                 }
//                 sts.push(in);
//             }
//             else if(s[i] == ']')
//             {
//                 int num = sti.top();
//                 sti.pop();
//                 string str = sts.top();
//                 sts.pop();

//                 string in;
//                 while(num--)
//                 {
//                     in += str;
//                 }

//                 sts.top() += in;
//                 ++i;
//             }
//             else
//             {
//                 string in;
//                 while(i < n && s[i] >= 'a' && s[i] <= 'z') //i < n防止越界
//                 {
//                     in += s[i];
//                     ++i;
//                 }
//                 sts.top() += in;
//             }
//         }

//         return sts.top();
//     }
// };