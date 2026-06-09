#include<utility>

//枚举值表示颜色
enum Colour
{
    RED,
    BLACK
};

//节点
template<class K, class V> //按照key/value的结构实现
struct RBTreeNode
{
    pair<K, V> _kv;
    RBTreeNode<K, V>* _left;
    RBTreeNode<K, V>* _right;
    RBTreeNode<K, V>* _parent;
    Colour _col;

    RBTreeNode(const pair<K, V>& kv)
    :_kv(kv)
    ,_left(nullptr)
    ,_right(nullptr)
    ,_parent(nullptr)
    {}
};

//树
template<class K, class V>
class RBTree
{
private:
    typedef RBTreeNode<K, V> Node;
    Node* _root = nullptr;

public:
    //插入
    bool Insert(const pair<K, V>& kv)
    {
        //根
        if(!_root)
        {
            _root = new Node(kv);
            _root->_col = BLACK;
            return true;
        }

        //非根
        Node* cur = _root;
        Node* parent = nullptr;
        while(cur)
        {
            if(cur->kv.first < kv.first)
            {
                parent = cur;
                cur = cur->_right;
            }
            else if(cur->_kv.first > kv.first)
            {
                parent = cur;
                cur = cur->_left;
            }
            else
            {
                return false;
            }
        }

        //新建节点
        cur = new Node(kv);
        cur->_col = RED;

        if(parent->_kv.first < kv.first) //右
        {
            parent->_right = cur;
        }
        else
        {
            parent->_left = cur;
        }

        cur->_parent = parent;

        //旋转调整
        while(parent && parent->_col = RED)
        {
            Node* grandfather = parent->_parent;

            //p在g左
            if(parent == grandfather->_left)
            {
                Node* uncle = grandfather->_right;

                //u存在且为红->变色继续向上处理
                if(uncle && uncle->_col == RED)
                {
                    parent->_col = BLACK;
                    uncle->_col = BLACK;
                    grandfather->_col = RED;

                    cur = grandfather;
                    parent = grandfather->_parent;
                }
                else //u不存在或为黑
                {
                    if(cur == parent->_left)
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
                if(uncle && uncle->_col == RED)
                {
                    parent->_col = BLACK;
                    uncle->_col = BLACK;
                    grandfather->_col = RED;

                    cur = parent;
                    parent = grandfather;
                }
                else //旋转 + 变色
                {
                    if(cur == parent->_right)
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

        return true;
    }

    //右旋
    void RotateR(Node* pParent)
    {
        Node* parent = pParent;
        Node* subL = parent->_left;
        Node* subLR = subL->_right;

        //1.parent和subLR
        parent->_left = subLR;

        if(subLR)
        {
            subLR->_parent = parent;
        }

        Node* parentParent = parent->_parent;

        //2.parent和subL
        parent->_parent = subL;
        subL->_right = parent;

        //3.subL和parentParent
        if(parentParent == nullptr)
        {
            _root = subL;
            subL->_parent = nullptr;
        }
        else
        {
            if(parentParent->_left == parent)
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
        if(subRL)
        {
            subRL->_parent = parent;
        }

        //2.parent和subR
        Node* parentParent = parent->_parent;

        parent->_parent = subR;
        subR->_left = parent;

        //3.subR和parentParent
        if(parentParent == nullptr)
        {
            _root = subR;
            subR->_parent = nullptr;
        }
        else
        {            
            if(parentParent->_left == parent)
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

    //查找
    Node* Find(const K& key)
    {
        Node* cur = _root;
        while(cur)
        {
            if(cur->_kv.first > key)
            {
                cur = cur->_left;
            }
            else if(cur->_kv.first < key)
            {
                cur = cur->_right;
            }
            else
            {
                return cur;
            }
        }

        return nullptr;
    }
};