#pragma once

#include<iostream>

namespace tairitsu_h
{
	template<class T>
	class Vector
	{
	private:
		iterator _start = nullptr;
		iterator _finish = nullptr;
		iterator _end_of_storage = nullptr;
		
	public:
		typedef T* iterator;

		size_t size()
		{
			return _finish - _start;
		}

		size_t capacity()
		{
			return _end_of_storage - _start;
		}

		void reverse(size_t n)
		{
			if (n > capacity())
			{
				//提前保存size
				size_t old_size = size();
				T* tmp = new T[n];
				memcpy(tmp, _start, size() * sizeof(T));

				delete _start;
				_start = tmp;

				//不能这样写，否则_finish仍为空
				//_finish = _start + size();

				_finish = _start + old_size();
				_end_of_storage = _start + n;
			}
		}

		void push_back(const T& x)
		{
			if (_finish == _end_of_storage)
			{
				reserve(capacity() == 0 ? 4 : 2 * capacity());
			}

			*_finish = x;
			++_finish;
		}




	};
}

