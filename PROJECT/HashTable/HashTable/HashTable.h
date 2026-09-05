#pragma once
#include<vector>
using namespace std;

//状态栏
enum State
{
	EXIST,
	EMPTY,
	DELETE
};

//哈希表中的数据
template<class K, class V>
struct HashData
{
	pair<K, V> _kv;
	State _state = EMPTY;
};

//哈希表
template<class K, class V>
class HashTable
{
private:
	vector<HashData<K, V>> _tables;
	size_t _n = 0;

public:
	HashTable()
		:_tables(11)
		,_n(0)
	{ }

	bool Insert(pair<K, V>& kv)
	{
		//key存在时插入失败
		if (Find(kv.first))
		{
			return false;
		}

		//负载因子 >= 0.7时扩容
		if (_n * 10 / _tables.size() >= 7) //注意不能是整数相除
		{
			//1. 扩容
			HashTable<K, V> newht;
			newht._tables.resize(_tables.size() * 2);

			//2. 旧表数据映射到新表
			for (auto& e : _tables)
			{
				if (e._state == EXIST)
				{
					//再次走一遍插入（巧妙复用，现代写法）
					newht.Insert(e._kv);
				}
			}

			//3. 旧表指针指向新表
			_tables.swap(newht._tables); //效率高（交换指针）
		}

		size_t hash0 = kv.first % _tables.size(); //注意不能对capacity取模，可能导致越界访问
		size_t hashi = hash0;
		size_t i = 1;
		while (_tables[hashi]._state == EXIST)
		{
			//线性探测
			hashi = hash0 + i;
			hashi %= _tables.size(); //防止越界，回绕
			i++;
		}

		_tables[hashi]._kv = kv;
		_tables[hashi]._state = EXIST;
		_n++;

		return true;
	}

	//查找
	HashData<K, V>* Find(const K& key)
	{
		//找key（hashi）
		size_t hash0 = key % _tables.size(); //注意不能对capacity取模，可能导致越界访问
		size_t hashi = hash0;
		size_t i = 1;
		while (_tables[hashi]._state != EMPTY)
		{
			if (_tables[hashi]._state == EXIST && _tables[hashi]._kv.first == key) //增加对exist的检测
			{
				return &_tables[hashi]; //返回指针的地址
			}

			//线性探测
			hashi = hash0 + i;
			hashi %= _tables.size(); //防止越界，回绕
			i++;
		}

		return nullptr;
	}

	//删除
	bool Erase(const K& key)
	{
		HashData <K, V>* ret = Find(key);
		if (!ret)
		{
			return false;
		}
		else
		{
			ret->_state = DELETE; //直接改状态即可
			return true;
		}
	}

};
