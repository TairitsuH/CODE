#pragma once
#include<vector>
#include<iostream>
using namespace std;

class UnionFindSet
{
private:
	vector<int> _ufs;

public:
	UnionFindSet(size_t size)
		:_ufs(size, -1)
	{}

	//查找元素的根
	int FindRoot(int x)
	{
		int root = x;
		while (_ufs[root] >= 0)
		{
			root = _ufs[root];
		}

		//优化：将该路径上的节点优化为与根直接相连，降低树高度
		while (_ufs[x] > 0)
		{
			int parent = _ufs[x];
			_ufs[x] = root;
			x = parent;
		}

		return root;
	}

	//合并两个元素所在的集合/建立关系
	bool Union(int x1, int x2)
	{
		int root1 = FindRoot(x1);
		int root2 = FindRoot(x2);

		//两个元素属于同一个集合
		if (root1 == root2) return false;

		//优化：数据量小的向数据量大的合并
		if (abs(_ufs[root1]) < abs(_ufs[root2]))
		{
			swap(root1, root2); //if-else的另一种写法
		}

		_ufs[root1] += _ufs[root2];
		_ufs[root2] = root1;

		return true;
	}
	

	//集合个数
	size_t Count() const
	{
		size_t ret = 0;
		for (size_t i = 0; i < _ufs.size(); ++i)
		{
			if (_ufs[i] < 0) ++ret;
		}

		return ret;
	}

	//打印（测试用）
	void Print() const
	{
		for (int i = 0; i < _ufs.size(); ++i)
		{
			cout << i << ":" << _ufs[i] << endl;
		}
	}
};









