/*
 * @lc app=leetcode.cn id=2208 lang=cpp
 *
 * [2208] 将数组和减半的最少操作次数
 */

// @lc code=start
class Solution {
public:
    int halveArray(vector<int>& nums)
    {
        priority_queue<double> heap(nums.begin(), nums.end());
        double sum = 0;
        for(auto x : nums) sum += x;

        int ret = 0;
        double tmp = 0;
        cout << sum << endl;
        while(tmp < sum / 2)
        {  
            ++ret;
            double top = heap.top();
            heap.pop();

            double newt = top / 2;
            tmp += newt;
            heap.push(newt);
        }    

        cout << tmp << endl;

        return ret;
    }
};
// @lc code=end
//一刷：贪心策略，注意数据用double来存储！！另外还要注意变量的类型！
