#pragma once
#include "HashTable.h"
using namespace std;

namespace mzh
{
	template<class K, class Hash = HashFunc<K>>
	class unordered_set
	{
	private:
		struct SetKeyOfT //返回key的仿函数
		{
			//operator() 返回 const K& ，是为了保证提取出的 key 不可被上层修改
			const K& operator()(const K& key)
			{
				return key;
			}
		};

		hash_bucket::HashTable<K, const K, SetKeyOfT, Hash> _ht;

	public:
		typedef typename hash_bucket::HashTable<K, const K, SetKeyOfT, Hash>::Iterator iterator;
		typedef typename hash_bucket::HashTable<K, const K, SetKeyOfT, Hash>::ConstIterator const_iterator;

		//插入
		pair<iterator, bool> insert(const K& key)
		{
			return _ht.Insert(key);
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

		//const迭代器begin
		const_iterator begin() const
		{
			return _ht.Begin();
		}

		//const迭代器end
		const_iterator end() const
		{
			return _ht.End();
		}

	};
}