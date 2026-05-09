#include<iostream>
using namespace std;

namespace tairitsu_h
{
    // List的节点类
    template<class T>
    struct ListNode
    {
        ListNode(const T& val = T())
            : _pPre(nullptr)
            , _pNext(nullptr)
            , _val(val)
        {}

        ListNode<T>* _pPre;
        ListNode<T>* _pNext;
        T _val;
    };


    //List的迭代器类
    template<class T, class Ref, class Ptr>
    struct ListIterator
    {
        typedef ListNode<T>* PNode;
        typedef ListIterator<T, Ref, Ptr> Self;
        //构造函数
        ListIterator(PNode pNode = nullptr)
            :_pNode(pNode)
        {}
        
        //拷贝构造
        ListIterator(const Self& l)
            :_pNode(l._pNode)
        {}

        //解引用（返回值）
        Ref operator*()
        {
            return _pNode->_val;
        }

        //迭代器模拟指针（访问值）
        Ptr operator->()
        {
            return &(_pNode->_val);
        }

        //前置自增
        Self& operator++()
        {
            _pNode = _pNode->_pNext;
            return *this;
        }

        //后置自增
        Self operator++(int)
        {
            Self tmp = *this;
            _pNode = _pNode->_pNext;
            return tmp;
        }

        //前置自减
        Self& operator--()
        {
            _pNode = _pNode->_pPre;
            return *this;
        }

        //后置自减
        Self operator--(int)
        {
            Self tmp = *this;
            _pNode = _pNode->_pPre;
            return tmp;
        }

        //节点不同
        bool operator!=(const Self& l) const
        {
            return !(*this == l);
        }

        //节点相同
        bool operator==(const Self& l) const
        {
            return _pNode == l._pNode;
        }

        //成员变量
        PNode _pNode; //指针类型，见typedef
    };


    //list类
    template<class T>
    class list
    {
        typedef ListNode<T> Node;
        typedef Node* PNode;
    public:
        typedef ListIterator<T, T&, T*> iterator;
        typedef ListIterator<T, const T&, const T*> const_iterator;
    public:
        ///////////////////////////////////////////////////////////////
        // List的构造
        list()
        {
            CreateHead();
        }

        //List的有参构造
        list(int n, const T& value = T())
        {
            CreateHead();
            for (int i = 0; i < n; i++)
            {
                push_back(value);
            }
        }

        //其他容器构造List
        template <class Iterator>
        list(Iterator first, Iterator last)
        {
            CreateHead();
            Iterator tmp = first;
            while (tmp != last)
            {
                push_back(*tmp);
                ++tmp;
            }
        }

        //拷贝构造
        list(const list<T>& l)
        {
            CreateHead();
            for (const auto& val : l)
            {
                push_back(val);
            }
        }

        //赋值重载
        list<T>& operator=(list<T> l)
        {
            swap(l);
            return *this;
        }

        //析构
        ~list()
        {
            clear();
            delete _pHead;
        }


        ///////////////////////////////////////////////////////////////
        // List Iterator
        iterator begin()
        {
            return iterator(_pHead->_pNext);
        }
        iterator end()
        {
            return iterator(_pHead);
        }
        const_iterator begin() const
        {
            return const_iterator(_pHead->_pNext);
        }
        const_iterator end() const
        {
            return const_iterator(_pHead);
        }


        ///////////////////////////////////////////////////////////////
        // List Capacity
        size_t size()const
        {
            size_t cnt = 0;
            Node* cur = _pHead->_pNext;
            while (cur != _pHead)
            {
                cur = cur->_pNext;
                ++cnt;
            }

            return cnt;
        }

        bool empty()const
        {
            return _pHead->_pNext == _pHead;
        }

        ////////////////////////////////////////////////////////////
        // List Access
        T& front()
        {
            return _pHead->_pNext->_val;
        }

        const T& front()const
        {
            return _pHead->_pNext->_val;
        }

        T& back()
        {
            return _pHead->_pPre->_val;
        }

        const T& back()const
        {
            return _pHead->_pPre->_val;
        }

        ////////////////////////////////////////////////////////////
        // List Modify
        void push_back(const T& val) { insert(end(), val); }
        void pop_back() { erase(--end()); }
        void push_front(const T& val) { insert(begin(), val); }
        void pop_front() { erase(begin()); }

        // 在pos位置前插入值为val的节点
        iterator insert(iterator pos, const T& val)
        {
            Node* newNode = new Node(val);
            newNode->_pPre = pos._pNode->_pPre;
            newNode->_pNext = pos._pNode;

            pos._pNode->_pPre->_pNext = newNode;
            pos._pNode->_pPre = newNode;

            return iterator(newNode);
        }

        // 删除pos位置的节点，返回该节点的下一个位置
        iterator erase(iterator pos)
        {
            Node* del = pos._pNode;
            Node* pre = pos._pNode->_pPre;
            Node* next = pos._pNode->_pNext;

            pre->_pNext = next;
            next->_pPre = pre;

            delete(del);
            return iterator(next);
        }

        //清空链表
        void clear()
        {
            Node* cur = _pHead->_pNext;
            while (cur != _pHead)
            {
                Node* next = cur->_pNext;
                delete cur;
                cur = next;
            }

            _pHead->_pPre = _pHead;
            _pHead->_pNext = _pHead;
        }

        //通过交换头结点来交换链表
        void swap(list<T>& l)
        {
            swap(_pHead, l._pHead);
        }

    private:
        void CreateHead()
        {
            _pHead = new Node;
            _pHead->_pPre = _pHead;
            _pHead->_pNext = _pHead;
        }
        PNode _pHead;
    };
}