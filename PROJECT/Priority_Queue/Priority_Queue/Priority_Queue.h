#include<iostream>
#include<vector>
#include<functional>
using namespace std;

namespace tairitsu_h
{
    template< class T, class Container = std::vector<T>, class Compare = less<T> >

    class priority_queue
    {
    public:

        priority_queue()
        {}

        template <class InputIterator>
        priority_queue(InputIterator first, InputIterator last)
            :c(first, last)
        {
            //建堆
            // make_heap(c.begin(), c.end(), comp);
            
            for (int i = (c.size()-1-1)/2; i >= 0; i--)
            {
                adjust_down(i);
            }
        }

        bool empty() const
        {
            return c.empty();
        }

        size_t size() const
        {
            return c.size();
        }

        T& top() const
        {
            return c[0];
        }

        void push(const T& x)
        {
            c.push_back(x);
            
            //库中堆算法： push_heap(c.begin(), c.end(), comp);
            adjust_up(c.size() - 1);
        }

        void pop()
        {
            //堆算法实现交换和调整： pop_heap(c.begin(), c.end(), comp);
            swap(c[0], c[c.size() - 1]);
            adjust_down(0);
            
            c.pop_back();
        }

    private:
        Container c; //底层容器
        Compare comp; //比较规则

        void adjust_up(size_t child)
        {
            while (child > 0)
            {
                size_t parent = (child - 1) / 2;
                if (comp(c[parent], c[child]))
                {
                    break;
                }

                swap(c[child], c[parent]);
                child = parent;
            }
        }

        void adjust_down(size_t parent)
        {
            size_t child = parent * 2 + 1;
            while (child < c.size())
            {
                if (child + 1 < c.size() && comp(c[child], c[child + 1]))
                {
                    ++child;
                }
                if (comp(c[parent], c[child]))
                {
                    break;
                }
    
                swap(c[parent], c[child]);
                parent = child;
                child = parent * 2 + 1;
            }
        }
    };
};