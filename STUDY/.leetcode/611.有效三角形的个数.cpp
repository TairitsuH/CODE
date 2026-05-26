/*
 * @lc app=leetcode.cn id=611 lang=cpp
 *
 * [611] 有效三角形的个数
 */
// @lc code=start
class Solution {
public:
    int triangleNumber(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        int cnt = 0;

        for(int i=nums.size()-1; i>=2; i--)
        {
            int left = 0;
            int right = i-1;
            while(left < right)
            {
                if(nums[left] + nums[right] > nums[i])
                {
                    cnt += right - left;
                    right--;
                }
                else
                {
                    left++;
                }
            }
        }

        return cnt;
    }
};

// @lc code=end
//二刷：排序->单调性+双指针，时间复杂度O(N*N)，注意循环是自减！
//一刷：思路是先排序，然后顺序挑选两个数和后面的数进行比较，若大于则计数，小于则重新循环
//时间复杂度O(N*logN + N*N*N)
// class Solution {
// public:
//     int triangleNumber(vector<int>& nums)
//     {
//         sort(nums.begin(), nums.end());
//         int cnt = 0;
//         int n = nums.size();

//         for(int i=0; i<n-2; i++)
//         {
//             for(int j=i+1; j<n-1; j++)
//             {
//                 int gap = j + 1;
//                 while(gap < n && nums[i] + nums[j] > nums[gap])
//                 {
//                     cnt++;
//                     gap++;
//                 }
//             }
//         }

//         return cnt;
//     }
// };
