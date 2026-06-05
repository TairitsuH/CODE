template<class T>
struct AVLTreeNode
{
	AVLTreeNode(const T& data = T())
		: _pLeft(nullptr)
		, _pRight(nullptr)
		, _pParent(nullptr)
		, _data(data)
		, _bf(0)
	{}

	AVLTreeNode<T>* _pLeft;
	AVLTreeNode<T>* _pRight;
	AVLTreeNode<T>* _pParent;
	T _data;
	int _bf;   // 节点的平衡因子
};


// AVL: 二叉搜索树 + 平衡因子的限制
template<class T>
class AVLTree
{
	typedef AVLTreeNode<T> Node;
public:
	AVLTree()
		: _pRoot(nullptr)
	{}

	// 在AVL树中插入值为data的节点
	bool Insert(const T& data)
	{
		//1.在空位置插入节点
		Node* cur = _proot;
		Node* parent = nullptr;

		//根节点
		if (!_pRoot)
		{
			_pRoot = new Node(data);
			return true;
		}
		else //非根节点
		{
			while (cur)
			{
				if (cur->_data < data)
				{
					parent = cur;
					cur = cur->_pRight;
				}
				else if (cur->_data > data)
				{
					parent = cur;
					cur = cur->_pLeft;
				}
				else
				{
					return false;
				}
			}

			//插入节点，更新父子指针
			cur = new Node(data);
			if (parent->_data > data)
			{
				parent->_pLeft = cur;
			}
			else
			{
				parent->_pRight = cur;
			}

			cur->_pParent = parent;

			//2.更新平衡因子
			while (parent)
			{
				//更新
				if (cur == parent->_pLeft)
				{
					parent->_bf--;
				}
				else
				{
					parent->_bf++;
				}

				//判断停止条件
				if (abs(parent->_bf) == 1) //继续
				{
					cur = parent;
					parent = parent->_pParent;
				}
				else if (abs(parent->_bf) == 0) //停止
				{
					break;
				}
				else if (abs(parent->_bf) == 2) //旋转
				{
					if (parent->_bf == -2 && cur->_bf == -1) //右单旋
					{
						RotateR(parent);
					}
					else if (parent->_bf == 2 && cur->_bf == 1) //左单旋
					{
						RotateL(parent);
					}
					else if(parent->_bf == 2 && cur->_bf == -1) //右左单旋
					{
						RotateRL(parent);
					}
					else if (parent->_bf == -2 && cur->_bf == 1) //左右单旋
					{
						RotateLR(parent);
					}
					else
					{
						assert(false);
					}

					break;
				}
			}

			return true;
		}
	}

	// AVL树的验证
	bool IsAVLTree()
	{
		return _IsAVLTree(_pRoot);
	}

private:
	// 根据AVL树的概念验证pRoot是否为有效的AVL树
	bool _IsAVLTree(Node* pRoot);
	size_t _Height(Node* pRoot);

	// 右单旋
	void RotateR(Node* pParent)
	{
		Node* parent = pParent;
		Node* subL = parent->_pLeft;
		Node* subLR = subL->_pRight;

		parent->_pLeft = subLR;
		if (subLR) //h > 0时
		{
			subLR->_pParent = parent;
		}

		Node* parentParent = parent->_pParent;

		subL->_pRight = parent;
		parent->_pParent = subL;

		//判断parent是否为根
		if (parentParent == nullptr)
		{
			_pRoot = subL;
			subL->_pParent = nullptr;
		}
		else //左右子树
		{
			if (parent == parentParent->_pLeft)
			{
				parentParent->_pLeft = subL;
			}
			else
			{
				parentParent->_pRight = subL;
			}

			subL->_pParent = parentParent;
		}

		//更新平衡因子
		parent->_bf = 0;
		subL->_bf = 0;
	}

	// 左单旋
	void RotateL(Node* pParent)
	{
		Node* parent = pParent;
		Node* subR = parent->_pRight;
		Node* subRL = subR->_pLeft;

		parent->_pRight = subRL;
		if(subLR) //h > 0时
		{
			subRL->_pParent = parent;
		}

		Node* parentParent = parent->_pParent;

		subR->_pLeft = parent;
		parent->_pParent = subR;

		//判断parent是否为根
		if (parentParent == nullptr)
		{
			_pRoot = subR;
			subR->_pParent = nullptr;
		}
		else
		{
			if (parentParent->_pLeft == parent)
			{
				parentParent->_pLeft = subR;
			}
			else
			{
				parentParent->_pRight = subR;
			}

			subR->_pParent = parentParent;
		}

		//更新平衡因子
		parent->_bf = 0;
		subR->_bf = 0;
	}

	// 左右双旋
	void RotateRL(Node* pParent)
	{
		Node* parent = pParent;
		Node* subL = parent->_pLeft;
		Node* subLR = subL->_pRight;

		RotateL(subL); //左
		RotateR(parent); //右

		//更新平衡因子
		if (subLR->_bf == 1)
		{
			subLR->_bf = 0;
			subL->_bf = -1;
			parent->_bf = 0;
		}
		else if (subLR->_bf == 0)
		{
			subLR->_bf = 0;
			subL->_bf = 0;
			parent->_bf = 0;
		}
		else if (subLR->_bf == -1)
		{
			subLR->_bf = 0;
			subL->_bf = 0;
			parent->_bf = 1;
		}
		else
		{
			return false;
		}
	}


	// 右左双旋
	void RotateLR(Node* pParent)
	{
		Node* parent = pParent;
		Node* subR = parent->_pRight;
		Node* subRL = subR->_pLeft;

		RotateR(subRL); //右
		RotateL(parent); //左

		//更新平衡因子
		if (subRL->_bf == 1)
		{
			subRL->_bf = 0;
			subR->_bf = 0;
			parent->_bf = -1;
		}
		else if (subRL->_bf == 0)
		{
			subRL->_bf = 0;
			subR->_bf = 0;
			parent->_bf = 0;
		}
		else if (subRL->_bf == -1)
		{
			subRL->_bf = 0;
			subR->_bf = 1;
			parent->_bf = 0;
		}
		else
		{
			return false;
		}
	}

	//查找节点
	Node* Find(const K& key)
	{
		Node* cur = _pRoot;
		while (cur)
		{
			if (cur->_data < key)
			{
				cur = cur->_pRight;
			}
			else if (cur->_data > key)
			{
				cur = cur->_pLeft;
			}
			else
			{
				return cur;
			}
		}

		return nullptr;
	}

private:
	Node* _pRoot;
};