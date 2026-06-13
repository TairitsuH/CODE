/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

// @lc code=start
class Solution {
public:
    vector<int> sortArray(vector<int>& nums)
    {
        int n = nums.size();
        srand(time(NULL));
        QuickSort(nums, 0, n - 1);

        return nums;
    }

    void QuickSort(vector<int>& nums, int l, int r)
    {
        if(l >= r) return;

        int key = getRandom(nums, l, r);
        int left = l - 1;
        int right = r + 1;

        for(int i = l; i < right;)
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

        QuickSort(nums, l, left); //注意递归区间！
        QuickSort(nums, right, r);

    }

    int getRandom(vector<int>& nums, int l, int r)
    {
        int num = rand();
        return nums[num % (r - l + 1) + l];
    }
};
// @lc code=end

//一刷：数组分三块 + 随机选数。注意left和right在传参时应该传入闭区间，函数内部再处理为开区间，否则会很麻烦！