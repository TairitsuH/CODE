/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution {
public:
    
    int findKthLargest(vector<int>& nums, int k)
    {
        srand(time(NULL));
        return QuickSort(nums, 0, nums.size()-1, k);
    }

    int QuickSort(vector<int>& nums, int l, int r, int k)
    {
        if(l == r) return nums[l];

        int key = getRandom(nums, l, r);
        int left = l - 1;
        int right = r + 1;
        int i = l;
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

        int c = r - right + 1;
        int b = right - left - 1;

        if(k <= c) return QuickSort(nums, right, r, k);
        else if(k <= b + c) return key; //注意是b + c!
        else return QuickSort(nums, l, left, k - b - c); //注意是k - b - c!
    }

    int getRandom(vector<int>& nums, int l, int r)
    {
        int num = rand();
        return nums[num % (r - l + 1) + l];
    }
};
// @lc code=end

//一刷：快速选择算法，有点复杂，不太熟练。