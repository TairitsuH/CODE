#pragma once
#include<utility>
#include<iostream>
using namespace std;

namespace mzh
{
    //枚举值表示颜色
    enum Colour
    {
        RED,
        BLACK
    };

    //节点
    template<class T>
    struct RBTreeNode
    {
    public:
        T _data; //让节点可以同时用于set(key)和map(pair)
        RBTreeNode<T>* _left;
        RBTreeNode<T>* _right;
        RBTreeNode<T>* _parent;
        Colour _col;

        //构造函数
        RBTreeNode(const T& data)
            :_data(data)
            , _left(nullptr)
            , _right(nullptr)
            , _parent(nullptr)
            , _col(RED)
        {
        }
    };

    //迭代器
    template<class T, class Ref, class Ptr>
    struct RBTreeIterator
    {
    public:
        typedef RBTreeNode<T> Node; //节点类型
        typedef RBTreeIterator<T, T&, T*> Self; //红黑树迭代器（根据RBTreeIterator的模板）

        Node* _node;
        Node* _root;

        //构造
        RBTreeIterator(Node* node, Node* root)
            :_node(node)
            , _root(root)
        {
            cout << "Instructor" << endl;
        }

        //重载++
        Self& operator++()
        {
            //1.右不为空，则下一个节点为右子树的最左节点
            if (_node->_right)
            {
                Node* leftmost = _node->_right;
                while (leftmost && leftmost->_left)
                {
                    leftmost = leftmost->_left;
                }

                _node = leftmost;
            }
            //2.右为空，向上查找直至该节点为左孩子时，返回父节点
            else
            {
                Node* cur = _node;
                Node* parent = _node->_parent;
                while (parent && cur == parent->_right)
                {
                    cur = parent;
                    parent = parent->_parent;
                }

                _node = parent;
            }

            return *this;
        }

        //重载--
        Self& operator--()
        {
            //1.根节点，找树最右侧节点
            if (_node == _root)
            {
                Node* rightmost = _node;
                while (rightmost && rightmost->_right)
                {
                    rightmost = rightmost->_right;
                }

                _node = rightmost;
            }
            //2.左为空，向上查找直至该节点为右孩子时，返回父节点
            else
            {
                Node* cur = _node;
                Node* parent = _node->_parent;
                while (parent && cur == parent->_left)
                {
                    cur = parent;
                    parent = parent->_parent;
                }

                _node = parent;
            }

            return *this;
        }

        //重载*：返回整个对象（解引用）
        Ref operator*()
        {
            return _node->_data;
        }

        //重载->：返回对象内部成员的地址
        Ptr operator->()
        {
            return &_node->_data;
        }

        //重载!=
        bool operator!=(const Self& s) const
        {
            return _node != s._node;
        }

        //重载==
        bool operator==(const Self& s) const
        {
            return _node == s._node;
        }
    };

    //树
    template<class K, class T, class KeyOfT> //KeyOfT是仿函数类型
    class RBTree
    {
    private:
        typedef RBTreeNode<T> Node;
        Node* _root = nullptr;

    public:
        typedef RBTreeIterator<T, T&, T*> Iterator;
        typedef RBTreeIterator<T, const T&, const T*> ConstIterator;

        //迭代器Begin：找树的最左节点
        Iterator Begin()
        {
            Node* leftmost = _root;
            while (leftmost && leftmost->_left)
            {
                leftmost = leftmost->_left;
            }

            Iterator ret = Iterator(leftmost, _root);
            return ret; //或者直接返回构造return RBTreeIterator(leftmost, _root);
        }

        //迭代器End：根节点的_parent，即空指针
        Iterator End()
        {
            return Iterator(nullptr, _root);
        }

        //迭代器ConstBegin
        ConstIterator Begin() const
        {
            Node* leftmost = _root;
            while (leftmost && leftmost->_left)
            {
                leftmost = leftmost->_left;
            }

            return ConstIterator(leftmost, _root);
        }

        //迭代器ConstEnd
        ConstIterator End() const
        {
            return ConstIterator(nullptr, _root);
        }

        //析构函数
        ~RBTree()
        {
            Destroy(_root);
            _root = nullptr;
        }

        //插入
        pair<Iterator, bool> Insert(const T& data)
        {
            //根
            if (!_root)
            {
                _root = new Node(data);
                _root->_col = BLACK;
                return { Iterator(_root, _root), true }; //改成iterator的形式
            }

            //非根
            KeyOfT kot; //比较逻辑（可以像类一样使用）
            Node* cur = _root;
            Node* parent = nullptr;
            while (cur)
            {
                if (kot(cur->_data) < kot(data))
                {
                    parent = cur;
                    cur = cur->_right;
                }
                else if (kot(cur->_data) > kot(data))
                {
                    parent = cur;
                    cur = cur->_left;
                }
                else
                {
                    return { Iterator(cur, _root), false }; //改成iterator的形式
                }
            }

            //新建节点
            cur = new Node(data);
            cur->_col = RED;

            if (kot(parent->_data) < kot(data)) //右
            {
                parent->_right = cur;
            }
            else //左
            {
                parent->_left = cur;
            }

            cur->_parent = parent;

            //旋转调整
            while (parent && parent->_col == RED)
            {
                Node* grandfather = parent->_parent;

                //p在g左
                if (parent == grandfather->_left)
                {
                    Node* uncle = grandfather->_right;

                    //u存在且为红->变色继续向上处理
                    if (uncle && uncle->_col == RED)
                    {
                        parent->_col = BLACK;
                        uncle->_col = BLACK;
                        grandfather->_col = RED;

                        cur = grandfather;
                        parent = grandfather->_parent;
                    }
                    else //u不存在或为黑
                    {
                        if (cur == parent->_left)
                        {
                            RotateR(grandfather);

                            parent->_col = BLACK;
                            grandfather->_col = RED;
                        }
                        else
                        {
                            RotateL(parent);
                            RotateR(grandfather);

                            cur->_col = BLACK;
                            grandfather->_col = RED;
                        }

                        break;
                    }
                }
                //p在g右
                else
                {
                    Node* uncle = grandfather->_left;
                    //仅变色
                    if (uncle && uncle->_col == RED)
                    {
                        parent->_col = BLACK;
                        uncle->_col = BLACK;
                        grandfather->_col = RED;

                        cur = parent;
                        parent = grandfather;
                    }
                    else //旋转 + 变色
                    {
                        if (cur == parent->_right)
                        {
                            RotateL(grandfather);

                            parent->_col = BLACK;
                            grandfather->_col = RED;
                        }
                        else
                        {
                            RotateR(parent);
                            RotateL(grandfather);

                            cur->_col = BLACK;
                            grandfather->_col = RED;
                        }

                        break;
                    }
                }
            }

            //一律设置为黑
            _root->_col = BLACK;

            return { Iterator(cur, _root), true }; //改成iterator的形式
        }

        //通过key查找
        Iterator Find(const K& key)
        {
            KeyOfT kot; //比较逻辑（可以像类一样使用）
            Node* cur = _root;
            while (cur)
            {
                if (kot(cur->_data) > key)
                {
                    cur = cur->_left;
                }
                else if (kot(cur->_data) < key)
                {
                    cur = cur->_right;
                }
                else
                {
                    return Iterator(cur, _root);
                }
            }

            return End();
        }

    private:
        //右旋
        void RotateR(Node* pParent)
        {
            Node* parent = pParent;
            Node* subL = parent->_left;
            Node* subLR = subL->_right;

            //1.parent和subLR
            parent->_left = subLR;

            if (subLR)
            {
                subLR->_parent = parent;
            }

            Node* parentParent = parent->_parent;

            //2.parent和subL
            parent->_parent = subL;
            subL->_right = parent;

            //3.subL和parentParent
            if (parentParent == nullptr)
            {
                _root = subL;
                subL->_parent = nullptr;
            }
            else
            {
                if (parentParent->_left == parent)
                {
                    parentParent->_left = subL;
                }
                else
                {
                    parentParent->_right = subL;
                }

                subL->_parent = parentParent;
            }
        }

        //左旋
        void RotateL(Node* pParent)
        {
            Node* parent = pParent;
            Node* subR = parent->_right;
            Node* subRL = subR->_left;

            //1.parent和subRL
            parent->_right = subRL;
            if (subRL)
            {
                subRL->_parent = parent;
            }

            //2.parent和subR
            Node* parentParent = parent->_parent;

            parent->_parent = subR;
            subR->_left = parent;

            //3.subR和parentParent
            if (parentParent == nullptr)
            {
                _root = subR;
                subR->_parent = nullptr;
            }
            else
            {
                if (parentParent->_left == parent)
                {
                    parentParent->_left = subR;
                }
                else
                {
                    parentParent->_right = subR;
                }

                subR->_parent = parentParent;
            }
        }

        //递归销毁
        void Destroy(Node* root)
        {
            if (root == nullptr) return;

            Destroy(root->_left);
            Destroy(root->_right);
            delete root;
        }
    };
}