/*
 * @lc app=leetcode.cn id=1046 lang=cpp
 *
 * [1046] 最后一块石头的重量
 */

// @lc code=start
class Solution {
public:
    int lastStoneWeight(vector<int>& stones)
    {
        priority_queue<int> heap;
        for(auto x : stones) heap.push(x); 

        while(heap.size() > 1)
        {
            int y = heap.top();
            heap.pop(); 
            int x = heap.top();
            heap.pop();
            int tmp = y - x;

            if(tmp != 0) heap.push(tmp);
        }   

        return heap.size() == 0 ? 0 : heap.top();
    }
};
// @lc code=end

//一刷：优先级队列（堆），挑一个max，从剩下的继续挑max很符合堆的结构