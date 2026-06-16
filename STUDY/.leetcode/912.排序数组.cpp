/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

// @lc code=start
class Solution {
public:
    vector<int> tmp;

    void Merge_Sort(vector<int>& nums, vector<int>& tmp, int left, int right)
    {
        if(left >= right) return;

        int mid = (left + right) / 2;

        Merge_Sort(nums, tmp, left, mid);
        Merge_Sort(nums, tmp, mid + 1, right);

        int begin1 = left;
        int end1 = mid;
        int begin2 = mid + 1;
        int end2 = right;
        int i = left;

        while(begin1 <= end1 && begin2 <= end2)
        {
            tmp[i++] = nums[begin1] <= nums[begin2] ? nums[begin1++] : nums[begin2++];
        }

        while(begin1 <= end1)
        {
            tmp[i++] = nums[begin1++];
        }

        while(begin2 <= end2)
        {
            tmp[i++] = nums[begin2++];
        }

        for(i=left; i<=right; i++)
        {
            nums[i] = tmp[i];
        }
    }

    vector<int> sortArray(vector<int>& nums)
    {
        tmp.resize(nums.size());
        Merge_Sort(nums, tmp, 0, nums.size() - 1);
        return nums;
    }
};
// @lc code=end

//三刷：归并排序，好久不练生疏了...打算现在遇到相关的就回去瞄一眼
//二刷：快速排序，整体偏套路化，注意一些细节
// class Solution {
// public:
//     int getRandom(vector<int>& nums, int l, int r)
//     {
//         return nums[rand() % (r - l + 1) + l];
//     }

//     void Quick_Sort(vector<int>& nums, int l, int r)
//     {
//         if(l >= r) return;

//         int left = l - 1;
//         int right = r + 1;
//         int i = l;
//         int key = getRandom(nums, l, r);

//         while(i < right)
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

//         Quick_Sort(nums, l, left);
//         Quick_Sort(nums, right, r); //注意递归的区间范围！不是从0开始到n-1结束
//     }

//     vector<int> sortArray(vector<int>& nums)
//     {
//         srand(time(NULL));

//         int n = nums.size();
//         Quick_Sort(nums, 0, n-1);

//         return nums;
//     }

// };
//一刷：快速排序，数组分三块 + 随机选数。注意left和right在传参时应该传入闭区间，函数内部再处理为开区间，否则会很麻烦！
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