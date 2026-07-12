/*
 * @lc app=leetcode.cn id=525 lang=cpp
 *
 * [525] 连续数组
 */

// @lc code=start
class Solution {
public:
    int findMaxLength(vector<int>& nums)
    {
        unordered_map<int, int> hash;
        int n = nums.size();
        int sum = 0, ret = 0;
        hash[0] = -1; //下标为-1

        for(int i=0; i<n; i++)
        {
            sum += (nums[i] == 0 ? -1 : 1);

            if(hash.count(sum) != 0)
            {
                int len = i - hash[sum]; //注意画图，这里不用加1
                ret = max(ret, len);
            }
            else
            {
                hash[sum] = i;
            }
        }

        return ret;
    }
};
// @lc code=end//
//二刷：首选滑动窗口，但不适用0；二选前缀和+哈希表：把0当作-1计算，哈希表中<int, int>前者存和，后者存下标。
//两次过了嘻嘻
//一刷：前缀和+哈希表，把0当作-1处理，并且要注意<sum, int>重复的情况。哈希表中存的是长度
// class Solution {
// public:
//     int findMaxLength(vector<int>& nums)
//     {
//         int sum = 0, ret = 0;
//         int n = nums.size();
//         unordered_map<int, int> hash;
//         hash[0] = 0; //如果存下标就是-1

//         for(int i=0; i<n; i++)
//         {
//             int x = nums[i];
//             if(x == 0)
//             {
//                 sum += -1;
//             }
//             else
//             {
//                 sum += 1;
//             }

//             if(hash.count(sum) != 0)
//             {
//                 int len = i + 1;
//                 ret = max(ret, len - hash[sum]);
//             }

            
//             if(sum != 0 && hash.count(sum) == 0)
//             {
//                 hash[sum] = i + 1;
//             }
//         }

//         return ret;
//     }
// };