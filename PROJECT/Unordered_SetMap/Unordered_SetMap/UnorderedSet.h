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
			//返回值加const限制的是调用者（不能改返回值）
			//括号后加const限制的是函数自己（不能改传入的值）
			//括号内加const限制的是别人（不能通过函数改自己的成员）
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

	};
}