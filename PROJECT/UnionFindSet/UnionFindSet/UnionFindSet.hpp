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
		int index = x;
		while (_ufs[index] >= 0)
		{
			index = _ufs[index];
		}

		return index;
	}

	//合并两个元素所在的集合/建立关系
	bool Union(int x1, int x2)
	{
		int root1 = FindRoot(x1);
		int root2 = FindRoot(x2);

		//两个元素属于同一个集合
		if (root1 == root2) return false;

		_ufs[root1] += _ufs[root2];
		_ufs[root2] = root1;

		return true;
	}
	

	//集合个数
	int Count() const
	{
		int ret = 0;
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









