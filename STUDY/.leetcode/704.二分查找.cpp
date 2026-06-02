//二分查找：升序数组，时间复杂度o(logn)，用于快速查找/定位元素（模板
class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
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
        
        if(nums[left] == target) return left;

        return -1;
    }
};

//二刷：要注意right初始化为size - 1
// 一刷：while(left < right) 没有等号，是因为if判断中有跳过mid的情况，加等号会陷入死循环
//复盘：更详细的解释：因为跳过了mid，循环最后会使left == right，导致死循环
// class Solution {
// public:
//     int search(vector<int>& nums, int target)
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
//         if(nums[right] == target)
//         return right;
//         return -1;
//     }
// };