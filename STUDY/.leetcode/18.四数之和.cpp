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
        vector<vector<int>> vv;
        sort(nums.begin(), nums.end());
        long long n = nums.size();

        for(int i=0; i<n-3; i++)
        {
            long long out = target - nums[i];
            for(int j=i+1; j<n-2; j++)
            {
                int left = j+1;
                int right = n-1;
                while(left < right)
                {
                    long long sum = nums[left] + nums[right];

                    if(sum < out - nums[j])
                    {
                        left++;
                    }
                    else if(sum > out - nums[j])
                    {
                        right--;
                    }
                    else
                    {
                        vv.push_back({nums[left], nums[right], nums[j], nums[i]});
                        left++;
                        right--;

                        while(left < right && nums[left-1] == nums[left])
                        {
                            left++;
                        }

                        while(left < right && nums[right+1] ==nums[right])
                        {
                            right--;
                        }
                    }
                }
                        
                while(j < n-1 && nums[j+1] == nums[j])
                {
                    j++;
                }
            }

            while(i < n-1 && nums[i+1] == nums[i])
            {
                i++;
            }
        }

        return vv;
    }
};
// @lc code=end
//一刷：大体思路没问题，flag可以优化掉了，数据越界是真难受啊TAT

