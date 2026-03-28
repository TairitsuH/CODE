/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        if(m == 0)
        {
            for(int i=0; i<n; i++)
            {
                nums1[i] = nums2[i];
            }
        }
        int p1 = m-1, p2 = n-1, p3 = m+n-1;
        while(p1 >= 0 && p2 >= 0)
        {
            if(nums1[p1] >= nums2[p2])
            {
                nums1[p3] = nums1[p1];
                p1--;
            }
            else if(nums1[p1] < nums2[p2])
            {
                nums1[p3] = nums2[p2];
                p2--;
            }
            p3--;
        }
        while(p1 < 0 && p2 >= 0) //p1先出循环
        {
            nums1[p3] = nums2[p2];
            p2--;
            p3--;
        }
    }
};
// @lc code=end

//一刷：暴力，先移动再排序
// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
//     {
//         int p1 = m;
//         for(int p2=0; p2<n; p2++)
//         {
//             nums1[p1] = nums2[p2];
//             p1++;
//         }
//         sort(nums1.begin(), nums1.end());
//     }
// };
//二刷：双指针，从后往前比较，p1从m-1开始，p2从n-1开始，谁大就把谁放到nums1的数组末尾
