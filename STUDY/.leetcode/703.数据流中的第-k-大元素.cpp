/*
 * @lc app=leetcode.cn id=703 lang=cpp
 *
 * [703] 数据流中的第 K 大元素
 */

// @lc code=start
class KthLargest {
public:
    int _k;
    priority_queue<int, vector<int>, greater<int>> heap;
    
    KthLargest(int k, vector<int>& nums)
    {
        _k = k;
        for(auto x : nums)
        {
            heap.push(x);
            if(heap.size() > _k) heap.pop();
        }
    }
    
    int add(int val)
    {
        heap.push(val);
        if(heap.size() > _k) heap.pop();

        return heap.top();
    }
};


/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end
//二刷：优先级队列，topK问题，入堆的方式有：1.和堆顶元素比较 / 2.先插入后比较size和_k
//一刷：优先级队列，topK问题（解法有堆和快速选择算法，面试常考），求topk大元素用小根堆，topk小元素用大根堆（和堆顶元素比较）
//或者先入堆再判断是否超过k个
class KthLargest {
public:
    int _k;
    priority_queue<int, vector<int>, greater<int>> heap;

    KthLargest(int k, vector<int>& nums)
    {
        _k = k;
        for(auto x : nums)
        {
            if(heap.size() < k) heap.push(x);
            else
            {
                if(heap.top() < x)
                {
                    heap.pop();
                    heap.push(x);
                }
            }
        }        
    } 
    
    int add(int val)
    {
        if(heap.size() < _k) heap.push(val);
        else if(heap.top() < val)
        {
            heap.pop();
            heap.push(val);
        }

        return heap.top();
    }
};