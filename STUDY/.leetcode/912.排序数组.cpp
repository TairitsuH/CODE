/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

// @lc code=start
class Solution {
public:
    int getRandom(vector<int>& nums, int l, int r)
    {
        return nums[rand() % (r - l + 1) + l];
    }

    void Quick_Sort(vector<int>& nums, int l, int r)
    {
        if(l >= r) return;

        int left = l - 1;
        int right = r + 1;
        int i = l;
        int key = getRandom(nums, l, r);

        while(i < right)
        {
            if(nums[i] < key)
            {
                swap(nums[++left], nums[i++]);
            }
            else if(nums[i] > key)
            {
                swap(nums[--right], nums[i]);
            }
            else
            {
                i++;
            }
        }

        Quick_Sort(nums, l, left);
        Quick_Sort(nums, right, r); //注意递归的区间范围！不是从0开始到n-1结束
    }

    vector<int> sortArray(vector<int>& nums)
    {
        srand(time(NULL));

        int n = nums.size();
        Quick_Sort(nums, 0, n-1);

        return nums;
    }

};
// @lc code=end

//二刷：整体偏套路化，注意一些细节
//一刷：数组分三块 + 随机选数。注意left和right在传参时应该传入闭区间，函数内部再处理为开区间，否则会很麻烦！
// class Solution {
// public:
//     vector<int> sortArray(vector<int>& nums)
//     {
//         int n = nums.size();
//         srand(time(NULL));
//         QuickSort(nums, 0, n - 1);

//         return nums;
//     }

//     void QuickSort(vector<int>& nums, int l, int r)
//     {
//         if(l >= r) return;

//         int key = getRandom(nums, l, r);
//         int left = l - 1;
//         int right = r + 1;

//         for(int i = l; i < right;)
//         {
//             if(nums[i] < key)
//             {
//                 swap(nums[++left], nums[i++]);
//             }
//             else if(nums[i] > key)
//             {
//                 swap(nums[--right], nums[i]);
//             }
//             else
//             {
//                 i++;
//             }
//         }

//         QuickSort(nums, l, left); //注意递归区间！
//         QuickSort(nums, right, r);

//     }

//     int getRandom(vector<int>& nums, int l, int r)
//     {
//         int num = rand();
//         return nums[num % (r - l + 1) + l];
//     }
// };