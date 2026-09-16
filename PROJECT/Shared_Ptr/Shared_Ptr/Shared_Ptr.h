#pragma once
#include<iostream>
#include<functional>
using namespace std;

namespace mzh
{
	//简单shared_ptr实现，面试考察写到这种程度就够了
	template<class T>
	class shared_ptr
	{
	private:
		T* _ptr;
		int* _pcount;
		function<void(T*)> _del = [](T* ptr) {delete ptr; }; //删除器(delete为缺省值)

	public:
		//构造
		shared_ptr(T* ptr = nullptr)
			:_ptr(ptr)
			,_pcount(new int(1))
		{
			cout << "shared_ptr()" << endl;
		}

		//含删除器的构造
		template<class D>
		shared_ptr(T* ptr, D del) //ptr = nullptr不能写两次缺省值！
			:_ptr(ptr)
			,_del(del)
		{}

		//拷贝构造
		shared_ptr(const shared_ptr<T>& sp)
			:_ptr(sp._ptr)
			, _pcount(sp._pcount)
			,_del(sp._del)
		{
			++(*_pcount);
		}

		//析构
		~shared_ptr()
		{
			--(*_pcount);
			if (*_pcount == 0)
			{
				_del(_ptr);
				delete _pcount;
				_ptr = nullptr;
				_pcount = nullptr;
			}
			cout << "~shared_ptr()" << endl;
		}

		//赋值重载
		shared_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			//自赋值
			if (sp._ptr == _ptr) //更推荐，或者this != &sp
			{
				cout << "不能自赋值！" << endl;
				return *this;
			}
			--(*_pcount);

			//释放自己
			if ((*_pcount) == 0)
			{
				_del(_ptr);
				delete _pcount;
			}

			//重新赋值
			_ptr = sp._ptr;
			_pcount = sp._pcount;
			_del = sp._del;
			++(*_pcount);
			return *this;
		}


		//重载*
		T& operator*() const 
		{
			return *_ptr; //_ptr本身是指针
		}

		//重载->
		T* operator->() const
		{
			return _ptr;
		}
	};
}