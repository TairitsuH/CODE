/*
 * @lc app=leetcode.cn id=1089 lang=cpp
 *
 * [1089] 复写零
 */
// @lc code=start
class Solution {
public:
    void duplicateZeros(vector<int>& arr)
    {
        int n = arr.size();
        int cnt = 0;
        int i = 0;
        for(i=0; i<n; i++)
        {
            if(arr[i] == 0) cnt += 2;
            else ++cnt;
            if(cnt >= n) break;
        }

        for(int left=i, right=n-1; left >= 0; left--)
        {
            if(left == i && cnt > n)
            {
                arr[right--] = 0;
                continue;
            }
            if(arr[left] == 0)
            {
                arr[right] = 0;
                arr[--right] = 0;
            }
            else
            {
                arr[right] = arr[left];
            }
            --right;
        }
    }
};
// @lc code=end

//三刷：先预计算所需空间，再从后往前使用双指针。注意特殊情况
//二刷：试着不用插入的方式，边界条件还需要注意！自己画图+模拟一遍
// class Solution {
// public:
//     void duplicateZeros(vector<int>& arr)
//     {
//         int n = arr.size();
//         int cur = 0;
//         int dest = -1;
//         while(cur < n)
//         {
//             if(arr[cur] == 0)
//             {
//                 dest += 2;
//             }
//             else
//             {
//                 dest++;
//             }

//             if(dest >= n - 1)
//             {
//                 break;
//             }

//             cur++;
//         }

//         if(dest > n - 1)
//         {
//             arr[n - 1] = 0;
//             dest -= 2;
//             cur--;
//         }

//         while(dest >= 0)
//         {
//             if(arr[cur] == 0)
//             {
//                 arr[dest] = 0;
//                 arr[dest - 1] = 0;
//                 dest -= 2;
//             }
//             else
//             {
//                 arr[dest] = arr[cur];
//                 dest--;
//             }

//             cur--;
//         }
//     }
// };
//一刷：注意迭代器的失效问题！循环和内部都涉及了i的修改
// class Solution {
// public:
//     void duplicateZeros(vector<int>& arr)
//     {
//         int n = arr.size();

//         for(int i=0; i<n; i++)
//         {
//             if(arr[i] == 0)
//             {
//                 arr.insert(arr.begin()+i, 0);
//                 i += 1;
//             }
//         }

//         arr.resize(n);
//     }
// };