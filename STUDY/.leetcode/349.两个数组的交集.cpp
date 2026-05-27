/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> v;
        set<int> s1(nums1.begin(), nums1.end());
        set<int> s2(nums2.begin(), nums2.end());

        auto p1 = s1.begin();
        auto p2 = s2.begin();
        while(p1 != s1.end() && p2 != s2.end())
        {
            if(*p1 == *p2)
            {
                v.push_back(*p1);
                p1++;
                p2++;
            }
            else if(*p1 < *p2)
            {
                p1++;
            }
            else
            {
                p2++;
            }
        }

        return v;
    }
};
// @lc code=end
//一刷：先将两个数组去重+排序（set），再用双指针(迭代器类型！)找交集。
