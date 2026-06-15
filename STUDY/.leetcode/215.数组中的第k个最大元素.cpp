/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution {
public:
    int Heap_Sort(vector<int>& nums, int k)
    {
        priority_queue<int> heap(nums.begin(), nums.end());
        k -= 1;
        while(k--)
        {
            heap.pop();
        }

        return heap.top();
    }

    int findKthLargest(vector<int>& nums, int k)
    {
        return Heap_Sort(nums, k);
    }
};
// @lc code=end

//三刷：试了一下用堆排序的方式解决
//二刷：太棒了！一遍过！很多细节自己推一遍会好很多，处理得也很好
// class Solution {
// public:
//     int Quick_Sort_K(vector<int>& nums, int l, int r, int k)
//     {
//         if(l == r) return nums[l];

//         int key = getRandom(nums, l, r);
//         int left = l - 1;
//         int right = r + 1;
//         int i = l;

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

//         int c =r - right + 1;
//         int b = right - left - 1;
//         if(k <= c) return Quick_Sort_K(nums, right, r, k);
//         if(k <= b + c) return key;
//         return Quick_Sort_K(nums, l, left, k - b - c); 
//     }

//     int getRandom(vector<int>& nums, int l, int r)
//     {
//         return nums[rand() % (r - l + 1) + l];
//     }

//     int findKthLargest(vector<int>& nums, int k)
//     {
//         srand(time(NULL));

//         return Quick_Sort_K(nums, 0, nums.size() - 1, k);
//     }
// };
//一刷：快速选择算法，有点复杂，不太熟练。
// class Solution {
// public:
    
//     int findKthLargest(vector<int>& nums, int k)
//     {
//         srand(time(NULL));
//         return QuickSort(nums, 0, nums.size()-1, k);
//     }

//     int QuickSort(vector<int>& nums, int l, int r, int k)
//     {
//         if(l == r) return nums[l]; //区间一定会存在

//         //1.随机选择基准元素
//         int key = getRandom(nums, l, r);

//         //2.根据基准元素将数组分为三块
//         int left = l - 1;
//         int right = r + 1;
//         int i = l;
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

//         //3.分情况讨论
//         int c = r - right + 1;
//         int b = right - left - 1;

//         if(k <= c) return QuickSort(nums, right, r, k);
//         else if(k <= b + c) return key; //注意是b + c!
//         else return QuickSort(nums, l, left, k - b - c); //注意是k - b - c!
//     }

//     int getRandom(vector<int>& nums, int l, int r)
//     {
//         int num = rand();
//         return nums[num % (r - l + 1) + l];
//     }
// };