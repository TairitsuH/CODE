class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        int n = nums.size();
        if(n == 0) return {-1, -1};
        
        int left = 0, right = n-1;
        int mid;
        while(left < right)
        {
            mid = left + (right - left) / 2;
            if(nums[mid] >= target) right = mid;
            //当遇到target时，right还会向左收缩，直至找到最左边的target
            else left = mid + 1;
        }
        int retleft = right;
        if(nums[left] != target) return {-1, -1};

        left = retleft, right = n-1;
        while(left < right)
        {
            mid = left + (right - left + 1) / 2;
            if(nums[mid] <= target) left = mid;
            //当遇到target时，left还会向右收缩，直至找到最右边的target
            else right = mid - 1;
        }
        return {retleft, left};
    }
};

//二分查找：升序数组，时间复杂度o(logn)，用于快速查找/定位元素
//关键在于 等号 在if中的哪一边（向哪边逼近），取等于的一侧为起始/结束点