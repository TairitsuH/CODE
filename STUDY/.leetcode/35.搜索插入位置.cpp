class Solution {
public:
    int searchInsert(vector<int>& nums, int target)
    {
        int n = nums.size();

        if(target > nums[n - 1]) return n;
        int left = 0;
        int right = n - 1;
        while(left < right)
        {
            int mid = (left + right) / 2;
            if(nums[mid] >= target) right = mid;
            else left = mid + 1;
        }    

        return left;
    }
};

//四刷：当target并不是比数组中所有的数都大的时候，插入位置的数总是会大于等于target，此时只能选择right = mid而不是mid+1，据此拓展函数体

//三刷：不应该依赖于测试用例，更应主动考虑所有情况
class Solution {
public:
    int searchInsert(vector<int>& nums, int target)
    {
        int n = nums.size();
        if(target > nums[n - 1]) return n;
        int left = 0;
        int right = n - 1;
        while(left < right)
        {
            int mid = (left + right) / 2;
            if(nums[mid] >= target) right = mid;
            else left = mid + 1;
        }

        return left;
    }
};
//二刷：忘记讨论target比所有元素大的情况了
// class Solution {
// public:
//     int searchInsert(vector<int>& nums, int target)
//     {
//         int left = 0;
//         int right = nums.size() - 1;

//         if(target > nums[right]) return right + 1;

//         while(left < right)
//         {
//             int mid = (left + right) / 2;
//             if(nums[mid] >= target)
//             {
//                 right = mid;
//             }
//             else
//             {
//                 left = mid + 1;
//             }
//         }

//         return left;
//     }
// };
//二分查找：升序数组，时间复杂度o(logn)，用于快速查找/定位元素
//找不到的情况需要插入，循环条件 while(left < right) 结束时，left == right
//此时right指向的是数组第一个 >= right 的元素的位置，所以循环结束后，
//nums[right] 是数组中第一个 >= target 的元素
// class Solution {
// public:
//     int searchInsert(vector<int>& nums, int target)
//     {
//         int n = nums.size();
//         int left = 0, right = n-1;
//         int mid;
//         while(left < right)
//         {
//             mid = left + (right - left) / 2;
//             if(nums[mid] >= target) right = mid;
//             else left = mid + 1;
//         }
//         if(nums[right] >= target) return right;
//         return right + 1;
//         //当循环结束时right指向最后一个元素，
//         //也就是 nums[mid] ，返回 right + 1

//     }
// };