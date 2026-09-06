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

//key转成整型
template<class K>
struct HashFunc
{
	size_t operator()(const K& key)
	{
		return (size_t)key;
	}
};

//（全特化）针对string的版本
template<>
struct HashFunc<string>
{
	size_t operator()(const string& key)
	{
		size_t hash = 0;
		for (auto e : key) //BKDR哈希
		{
			hash *= 131;
			hash += e;
		}

		return hash;
	}
};

//哈希扩容（接近2倍的素数）
inline unsigned long __stl_next_prime(unsigned long n)
{
	// Note: assumes long is at least 32 bits.
	static const int __stl_num_primes = 28; //数组大小
	static const unsigned long __stl_prime_list[__stl_num_primes] =
	{
		53, 97, 193, 389, 769,
		1543, 3079, 6151, 12289, 24593,
		49157, 98317, 196613, 393241, 786433,
		1572869, 3145739, 6291469, 12582917, 25165843,
		50331653, 100663319, 201326611, 402653189, 805306457,
		1610612741, 3221225473, 4294967291
	};

	//查找区间（左闭右开）
	const unsigned long* first = __stl_prime_list; //指针
	const unsigned long* last = __stl_prime_list + __stl_num_primes; //指针
	const unsigned long* pos = lower_bound(first, last, n); //区间内查找第一个>=n的数
	return pos == last ? *(last - 1) : *pos; //注意返回时需要解引用
}

//1.开放定址法
namespace open_address
{
	//哈希表中的数据
	template<class K, class V>
	struct HashData
	{
		pair<K, V> _kv;
		State _state = EMPTY;
	};

	//哈希表
	template<class K, class V, class Hash = HashFunc<K>>
	class HashTable
	{
	private:
		vector<HashData<K, V>> _tables;
		size_t _n = 0;

	public:
		//构造函数
		HashTable()
		{
			_tables.resize(__stl_next_prime(0));
			_n = 0;
		}

		bool Insert(const pair<K, V>& kv)
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
				HashTable<K, V, Hash> newht;
				newht._tables.resize(__stl_next_prime(_tables.size() + 1)); //注意一定要加1，否则会导致死循环

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

			Hash hash; //仿函数实例化(或者用HashFunc<K>()(key))
			size_t hash0 = hash(kv.first) % _tables.size(); //注意不能对capacity取模，可能导致越界访问
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
			Hash hash;
			size_t hash0 = hash(key) % _tables.size(); //注意不能对capacity取模，可能导致越界访问
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
}


namespace hash_bucket
{
	template<class K, class V>
	struct HashNode
	{
		pair<K, V> _kv;
		HashNode<K, V>* _next;

		HashNode(const pair<K, V>& kv)
			:_kv(kv)
			,_next(nullptr)
		{ }
	};

	template<class K, class V, class Hash = HashFunc<K>>
	class HashTable
	{
	private:
		typedef HashNode<K, V> Node;
		vector<Node*> _tables;
		size_t _n;

	public:
		HashTable()//__stl_next_prime(0)
			:_tables(11)
			,_n(0)
		{}

		//vector不会把桶释放，需要单独实现析构函数
		

		//插入
		bool Insert(const pair<K, V>& kv)
		{
			Hash hash;
			size_t hashi = kv.first % _tables.size();

			//扩容
			if (_n * 10 / _tables.size() == 7)
			{
				//__stl_next_prime(_tables.size() + 1), nullptr
				vector<Node*> newtables(_tables.size() * 2, nullptr);

				for (size_t i = 0; i < _tables.size(); i++)
				{
					Node* cur = _tables[i];
					while (cur)
					{
						Node* next = cur->_next;
						size_t hashi = hash(cur->_kv.first) % newtables.size();
						cur->_next = newtables[hashi];
						newtables[hashi] = cur;

						cur = next;
					}

					_tables[i] = nullptr;
				}

				_tables.swap(newtables);
			}

			//头插
			Node* newnode = new Node(kv);
			newnode->_next = _tables[hashi];
			_tables[hashi] = newnode;
			++_n;

			return true;
		}
	};
}
