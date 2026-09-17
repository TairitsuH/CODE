/*
 * @lc app=leetcode.cn id=852 lang=cpp
 *
 * [852] 山脉数组的峰顶索引
 */

// @lc code=start

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr)
    {
        int n = arr.size();
        int left = 0, right = n - 1;
        while(left < right)
        {
            int mid = (left + right) / 2;
            if(arr[mid] < arr[mid + 1]) left = mid + 1;
            else right = mid;
        }    

        return left;
    }
};
// @lc code=end
//二刷：二分查找，找其中一个峰值即可，时间复杂度O(logN)
//一刷：原来这也是二段性！不是递增数组也可以用二分查找，长知识了ψ(｀∇´)ψ
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr)
    {
        int left = 0;
        int right = arr.size() - 1;

        while(left < right)
        {
            int mid = left + (right - left + 1) / 2;
            if(arr[mid] > arr[mid - 1])
            {
                left = mid;
            }
            else
            {
                right = mid - 1;
            }
        }

        return left;
    }
};