#pragma once

#include<iostream>
#include<assert.h>
using namespace std;

namespace tairitsu_h
{
	template<class T>
	class Vector
	{
    public:
        typedef T* iterator;
		typedef const T* const_iterator;
        
	private:
		iterator _start = nullptr;
		iterator _finish = nullptr;
		iterator _end_of_storage = nullptr;
		
	public:
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		const_iterator begin() const
		{
			return _start;
		}
		const_iterator end() const
		{
			return _finish;
		}

		//构造（写了构造函数编译器就不会自动生成拷贝构造了）
		Vector()
		{}

		template<class Inputiterator>
		//构造（迭代器）
		Vector(Inputiterator first, Inputiterator last)
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		//构造（n个val）
		Vector(size_t n, const T& val = T())
		{
			reserve(n);

			for (size_t i = 0; i < n; i++)
			{
				push_back(val);
			}
		}

		//拷贝构造
		Vector(const Vector<T>& v)
		{
			reserve(v.size());
			for (const auto val : v) //拷贝
			{
				push_back(val);
			}
		}
		
		//析构
		~Vector()
		{
			cout << "析构" << endl;
			if (_start)
			{
				delete[] _start;
			}
			_start = _finish = _end_of_storage = nullptr;
		}

		//元素个数
		size_t size() const
		{
			return _finish - _start;
		}

		//容量
		size_t capacity() const
		{
			return _end_of_storage - _start;
		}

		//扩容
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				//提前保存size
				size_t old_size = size();
				T* tmp = new T[n];

				//不能这样写，会导致vector内部涉及资源开辟的元素仅仅浅拷贝
				//memcpy(tmp, _start, size() * sizeof(T));

				for (size_t i = 0; i < old_size; i++)
				{
					//深拷贝
					tmp[i] = _start[i];
				}
				delete[] _start;

				//更新数据
				_start = tmp;

				//不能这样写，否则_finish仍为空指针
				//_finish = _start + size();

				_finish = _start + old_size;
				_end_of_storage = _start + n;
			}
		}

		//尾插
		void push_back(const T& x)
		{
			//判断扩容
			if (_finish == _end_of_storage)
			{
				reserve(capacity() == 0 ? 4 : 2 * capacity());
			}

			//尾插
			*_finish = x; //深拷贝
			++_finish;
		}

		//判空
		bool empty()
		{
			return _start == _finish;
		}

		//尾删
		void pop_back()
		{
			assert(!empty());
			--_finish;
		}

		//插入
		void insert(iterator pos, const T& x)
		{
			assert(pos <= _finish);

			//判断扩容
			if (_finish == _end_of_storage)
			{
				//拷贝迭代器避免失效
				size_t gap = pos - _start;
				reserve(capacity() == 0 ? 4 : 2 * capacity());
				pos = _start + gap;
			}

			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}

			*pos = x;
			++_finish;
		}
		
		//删除并返回下一个位置
		iterator erase(iterator pos)
		{
			assert(pos < _finish);

			iterator end = pos + 1;
			while (end < _finish)
			{
				*(end - 1) = *end;
				++end;
			}

			--_finish;

			return pos;
		}

		//更新size
		void resize(size_t n, T val = T())
		{
			if (n < size())
			{
				_finish = _start + n;
			}
			else
			{
				reserve(n);
				while (n--)
				{
					*_finish = val;
					++_finish;
				}
			}
		}

		//赋值重载（现代写法：传值直接深拷贝）
		void Swap(Vector<T>& v)
		{
			swap(_start, v._start);
			swap(_finish, v._finish);
			swap(_end_of_storage, v._end_of_storage);
		}
		Vector<T>& operator=(Vector<T> v)
		{
			Swap(v);
			return *this;
		}

		//清空
		void clear()
		{
			_finish = _start;
		}
	};
}

