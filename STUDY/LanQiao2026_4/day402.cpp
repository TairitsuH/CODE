// //二分算法，力扣https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/description/
// //2026.3.15
// class Solution {
// public:
//     vector<int> searchRange(vector<int>& nums, int target) 
//     {
//         int n = nums.size();
//         if(n == 0) return {-1, -1};

//         //查找起始位置
//         int left = 0; int right = n-1;
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
//         //判断是否含有target
//         if(nums[left] != target) return {-1, -1};
//         int retleft = left;
                    
//         //查找终止位置
//         left = retleft, right = n-1;
//         while(left < right)
//         {
//             int mid = (left + right + 1) / 2;
//             if(nums[mid] <= target)
//             {
//                 left = mid;
//             }
//             else
//             {
//                 right = mid - 1;
//             }
//         }
//         return {retleft, left};
//     }
// };

//2026.3.16 复盘
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        int n = nums.size();
        if(n == 0) return {-1, -1};

        int left = 0, right = n-1, ret = 0;
        while(left < right)
        {
            int mid = (left + right) / 2;
            if(nums[mid] >= target)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        ret = left;
        if(nums[left] != target) return {-1, -1};

        left = 0, right = n-1;
        while(left < right)
        {
            int mid = (right + left + 1) / 2;
            if(nums[mid] <= target)
            {
                left = mid;
            }
            else
            {
                right = mid - 1;
            }
        }

        return {ret, right};

    }
};