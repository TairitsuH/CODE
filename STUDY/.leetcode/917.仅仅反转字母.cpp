/*
 * @lc app=leetcode.cn id=917 lang=cpp
 *
 * [917] 仅仅反转字母
 */
#include<iostream>
using namespace std;


// @lc code=start
class Solution {
public:
    string reverseOnlyLetters(string s)
    {
        int right = s.size() - 1;
        int left = 0;

        while(left < right)
        {
            while(left < right && !isalpha(s[left]))
            {
                left++;
            }
            while(left < right && !isalpha(s[right]))
            {
                right--;
            }

            swap(s[left], s[right]);

            left++;
            right--;
        }

        return s;
    }
};
// @lc code=end
//一刷：注意比较的是s不是left和right！不是比较下标TvT