#pragma once
#include<utility>
#include "RBTree.h"
using namespace std;

namespace mzh
{
	template<class K, class V>
	class map
	{
		struct MapKeyOfT
		{
			const K& operator()(const pair<K, V>& kv)
			{
				return kv.first;
			}
		};

	public:
		typedef typename RBTree<K, pair<const K, V>, MapKeyOfT>::Iterator iterator;
		typedef typename RBTree<K, pair<const K, V>, MapKeyOfT>::ConstIterator const_iterator;

		iterator begin()
		{
			return _t.Begin();
		}

		iterator end()
		{
			return _t.End();
		}

		const_iterator begin() const
		{
			return _t.Begin();
		}

		const_iterator end() const
		{
			return _t.End();
		}

		pair<iterator, bool> insert(const pair<K, V>& kv)
		{
			return _t.Insert(kv);
		}

		iterator find(const K& key)
		{
			return _t.Find(key);
		}

		//出函数后，返回对象未被销毁时才可以返回引用
		//已知key存在，则可以通过插入的返回值反向找到value
		V& operator[](const K& key)
		{
			pair<iterator, bool> ret = _t.Insert({ key, V() }); //V()表示value的缺省值
			return (ret.first)->second; //返回值是iterator的value
		}

	private:
		//底层红黑树：键的类型，节点存储的数据类型，键萃取器（从pair中取出key）
		RBTree<K, pair<const K, V>, MapKeyOfT> _t;
	};
}

