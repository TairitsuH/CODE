/*
 * @lc app=leetcode.cn id=493 lang=cpp
 *
 * [493] 翻转对
 */

// @lc code=start
class Solution {
public:
    vector<int> tmp;

    int reversePairs(vector<int>& nums)
    {
        int n = nums.size();
        tmp.resize(n);

        return Merge_Sort(nums, 0, n - 1);
    }

    //降序
    int Merge_Sort(vector<int>& nums, int left, int right)
    {
        if(left >= right) return 0;

        int mid = (left + right) / 2;
        int ret = 0;

        ret += Merge_Sort(nums, left, mid);
        ret += Merge_Sort(nums, mid + 1, right);

        int cur1 = left;
        int cur2 = mid + 1;
        int i = 0;

        //计算翻转对的数量（双指针）
        while(cur1 <= mid)
        {
            while(cur2 <= right && nums[cur1] / 2.0 <= nums[cur2]) //除以2避免越界
            {
                cur2++;
            }

            if(cur2 > right) break; //优化：没有翻转对的时候直接退出

            ret += right - cur2 + 1;
            cur1++;
        }

        //合并两个有序数组
        cur1 = left;
        cur2 = mid + 1;
        while(cur1 <= mid && cur2 <= right)
        {
            tmp[i++] = nums[cur1] >= nums[cur2] ? nums[cur1++] : nums[cur2++];
        }

        while(cur1 <= mid) tmp[i++] = nums[cur1++];
        while(cur2 <= right) tmp[i++] = nums[cur2++];

        for(int j=left; j<=right; j++)
        {
            nums[j] = tmp[j - left];
        }

        return ret;
    }
};
// @lc code=end

