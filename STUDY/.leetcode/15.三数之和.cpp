/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());

        vector<vector<int>> vv;

        int n = nums.size();
        for(int i=0; i<n-2; i++)
        {
            int left = i+1;
            int right = n-1;
            int flag = 0;

            while(left < right)
            {
                if(nums[left] + nums[right] == -nums[i])
                {
                    flag = 1;
                    vv.push_back({nums[left], nums[right], nums[i]});

                    left++;
                    right--;

                    //去重left和right
                    while(left < right && nums[left-1] == nums[left])
                    {
                        left++;
                    }

                    while(left < right && nums[right+1] == nums[right])
                    {
                        right--;
                    }
                }
                else if(nums[left] + nums[right] > -nums[i])
                {
                    right--;
                }
                else
                {
                    left++;
                }
            }

            //去重i
            if(flag == 1)
            {
                while(i < n-2 && nums[i] == nums[i+1])
                {
                    i++;
                }
            }
        }

        return vv;
    }
};

// @lc code=end
//二刷：排序+选定数据+双指针+去重
//一刷：排序，暴力枚举，放进set里，然后放入vector。
//超时了TAT
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums)
//     {
//         int n = nums.size();
//         sort(nums.begin(), nums.end());
//         set<vector<int>> s;

//         for(int i=0; i<n-2; i++)
//         {
//             for(int j=i+1; j<n-1; j++)
//             {
//                 for(int k=j+1; k<n; k++)
//                 {
//                     vector<int> v;
//                     if(nums[i] + nums[j] + nums[k] == 0)
//                     {
//                         v.push_back(nums[i]);
//                         v.push_back(nums[j]);
//                         v.push_back(nums[k]);
//                         s.insert(v);
//                     }
//                 }
//             }
//         }

//         vector<vector<int>> vvret(s.begin(), s.end());

//         return vvret;
//     }
// };
