class Solution {
public:
    vector<int> tmp;

    int reversePairs(vector<int>& record)
    {
        tmp.resize(record.size());
        return Merge_Sort2(record, 0, record.size() - 1);
    }

    // //升序
    // int Merge_Sort1(vector<int>& nums, int left, int right)
    // {
    //     if(left >= right) return 0;

    //     int ret = 0;
    //     int mid = (left + right) / 2;

    //     //左个数 + 排序
    //     ret += Merge_Sort(nums, left, mid);
    //     //右个数 + 排序
    //     ret += Merge_Sort(nums, mid + 1, right);

    //     int cur1 = left;
    //     int cur2 = mid + 1;
    //     int i = 0;

    //     //左右升序排序
    //     while(cur1 <= mid && cur2 <= right)
    //     {
    //         if(nums[cur1] <= nums[cur2])
    //         {
    //             tmp[i++] = nums[cur1++];
    //         }
    //         else
    //         {
    //             ret += mid - cur1 + 1;
    //             tmp[i++] = nums[cur2++];
    //         }
    //     }

    //     while(cur1 <= mid) tmp[i++] = nums[cur1++];
    //     while(cur2 <= right) tmp[i++] = nums[cur2++];

    //     for(int j=left; j<=right; j++)
    //     {
    //         nums[j] = tmp[j - left];
    //     }

    //     return ret;
    // }

    //降序
    int Merge_Sort2(vector<int> &nums, int left, int right)
    {
        if(left >= right) return 0;

        int mid = (left + right) / 2;
        int ret = 0;
        
        ret += Merge_Sort2(nums, left, mid);
        ret += Merge_Sort2(nums, mid + 1, right);

        int cur1 = left;
        int cur2 = mid + 1;
        int i = 0;

        while(cur1 <= mid && cur2 <= right)
        {
            if(nums[cur1] > nums[cur2])
            {
                ret += right - cur2 + 1;
                tmp[i++] = nums[cur1++];
            }
            else
            {
                tmp[i++] = nums[cur2++];
            }
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

//一刷：先左后右，分别排序，最后左右，注意顺序和倒序时改变ret的情况不同，而且两数相等时也不能算是逆序对！