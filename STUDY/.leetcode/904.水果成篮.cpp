class Solution {
public:
    int totalFruit(vector<int>& fruits)
    {
        int n = fruits.size();
        int slow = 0, fast;
        int x = fruits[0], y;
        int xt = 0, yt = 0;
        int flag = 1;
        int len = 0;

        for(fast=0; fast<n; fast++)
        {
            if(fruits[fast] != fruits[slow] && flag == 1) //flag为1表示还没找到第二种水果
            {
                flag = 0; //flag置为0表示y已被赋值
                y = fruits[fast];
            }

            if(fruits[fast] == x) xt++;
            else if(fruits[fast] == y && flag == 0) yt++;

            if(fruits[fast] != x && fruits[fast] != y && flag == 0) //flag等于0易漏！
            {
                len = max(len, fast - slow);
                while(xt > 0 && yt > 0) //条件易错！
                {
                    if(fruits[slow] == x) xt--;
                    else yt--;
                    slow++; //易漏！！
                }

                if(xt == 0)
                {
                    x = fruits[fast];
                    xt = 1;
                }
                else
                {
                    y = fruits[fast];
                    yt = 1;
                }
            }
        }
        len = max(len, fast - slow); //最后还需比较一下（fast为n时的情况
        return len;
    }
};

//一刷：看了下评论区思路，不用哈希表需要创建四个变量，存x y和x y的次数，有点复杂，需要注意的点太多了
//哈希表打算之后学，现在先打数组基础