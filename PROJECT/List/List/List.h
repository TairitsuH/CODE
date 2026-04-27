#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

namespace tairitsu_h
{
	template<typename T>
	struct List_node
	{
		T _data;
		List_node<T>* _prev;
		List_node<T>* _next;

		//构造
		List_node(const T& data = T())
			:_data(data)
			,_prev(nullptr)
			,_next(nullptr)
		{}
	};

	template<typename T>
	struct List_iterator
	{
		typedef List_iterator<T> Self;
		typedef List_node<T> Node;

		//成员
		Node* _node;

		//构造
		List_iterator(Node* node)
			:_node(node)
		{
		}

		//解引用
		T& operator*()
		{
			return _node->_data;
		}

		//前置自增
		Self& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		//前置自减
		Self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		//后置自增
		Self operator++(int)
		{
			Self tmp(*this);
			++*this;
			return tmp;
		}

		//后置自减
		Self operator--(int)
		{
			Self tmp(*this);
			--*this;
			return tmp;
		}

		//等
		bool operator==(const Self& s) const
		{
			return _node == s._node;
		}

		//不等
		bool operator!=(const Self& s) const
		{
			return _node != s._node;
		}

		//解引用访问(编译器会递归调用，直到返回原始指针）
		T* operator->()
		{
			return &_node->_data;
		}
	};

	template<typename T>
	class List
	{
		//内部用，私有
		typedef List_node<T> Node;

	private:
		Node* _head;
		size_t _size;

	public:
		//迭代器
		typedef List_iterator<T> iterator;
		iterator begin()
		{
			//隐式类型转换
			return _head->_next;
		}
		iterator end()
		{
			//尾节点的下一个
			return _head;
		}

		//构造
		List()
		{
			_head = new Node;
			_head->_prev = _head;
			_head->_next = _head;
			_size = 0;
		}

		//尾插
		void push_back(const T& x)
		{
			Node* newnode = new Node(x);
			Node* tail = _head->_prev;

			newnode->_prev = tail;
			newnode->_next = _head;
			tail->_next = newnode;
			_head->_prev = newnode;

			++_size;
		}

		//大小
		size_t size() const
		{
			return _size;
		}

		//判空
		bool empty() const
		{
			return _size == 0;
		}

		//插入
		void insert(iterator pos, const T& x)
		{
			Node* cur = pos._node;

			Node* newnode = new Node(x);
			newnode->_prev = cur->_prev;
			newnode->_next = cur;
			cur->_prev->_next = newnode;
			cur->_prev = newnode;

			++_size;
		}

		//删除
		void erase(iterator pos)
		{
			//pos不能为虚拟头结点
			assert(pos != end());

			Node* prev = pos._node->_prev;
			Node* next = pos._node->_next;

			prev->_next = next;
			next->_prev = prev;
			delete pos._node; //记得销毁节点

			--_size;
		}

		//头删
		void pop_front()
		{
			erase(begin());
		}

		//尾删
		void pop_back()
		{
			erase(--end());
		}
	};
}