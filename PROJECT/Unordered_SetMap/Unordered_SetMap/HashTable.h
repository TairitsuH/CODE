#pragma once
#include<vector>
#include<string>
using namespace std;

//key转成整型
template<class K>
struct HashFunc
{
	size_t operator()(const K& key)
	{
		return (size_t)key;
	}
};

//针对string的特化
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

//链地址法
namespace hash_bucket
{
	//前置声明
	template<class K, class T, class KeyOfT, class Hash>
	class HashTable;

	//节点
	template<class T>
	struct HashNode
	{
		T _data;
		HashNode<T>* _next;

		HashNode(const T& data)
			:_data(data)
			, _next(nullptr)
		{
		}
	};

	//迭代器
	template<class K, class T, class Ref, class Ptr, class KeyOfT, class Hash>
	struct HTIterator
	{
		typedef HashNode<T> Node;
		typedef HashTable<K, T, KeyOfT, Hash> HT;
		typedef HTIterator<K, T, Ref, Ptr, KeyOfT, Hash> Self;

		//成员(节点的指针和哈希表指针)
		Node* _node;
		const HT* _ht; //可以直接传_ht内部的_tables指针，避开相互依赖

		//构造函数
		HTIterator(Node* node, const HT* ht)
			:_node(node)
			,_ht(ht)
		{}

		//重载*
		Ref operator*()
		{
			return _node->_data;
		}

		//重载->
		Ptr operator->()
		{
			return &_node->_data;
		}

		//重载!=
		bool operator!=(const Self& s) const
		{
			return _node != s._node;
		}

		//重载++
		Self& operator++()
		{
			if (_node == nullptr) return *this;

			//当前桶还有数据
			if (_node->_next)
			{
				_node = _node->_next;
			}
			else //当前桶走完，找下一个非空桶
			{
				KeyOfT kot;
				Hash hash;
				//顺序：取key->求哈希值->取模
				//私有成员访问需要设置为友元
				size_t hashi = hash(kot(_node->_data)) % _ht->_tables.size();
				++hashi; //跳到下一个桶
				while (hashi < _ht->_tables.size())
				{
					_node = _ht->_tables[hashi];

					if (_node)
					{
						break;
					}
					else
					{
						++hashi;
					}
				}

				//走到end()
				if (hashi == _ht->_tables.size())
				{
					_node = nullptr;
				}
			}

			return *this;
		}
	};

	//哈希表
	template<class K, class T, class KeyOfT, class Hash>
	class HashTable
	{
	private:
		typedef HashNode<T> Node; //内部使用，私有成员
		vector<Node*> _tables;
		size_t _n;

	public:
		//类模板友元
		template<class K, class T, class Ref, class Ptr, class KeyOfT, class Hash>
		friend struct HTIterator;

		typedef HTIterator<K, T, T&, T*, KeyOfT, Hash> Iterator;
		typedef HTIterator<K, const T, const T&, const T*, KeyOfT, Hash> ConstIterator;


		//构造函数
		HashTable()
			:_tables(__stl_next_prime(0))
			, _n(0)
		{}

		//拷贝构造(复用Insert，但是效率比手写深拷贝低)
		HashTable(const HashTable& hst)
			:_tables(hst._tables.size())
			, _n(0)
		{
			for (size_t i = 0; i < hst._tables.size(); i++)
			{
				Node* cur = hst._tables[i];
				while (cur)
				{
					this->Insert(cur->_data);
					cur = cur->_next;
				}
			}
		}

		void SwapHash(HashTable& hst) //传引用
		{
			_tables.swap(hst._tables);
			swap(_n, hst._n);
		}

		//赋值重载(SwapHash现代写法)
		HashTable& operator=(HashTable hst)
		{
			SwapHash(hst);
			return *this;
		}

		//vector不会把桶释放，需要单独实现析构函数
		~HashTable()
		{
			for (size_t i = 0; i < _tables.size(); i++)
			{
				Node* cur = _tables[i];
				while (cur)
				{
					Node* del = cur;
					cur = cur->_next;
					delete del;
				}

				_tables[i] = nullptr;
			}
		}

		//插入（返回值为pair）
		pair<Iterator, bool> Insert(const T& data)
		{
			KeyOfT kot;
			Iterator it = Find(kot(data));
			if (it != End()) return make_pair(it, false); //不允许冗余

			Hash hash;

			//扩容
			if (_n == _tables.size())
			{
				vector<Node*> newtables(__stl_next_prime((unsigned long)_tables.size() + 1), nullptr);

				for (size_t i = 0; i < _tables.size(); i++)
				{
					Node* cur = _tables[i];
					while (cur)
					{
						Node* next = cur->_next;
						size_t hashi = hash(kot(cur->_data)) % newtables.size();
						cur->_next = newtables[hashi];
						newtables[hashi] = cur;

						cur = next;
					}

					_tables[i] = nullptr;
				}

				_tables.swap(newtables);
			}

			//头插
			size_t hashi = hash(kot(data)) % _tables.size();
			Node* newnode = new Node(data);
			newnode->_next = _tables[hashi];
			_tables[hashi] = newnode;
			++_n;

			return make_pair(Iterator(newnode, this), true);
		}

		//查找（返回值为Iterator）
		Iterator Find(const K& key)
		{
			if (_tables.empty()) return End();

			KeyOfT kot;
			Hash hash;
			size_t hashi = hash(key) % _tables.size();
			Node* cur = _tables[hashi];
			while (cur)
			{
				if (kot(cur->_data) == key)
				{
					return Iterator(cur, this);
				}

				cur = cur->_next;
			}

			return End();
		}

		//删除
		bool Erase(const K& key)
		{
			KeyOfT kot;
			Hash hash;
			size_t hashi = hash(key) % _tables.size();
			Node* cur = _tables[hashi];

			if (!cur) return false;

			Node* prev = nullptr;
			while (cur)
			{
				if (kot(cur->_data) == key)
				{
					//1.删除头节点
					if (prev == nullptr)
					{
						_tables[hashi] = cur->_next;
					}
					else
					{
						prev->_next = cur->_next;
					}

					--_n;
					delete cur;
					return true;
				}
				else
				{
					prev = cur;
					cur = cur->_next;
				}
			}

			return false;
		}

		//迭代器Begin
		Iterator Begin()
		{
			if (_n == 0) return End();

			for (size_t i = 0; i < _tables.size(); i++)
			{
				Node* cur = _tables[i];
				if (cur)
				{
					return Iterator(cur, this);
				}
			}
			return End();
		}

		ConstIterator Begin() const
		{
			if (_n == 0) return End();

			for (size_t i = 0; i < _tables.size(); i++)
			{
				Node* cur = _tables[i];
				if (cur)
				{
					return ConstIterator(cur, this);
				}
			}
			return End();
		}

		//迭代器End
		Iterator End()
		{
			return Iterator(nullptr, this);
		}

		ConstIterator End() const
		{
			return ConstIterator(nullptr, this); //构造函数内部的this指针需要const修饰
		}
	};


}
