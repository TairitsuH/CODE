/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        vector<int> ret;
        int m = matrix.size();
        int n = matrix[0].size();

        //确定上下左右边界
        int left = 0, right = n-1, up = 0, down = m-1; //right和down记得减1！
        while(1)
        {
            //右
            for(int i=left; i<=right; i++) ret.push_back(matrix[up][i]);
            up++;
            if(up > down) break; //判断是否越界

            //下
            for(int i=up; i<=down; i++) ret.push_back(matrix[i][right]);
            right--;
            if(right < left) break;

            //左
            for(int i=right; i>=left; i--) ret.push_back(matrix[down][i]);
            down--;
            if(down < up) break;

            //上
            for(int i=down; i>=up; i--) ret.push_back(matrix[i][left]);
            left++;
            if(left > right) break;
        }
        return ret;
    }
};
// @lc code=end

//一刷：史山代码……用了方向向量+重新定义了新数组存储是否走过，感觉这种更适合矩阵填数。
// class Solution {
// public:
//     vector<int> spiralOrder(vector<vector<int>>& matrix)
//     {
//         int m = matrix.size(); //行
//         int n = matrix[0].size(); //列
//         vector<int> ret(m*n);
//         vector<vector<int>> matrix2(m, vector<int>(n)); //判断是否走过

//         vector<vector<int>> dest = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
//         int p = 0; //方向

//         int z = 0, x = 0, y = 0;
//         for(int i=1; i<=m*n; i++)
//         {
//             ret[z++] = matrix[x][y];
//             matrix2[x][y] = 1;

//             int a = x + dest[p][0];
//             int b = y + dest[p][1];

//             if(a >= m || b >= n || a < 0 || b < 0 || matrix2[a][b] == 1)
//             {
//                 p = (p + 1) % 4;
//                 a = x + dest[p][0];
//                 b = y + dest[p][1];
//             }

//             x = a;
//             y = b;
//         }
//         return ret;
//     }
// };

//二刷：依旧orz评论区大佬……简洁易懂，剥洋葱法完美解决了矩阵读取问题，搭配方向向量简直是矩阵万精油！
//虽然又卡在一些边界条件上了TvT