#pragma once
#include<vector>
#include<string>
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
	size_t operator()(const K& key) const
	{
		return (size_t)key;
	}
};

//针对string的特化
template<>
struct HashFunc<string>
{
	size_t operator()(const string& key) const
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

//2.链地址法
namespace hash_bucket
{
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

	template<class K, class T, class KeyOfT, class Hash = HashFunc<K>>
	class HashTable
	{
	private:
		typedef HashNode<T> Node;
		vector<Node*> _tables;
		size_t _n;

	public:
		//构造函数
		HashTable()
			:_tables(__stl_next_prime(0))
			, _n(0)
		{
		}

		//拷贝构造(复用Insert，但是效率比手写深拷贝低)
		HashTable(const HashTable& hst)
			:_tables(__stl_next_prime(hst._tables.size() == 0 ? __stl_next_prime(0) : hst._tables.size())) //注意检验哈希表是否为空
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

		//插入
		bool Insert(const T& data)
		{
			KeyOfT kot;

			if (Find(kot(data))) return false; //不允许冗余

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

			return true;
		}

		//查找
		Node* Find(const T& data) const
		{
			if (_tables.empty()) return nullptr;

			KeyOfT kot;
			Hash hash;
			size_t hashi = hash(kot(data)) % _tables.size();
			Node* cur = _tables[hashi];
			while (cur)
			{
				if (kot(cur->_data) == kot(data))
				{
					return cur;
				}

				cur = cur->_next;
			}

			return nullptr;
		}

		//删除
		bool Erase(const T& data)
		{
			KeyOfT kot;
			Hash hash;
			size_t hashi = hash(kot(data)) % _tables.size();
			Node* cur = _tables[hashi];

			if (!cur) return false;

			Node* prev = nullptr;
			while (cur)
			{
				if (kot(cur->_data) == kot(data))
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
	};
}
