/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] 数据流的中位数
 */

// @lc code=start
class MedianFinder {
public:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;

    MedianFinder() {}
    
    void addNum(int num)
    {
        if(left.size() == right.size())
        {
            if(left.size() == 0 || num <= left.top()) left.push(num);
            else
            {
                right.push(num);
                int tmp = right.top();
                right.pop();
                left.push(tmp);
            }    
        }
        else
        {
            if(num <= left.top())
            {
                left.push(num);
                int tmp = left.top();
                left.pop();
                right.push(tmp);
            }
            else right.push(num);
        }
    }
    
    double findMedian()
    {
        if(left.size() != right.size()) return (double)left.top();
        return (left.top() + right.top()) / 2.0;    
    }
};


// @lc code=end
//二刷：优先级队列解决中位数问题，使用大根堆（左）和小根堆（右）将数据从中间划分，插入时调整堆，计算中位数取堆顶元素
//一刷：优先级队列，两个堆模拟找中位数，记住模板即可，重点在于插入元素的分类讨论
class MedianFinder {
public:
    //用两个堆模拟（大根堆和小根堆）
    priority_queue<int> left; //大根堆
    priority_queue<int, vector<int>, greater<int>> right; //小根堆

    MedianFinder()
    {}
    
    void addNum(int num)
    {
        //分类讨论
        int m = left.size();
        int n = right.size();
        if(m == n)
        {
            if(m == 0 || num <= left.top()) left.push(num);
            if(num > left.top())
            {
                right.push(num);
                int y = right.top();
                right.pop();
                left.push(y);
            }
        }
        else // m == n + 1  
        {
            if(num <= left.top())
            {
                left.push(num); 
                int x = left.top();
                left.pop();
                right.push(x);
            }
            else right.push(num); // m == n
        }
    }
    
    double findMedian()
    {
        if(left.size() != right.size()) return (double)left.top();
        return (double)((left.top() + right.top()) / 2.0);
    }
};