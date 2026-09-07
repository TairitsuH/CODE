#pragma once
#include<utility>
#include "HashTable.h"
using namespace std;

namespace mzh
{
	template<class K, class V>
	class unordered_map
	{
	private:
		struct MapKeyOfT
		{
			//返回值加const限制的是调用者（不能改返回值）
			//括号后加const限制的是函数自己（不能改传入的值）
			//括号内加const限制的是别人（不能通过函数改自己的成员）
			const K& operator()(const pair<K, V>& kv)
			{
				return kv.first;
			}
		};

		hash_bucket::HashTable<K, pair<K, V>, MapKeyOfT> _ht;

	public:
		//插入
		bool insert(const pair<K, V>& kv)
		{
			return _ht.Insert(kv);
		}
	};
}