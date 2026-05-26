/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int n = height.size();
        int left = 0;
        int right = n - 1;
        int maxv = 0;

        while(left < right)
        {
            maxv = max(maxv, min(height[left], height[right]) * (right - left));

            if(height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }

        return maxv;
    }
};

// @lc code=end

//二刷：利用单调性和双指针，时间复杂度O(N)；左右指针中较小的高度向内枚举总会变小，因此可以大胆舍去
//一刷：暴力解法，两个for循环枚举全部情况，时间复杂度n*n
//通过用例58/65，超时了TvT
// class Solution {
// public:
//     int maxArea(vector<int>& height)
//     {
//         int n = height.size();
//         int maxx = 0;

//         for(int i=0; i<n-1; i++)
//         {
//             for(int j=i+1; j<n; j++)
//             {
//                 int tmp = (j-i) * min(height[j], height[i]);
//                 maxx =  max(maxx, tmp);
//             }
//         }

//         return maxx;
//     }
// };
