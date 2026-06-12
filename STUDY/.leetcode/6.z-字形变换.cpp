/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows)
    {
        int d = 2*(numRows - 1);
        int n = s.size();
        string ret;
        if(numRows == 1) return s;

        //第一行
        for(int i=0; i<n; i+=d)
        {
            ret += s[i];
        }

        //中间行
        for(int k=1; k<numRows-1; k++)
        {
            for(int i=k, j=d-k; i < n || j < n; i+=d, j+=d)
            {
                if(i < n)
                {
                    ret += s[i];
                }
                if(j < n)
                {
                    ret += s[j];
                }
            }
        }

        //末尾行
        for(int i=numRows-1; i<n; i+=d)
        {
            ret += s[i];
        }

        return ret;
    }
};
// @lc code=end

//三刷：搞懂了规律！注意要顺着下标找规律而不是数组中的位置！
//二刷：试着直接模拟了一下
// class Solution {
// public:
//     string convert(string s, int numRows)
//     {
//         int n = s.size();
//         if(numRows == 1) return s;
//         vector<vector<int>> vv(numRows, vector<int>(n, '1'));

//         for(int i=0,x=0,y=0; i<n; i++,x++)
//         {
//             vv[x][y] = s[i];

//             if(x == numRows - 1)
//             {
//                 while(x > 0 && i + 1 < n)
//                 {
//                     vv[--x][++y] = s[++i];
//                 }
//             }
//         }

//         string ret;

//         for(int i=0; i<numRows; i++)
//         {
//             for(int j=0; j<n; j++)
//             {
//                 if(vv[i][j] != '1')
//                 {
//                     ret += vv[i][j];
//                 }
//             }
//         }

//         return ret;
//     }
// };
//一刷：用找规律优化模拟
// class Solution {
// public:
//     string convert(string s, int numRows)
//     {
//         int n = s.size();
//         if(numRows == 1) return s;

//         string ret ="";
//         int d = 2 * numRows - 2;
        
//         //第一行
//         for(int i=0; i<n; i+=d)
//         {
//             ret += s[i];
//         }

//         //处理中间行
//         for(int k=1; k<numRows-1; k++)
//         {
//             for(int i=k, j=d-k; i<n || j<n; i+=d, j+=d)
//             {
//                 if(i < n)
//                 {
//                     ret += s[i];
//                 }
//                 if(j < n)
//                 {
//                     ret += s[j];
//                 }
//             }
//         }

//         //最后一行
//         for(int i=numRows-1; i<n; i+=d)
//         {
//             ret += s[i];
//         }

//         return ret;
//     }
// };
//直接模拟（创建数组），但是时空复杂度消耗过大，边界情况不好把握
