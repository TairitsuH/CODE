/*
 * @lc app=leetcode.cn id=315 lang=cpp
 *
 * [315] 计算右侧小于当前元素的个数
 */

// @lc code=start
class Solution {
public:
    vector<int> tmp_nums;
    vector<int> tmp_in;
    vector<int> ret;
    vector<int> index;

    vector<int> countSmaller(vector<int>& nums)
    {
        int n = nums.size();

        index.resize(n);
        ret.resize(n);
        tmp_nums.resize(n);
        tmp_in.resize(n);

        for(int i=0; i<n; i++) index[i] = i;

        Merge_Sort(nums, index, 0, n - 1);

        return ret;
    }

    void Merge_Sort(vector<int>& nums, vector<int>& index, int left, int right)
    {
        if(left >= right) return;

        int mid = (left + right) / 2;

        Merge_Sort(nums, index, left, mid);
        Merge_Sort(nums, index, mid + 1, right);

        int cur1 = left;
        int cur2 = mid + 1;
        int i = 0;
        int j = 0;

        while(cur1 <= mid && cur2 <= right)
        {
            if(nums[cur1] > nums[cur2])
            {
                ret[index[cur1]] += right - cur2 + 1;
                tmp_nums[i++] = nums[cur1];
                tmp_in[j++] = index[cur1];
                cur1++;
            }
            else
            {
                tmp_nums[i++] = nums[cur2];
                tmp_in[j++] = index[cur2];
                cur2++;
            }
        }

        while(cur1 <= mid)
        {
            tmp_nums[i++] = nums[cur1];
            tmp_in[j++] = index[cur1++];
        }

        while(cur2 <= right)
        {
            tmp_nums[i++] = nums[cur2];
            tmp_in[j++] = index[cur2++];
        }

        for(int k=left; k<=right; k++)
        {
            nums[k] = tmp_nums[k - left];
            index[k] = tmp_in[k - left];
        }
    }
};
// @lc code=end
//一刷：归并排序，需要两个数组和两个辅助数组，搞清楚下标逻辑后还是很好处理的