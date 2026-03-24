/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> ret(n, vector<int>(n)); //创建n行n列的矩阵，已初始化为0
        vector<vector<int>> dest = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int p = 0; //方向向量
        int num = 1;
        int x = 0, y = 0;
        while(num <= n*n)
        {
            ret[x][y] = num;
            
            int a = x + dest[p][0];
            int b = y + dest[p][1];

            if(a > n-1 || b > n-1 || a < 0 || b < 0 || ret[a][b] != 0) 
            //判断越界
            {
                p = (p + 1) % 4;
                a = x + dest[p][0];
                b = y + dest[p][1];
            }

            x = a;
            y = b;
            num++;
        }
        return ret;
    }
};
// @lc code=end

//一刷：vector不太熟练，在创建时如果指定了大小会自动初始化为0。

