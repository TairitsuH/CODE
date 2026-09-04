#pragma once
#include<utility>
#include "RBTree.h"
using namespace std;


namespace mzh
{
	template<class K>
	class set
	{
		//仿函数SetKeyOfT，用于取出set中的key或者map中的pair.first
		struct SetKeyOfT
		{
			const K& operator()(const K& key) const
			{
				return key;
			}
		};

	public:
		//红黑树迭代器中的类型名，加typename保证语法正确，设置const K以免key被修改
		typedef typename RBTree<K, const K, SetKeyOfT>::Iterator iterator;
		typedef typename RBTree<K, const K, SetKeyOfT>::ConstIterator const_iterator;

		//迭代器begin
		iterator begin()
		{
			return _t.Begin();
		}

		//迭代器end
		iterator end()
		{
			return _t.End();
		}

		//const迭代器begin
		const_iterator begin() const
		{
			return _t.Begin();
		}

		//const迭代器end
		const_iterator end() const
		{
			return _t.End();
		}

		//插入
		pair<iterator, bool> insert(const K& key)
		{
			//_t.Insert(key);
			return _t.Insert(key);
		}

		//查找
		iterator find(const K& key)
		{
			return _t.Find(key);
		}
		 
	private:
		RBTree<K, const K, SetKeyOfT> _t; //加const避免插入的返回值被修改
	};
}