/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for(int i=0; i<n-3; i++)
        {
            for(int j=i+1; j<n-2; j++)
            {
                int left = j + 1;
                int right = n - 1;
                while(left < right)
                {
                    long long sum1 = nums[right] + nums[j];
                    long long sum2 = nums[left] + nums[i];
                    if(sum2 < target - sum1)
                    {
                        ++left;
                    }
                    else if(sum2 > target - sum1)
                    {
                        --right;
                    }
                    else
                    {
                        ret.push_back({nums[i], nums[j], nums[left], nums[right]});
                        ++left;
                        --right;

                        while(left < right && nums[left] == nums[left - 1])
                        {
                            ++left;
                        } 
                        while(left < right && nums[right] == nums[right + 1])
                        {
                            --right;
                        }
                    }
                }

                while(i < n - 3 && nums[i] == nums[i + 1])
                {
                    ++i;
                }
                while(j < n - 2 && nums[j] == nums[j + 1])
                {
                    ++j;
                }
            }
        }

        return ret;
    }
};
// @lc code=end
//二刷：思路和三数求和高度相似，唯一需要注意的就是相加容易导致数据越界
//一刷：大体思路没问题，flag可以优化掉了，数据越界是真难受啊TAT
// class Solution {
// public:
//     vector<vector<int>> fourSum(vector<int>& nums, int target)
//     {
//         vector<vector<int>> vv;
//         sort(nums.begin(), nums.end());
//         long long n = nums.size();

//         for(int i=0; i<n-3; i++)
//         {
//             long long out = target - nums[i];
//             for(int j=i+1; j<n-2; j++)
//             {
//                 int left = j+1;
//                 int right = n-1;
//                 while(left < right)
//                 {
//                     long long sum = nums[left] + nums[right];

//                     if(sum < out - nums[j])
//                     {
//                         left++;
//                     }
//                     else if(sum > out - nums[j])
//                     {
//                         right--;
//                     }
//                     else
//                     {
//                         vv.push_back({nums[left], nums[right], nums[j], nums[i]});
//                         left++;
//                         right--;

//                         while(left < right && nums[left-1] == nums[left])
//                         {
//                             left++;
//                         }

//                         while(left < right && nums[right+1] ==nums[right])
//                         {
//                             right--;
//                         }
//                     }
//                 }
                        
//                 while(j < n-1 && nums[j+1] == nums[j])
//                 {
//                     j++;
//                 }
//             }

//             while(i < n-1 && nums[i+1] == nums[i])
//             {
//                 i++;
//             }
//         }

//         return vv;
//     }
// };