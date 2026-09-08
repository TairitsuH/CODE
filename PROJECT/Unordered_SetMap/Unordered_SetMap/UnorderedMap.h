#pragma once
#include<utility>
#include "HashTable.h"
using namespace std;

namespace mzh
{
	template<class K, class V, class Hash = HashFunc<K>>
	class unordered_map
	{
	private:
		struct MapKeyOfT //返回key的仿函数
		{
			//返回值加const限制的是调用者（不能改返回值）
			//括号后加const限制的是函数自己（不能改传入的值）
			//括号内加const限制的是别人（不能通过函数改自己的成员）
			const K& operator()(const pair<K, V>& kv)
			{
				return kv.first;
			}
		};

		hash_bucket::HashTable<K, pair<const K, V>, MapKeyOfT> _ht;

	public:
		typedef typename hash_bucket::HashTable<K, pair<const K, V>, MapKeyOfT, Hash>::Iterator iterator;
		typedef typename hash_bucket::HashTable<K, pair<const K, V>, MapKeyOfT, Hash>::ConstIterator const_iterator;

		//插入
		pair<iterator, bool> insert(const pair<K, V>& kv)
		{
			return _ht.Insert(kv);
		}

		//查找
		iterator find(const K& key)
		{
			return _ht.Find(key);
		}

		//删除
		bool erase(const K& key)
		{
			return _ht.Erase(key);
		}

		//迭代器begin
		iterator begin()
		{
			return _ht.Begin();
		}

		//迭代器end
		iterator end()
		{
			return _ht.End();
		}

		//迭代器const_begin
		const_iterator const_begin() const
		{
			return _ht.Begin();
		}

		//迭代器const_end
		const_iterator const_end() const
		{
			return _ht.End();
		}

		//重载[]（自动插入）
		V& operator[](const K& key)
		{
			pair<iterator, bool> it = _ht.Insert(make_pair(key, V()));
			return it.first->second; //取的是pair中的iterator,再通过->重载取value
		}
	};
}