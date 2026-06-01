#include<iostream>
using namespace std;

template<class K, class V>
struct BSTreeNode
{
    K _key;
    V _value;
    BSTreeNode<K, V>* _left;
    BSTreeNode<K, V>* _right;

    BSTreeNode(const K& key, const V& value)
    :_key(key)
    ,_value(value)
    ,_left(nullptr)
    ,_right(nullptr)
    {}
};

template<class K, class V>
class BSTree
{
	typedef BSTreeNode<K, V> Node;

private:
	Node* _root = nullptr;

public:
    //构造
    BSTree() = default;

    //拷贝构造
    BSTree(const BSTree<K, V>& t)
    {
        _root = Copy(t._root);
    }

    Node* Copy(Node& n)
    {
        if(n == nullptr)
        {
            return nullptr;
        }

        Node* newnode = new Node(n->_key, n->_value);
        newnode->_left = Copy(n->_left);
        newnode->_right = Copy(n->_right);

        return newnode;
    }

    //赋值重载
    BSTree<K, V>& operator=(BSTree<K, V> t)
    {
        swap(t._root, _root);
        return *this;
    }
    
    //插入节点
	bool Insert(const K& key, const V& value)
    {
        //处理空树
        if(_root == nullptr)
        {
            Node* tmp = new Node(key, value);
            _root = tmp;
            return true;
        }
        
        //移动至叶子节点
        Node* cur = _root;
        Node* parent = nullptr;
        while(cur)
        {
            if(cur->_key < key)
            {
                parent = cur;
                cur = cur->_right;
            }
            else if(cur->_key > key)
            {
                parent = cur;
                cur = cur->_left;
            }
            else
            {
                return false;
            }
        }

        //插入
        Node* newnode = new Node(key, value);
        if(parent->_key > key)
        {
            parent->_left = newnode;
        }
        else
        {
            parent->_right = newnode;
        }

        return true;
    }

    //查找节点
	Node* Find(const K& key)
    {
        Node* cur = _root;
        while(cur)
        {
            if(cur->_key < key)
            {
                cur = cur->_right;
            }
            else if(cur->_key > key)
            {
                cur = cur->_left;
            }
            else
            {
                return cur;
            }
        }

        return nullptr;
    }

    //删除节点
	bool Erase(const K& key)
    {
        Node* parent = nullptr;
        Node* cur = _root;

        //找节点
        while(cur)
        {
            if(cur->_key < key)
            {
                parent = cur;
                cur = cur->_right;
            }
            else if(cur->_key > key)
            {
                parent = cur;
                cur = cur->_left;
            }
            else //找到key
            {
                //1. c左为空
                if(cur->_left == nullptr)
                {
                    //根节点
                    if(parent == nullptr)
                    {
                        _root = cur->_right;
                    }
                    else //非根节点
                    {
                        //p左为c
                        if(parent->_left == cur)
                        {
                            parent->_left = cur->_right;
                        }
                        else 
                        {
                            parent->_right = cur->_right;
                        }
                    }
                }
                //2. c右为空
                else if(cur->_right == nullptr)
                {
                    //根节点
                    if(parent == nullptr)
                    {
                        _root = cur->_left;
                    }
                    else //非根节点
                    {
                        //p左为c
                        if(parent->_left = cur)
                        {
                            parent->_left = cur->_left;
                        }
                        else //p右为c
                        {
                            parent->_right = cur->_left;
                        }
                    }
                }
                //3. c左右非空，找右子树的最小节点
                else
                {
                    Node* RNodeP = cur;
                    Node* RNodeC = cur->_left;
                    while(RNodeC)
                    {
                        RNodeP = RNodeC;
                        RNodeC = RNodeC->_left;
                    }

                    //赋值
                    cur->_key = RNodeC->_key;
                    cur->_value = RNodeC->_value;

                    //转化为1，2情况（c左为空）
                    if(RNodeP->_left == RNodeC) //p左为c
                    {
                        RNodeP->_left = RNodeC->_right;
                    }
                    else //p右为c
                    {
                        RNodeP->_right = RNodeC->_right;
                    }
                }

                delete cur;
                return true;
            }
        }

        return false;
    }

    //中序遍历
	void InOrder()
    {
        _InOrder(_root);
        cout << endl;
    }

private:
    //中序遍历（设置为私有，方便访问root）
	void _InOrder(Node* root)
    {
        if(root == nullptr)
        {
            return;
        }

        _InOrder(root->_left);
        cout << root->_key << ":" << root->_value << endl;
        _InOrder(root->_right);
    }
};

void TestBSTree()
{
	BSTree<string, string> dict;
	dict.Insert("insert", "插入");
	dict.Insert("erase", "删除");
	dict.Insert("left", "左边");
	dict.Insert("string", "字符串");

	string str;
	while (cin >> str)
	{
		auto ret = dict.Find(str);
		if (ret)
		{
			cout << str << ":" << ret->_value << endl;
		}
		else
		{
			cout << "单词拼写错误" << endl;
		}
	}

	string strs[] = { "苹果", "西瓜", "苹果", "樱桃", "苹果", "樱桃", "苹果", "樱桃", "苹果" };
	// 统计水果出现的次
	BSTree<string, int> countTree;
	for (auto str : strs)
	{
		auto ret = countTree.Find(str);
		if (ret == NULL)
		{
			countTree.Insert(str, 1);
		}
		else
		{
			ret->_value++;
		}
	}
	countTree.InOrder();
}