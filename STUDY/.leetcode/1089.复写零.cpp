/*
 * @lc app=leetcode.cn id=1089 lang=cpp
 *
 * [1089] 复写零
 */
// @lc code=start
class Solution {
public:
    void duplicateZeros(vector<int>& arr)
    {
        int n = arr.size();

        for(int i=0; i<n; i++)
        {
            if(arr[i] == 0)
            {
                arr.insert(arr.begin()+i, 0);
                i += 1;
            }
        }

        arr.resize(n);
    }
};
// @lc code=end

//一刷：注意迭代器的失效问题！循环和内部都涉及了i的修改