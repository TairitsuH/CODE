#pragma once
#include "HashTable.h"
using namespace std;

namespace mzh
{
	template<class K>
	class unordered_set
	{
	private:
		struct SetKeyOfT
		{
			//返回值加const限制的是调用者（不能改返回值）
			//括号后加const限制的是函数自己（不能改传入的值）
			//括号内加const限制的是别人（不能通过函数改自己的成员）
			const K& operator()(const K& key)
			{
				return key;
			}
		};

		hash_bucket::HashTable<K, K, SetKeyOfT> _ht;

	public:
		//插入
		bool insert(const K& key)
		{
			return _ht.Insert(key);
		}
	};
}