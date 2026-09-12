class Solution {
public:
    int totalFruit(vector<int>& fruits)
    {
        int hash[100001] = {0};
        int ret = 0;
        int n = fruits.size();
        int kinds = 0;
        for(int left=0,right=0; right<n; right++)
        {
            if(hash[fruits[right]] == 0)
            {
                ++kinds;
            }            
            ++hash[fruits[right]];

            while(kinds > 2)
            {
                --hash[fruits[left]];
                if(hash[fruits[left]] == 0)
                {
                    --kinds;
                }
                ++left;
            }

            ret = max(ret, right - left + 1);
        }

        return ret;
    }
};

//四刷：减少空间复杂度
//三刷：数组模拟哈希表，时间复杂度O(n)，空间复杂度O(n)，稍快
//二刷：哈希表，对于接口的使用还是不太熟练，比如说[]支持直接插入，size返回存储的种类等等
// class Solution {
// public:
//     int totalFruit(vector<int>& fruits)
//     {
//         unordered_map<int, int> hash;
//         int ret = 0;
//         int n = fruits.size();
//         for(int left=0, right=0; right < n; right++)
//         {
//             ++hash[fruits[right]];
//             //出窗口
//             if(hash.size() > 2)
//             {
//                 --hash[fruits[left]];    
//                 if(hash[fruits[left]] == 0) hash.erase(fruits[left]);
//                 ++left;
//             }

//             ret = max(ret, right - left + 1);
//         }

//         return ret;
//     }
// };
//一刷：滑动窗口（特化，不用数组）。看了下评论区思路，不用哈希表需要创建四个变量，存x y和x y的次数，有点复杂，需要注意的点太多了。
//哈希表打算之后学，现在先打数组基础
// class Solution {
// public:
//     int totalFruit(vector<int>& fruits)
//     {
//         int n = fruits.size();
//         int slow = 0, fast;
//         int x = fruits[0], y;
//         int xt = 0, yt = 0;
//         int flag = 1;
//         int len = 0;

//         for(fast=0; fast<n; fast++)
//         {
//             if(fruits[fast] != fruits[slow] && flag == 1) //flag为1表示还没找到第二种水果
//             {
//                 flag = 0; //flag置为0表示y已被赋值
//                 y = fruits[fast];
//             }

//             if(fruits[fast] == x) xt++;
//             else if(fruits[fast] == y && flag == 0) yt++;

//             if(fruits[fast] != x && fruits[fast] != y && flag == 0) //flag等于0易漏！
//             {
//                 len = max(len, fast - slow);
//                 while(xt > 0 && yt > 0) //条件易错！
//                 {
//                     if(fruits[slow] == x) xt--;
//                     else yt--;
//                     slow++; //易漏！！
//                 }

//                 if(xt == 0)
//                 {
//                     x = fruits[fast];
//                     xt = 1;
//                 }
//                 else
//                 {
//                     y = fruits[fast];
//                     yt = 1;
//                 }
//             }
//         }
//         len = max(len, fast - slow); //最后还需比较一下（fast为n时的情况
//         return len;
//     }
// };