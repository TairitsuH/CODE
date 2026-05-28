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

    BSTree<K, V> Copy(Node& n)
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
        Node* parent = _root;
        while(cur != nullptr)
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

            return nullptr;
        }

        return nullptr;
    }

    // //删除节点
	// bool Erase(const K& key)
    // {

    // }

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