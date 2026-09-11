#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<utility>
#include<string>
#include<assert.h>
#include<utility>
using namespace std;

namespace bit
{
	template<class T>
	struct ListNode
	{
		ListNode<T>* _next;
		ListNode<T>* _prev;

		T _data;

		//左/右值构造
		ListNode(T&& data)
			:_next(nullptr)
			, _prev(nullptr)
			, _data(move(data))
		{
		}

		//参数包构造（跳过中间临时对象，参数下传到构造函数）
		template <class... Args>
		ListNode(Args&&... args)
			:_next(nullptr)
			, _prev(nullptr)
			, _data(std::forward<Args>(args)...)
		{
		}
	};

	template<class T, class Ref, class Ptr>
	struct ListIterator
	{
		typedef ListNode<T> Node;
		typedef ListIterator<T, Ref, Ptr> Self;
		Node* _node;

		ListIterator(Node* node)
			:_node(node)
		{
		}

		// ++it;
		Self& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		Self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		Ref operator*()
		{
			return _node->_data;
		}

		bool operator!=(const Self& it)
		{
			return _node != it._node;
		}
	};

	template<class T>
	class list
	{
		typedef ListNode<T> Node;
	public:
		typedef ListIterator<T, T&, T*> iterator;
		typedef ListIterator<T, const T&, const T*> const_iterator;

		iterator begin()
		{
			return iterator(_head->_next);
		}

		iterator end()
		{
			return iterator(_head);
		}

		void empty_init()
		{
			_head = new Node();
			_head->_next = _head;
			_head->_prev = _head;
		}

		list()
		{
			empty_init();
		}

		void push_back(const T& x)
		{
			insert(end(), x);
		}

		void push_back(T&& x)
		{
			insert(end(), move(x));
		}

		iterator insert(iterator pos, const T& x) //const左值引用insert
		{
			Node* cur = pos._node;
			Node* newnode = new Node(x);
			Node* prev = cur->_prev;

			// prev newnode cur
			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;

			return iterator(newnode);
		}

		//iterator insert(iterator pos, T&& x) //右值引用insert
		//{
		//	Node* cur = pos._node;
		//	Node* newnode = new Node(move(x)); //x的属性是左值，因此要重新move转为右值
		//	Node* prev = cur->_prev;

		//	// prev newnode cur
		//	prev->_next = newnode;
		//	newnode->_prev = prev;
		//	newnode->_next = cur;
		//	cur->_prev = newnode;

		//	return iterator(newnode);
		//}

		template <class... Args>
		void emplace_back(Args&&... args)
		{
			insert(end(), std::forward<Args>(args)...);
		}

		// 原理：本质编译器根据可变参数模板⽣成对应参数的函数
		/*void emplace_back(string& s)
		{
			insert(end(), std::forward<string>(s));
		}

		void emplace_back(string&& s)
		{
			insert(end(), std::forward<string>(s));
		}

		void emplace_back(const char* s)
		{
			insert(end(), std::forward<const char*>(s));
		}
		*/

		template <class... Args>
		iterator insert(iterator pos, Args&&... args) //参数包insert
		{
			Node* cur = pos._node;
			Node* newnode = new Node(std::forward<Args>(args)...);
			Node* prev = cur->_prev;

			// prev newnode cur
			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;

			return iterator(newnode);
		}
	private:
		Node* _head;
	};
}


namespace bit
{
	class string
	{
	public:
		typedef char* iterator;
		typedef const char* const_iterator;
		friend ostream& operator<<(ostream& out, const string& s);


		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}

		const_iterator begin() const
		{
			return _str;
		}
		const_iterator end() const
		{
			return _str + _size;
		}

		string(const char* str = "")
			:_size(strlen(str))
			, _capacity(_size)
		{
			cout << "string(char* str)-构造" << endl;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		void swap(string& s)
		{
			::swap(_str, s._str);
			::swap(_size, s._size);
			::swap(_capacity, s._capacity);
		}

		string(const string& s)
			:_str(nullptr)
		{
			cout << "string(const string& s) -- 拷贝构造" << endl;
			reserve(s._capacity);
			for (auto ch : s)
			{
				push_back(ch);
			}
		}

		// 移动构造
		string(string&& s)
		{
			cout << "string(string&& s) -- 移动构造" << endl;
			swap(s);
		}

		//拷贝赋值
		string& operator=(const string& s)
		{
			cout << "string& operator=(const string& s) -- 拷贝赋值" << endl;
			if (this != &s)
			{
				_str[0] = '\0';
				_size = 0;
				reserve(s._capacity);
				for (auto ch : s)
				{
					push_back(ch);
				}
			}
			return *this;
		}

		// 移动赋值
		string& operator=(string&& s)
		{
			cout << "string& operator=(string&& s) -- 移动赋值" << endl;
			swap(s);
			return *this;
		}

		~string()
		{
			// cout << "~string() -- 析构" << endl;
			delete[] _str;
			_str = nullptr;
		}

		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}

		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				if (_str)
				{
					strcpy(tmp, _str);
					delete[] _str;
				}
				_str = tmp;
				_capacity = n;
			}
		}

		void push_back(char ch)
		{
			if (_size >= _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
				reserve(newcapacity);
			}
			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}

		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}

		const char* c_str() const
		{
			return _str;
		}

		size_t size() const
		{
			return _size;
		}

	private:
		char* _str = nullptr;
		size_t _size = 0;
		size_t _capacity = 0;
	};

	ostream& operator<<(ostream& out, const string& s)
	{
		for (size_t i = 0; i < s._size; i++)
		{
			out << s._str[i];
		}
		return out;
	}

}

