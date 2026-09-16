#include<iostream>
#include<memory>
#include<cstdio>
#include<cstring>
#include<assert.h>
using namespace std;

namespace mzh
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
            cout << "string(char* str)-构造" <<  endl;
            _str = new char[_capacity + 1];
            strcpy(_str, str);
        }

        void swap(string& s)
        {
            ::swap(_str, s._str);
            ::swap(_size, s._size);
            ::swap(_capacity, s._capacity);
        }

        //拷贝构造
        string(const string& s)
            :_str(nullptr)
        {
            cout << "string(const string& s) -- 拷贝构造" <<  endl;
            reserve(s._capacity);
            for (auto ch : s)
            {
                push_back(ch);
            }
        }

        // 移动构造
        string(string&& s)
        {
            cout << "string(string&& s) -- 移动构造" <<  endl;
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
        for(size_t i=0; i<s._size; i++)
        {
            out << s._str[i];
        }
        return out;
    }
}

//抛异常
// #include <iostream>
// #include <memory>
// #include <stdexcept>

// class Dog {
// public:
//     Dog()
//     { 
//         std::cout << "小狗出生\n";
//     }

//     ~Dog()
//     { 
//         std::cout << "小狗死亡\n";
//     }
// };

// void badDemo()
// {
//     Dog* dog = new Dog();
//     throw std::string("中途出事了！");
//     delete dog; //抛异常后跳过了释放
// }

// void call()
// {
//     try
//     {
//         badDemo();
//     }

//     catch (const std::string& e)
//     {
//         std::cout << "捕获: " << e<< endl;
//     }
// }

// int main()
// {
//     call(); //内存泄漏
//     return 0;
// }



//模拟实现简单智能指针
template<class T>
class SmartPtr
{
private:
    T* _ptr;

public:
    SmartPtr(T* ptr)
    :_ptr(ptr)
    {}

    ~SmartPtr()
    {
        cout << "delete[]" << _ptr << endl;
        delete[] _ptr;
    }

    T& operator*()
    {
        return *_ptr;
    }

    T* operator->()
    {
        return _ptr;
    }

    T& operator[](size_t i)
    {
        return _ptr[i];
    }
};

double Divide(int a, int b)
{
    try
    {
        if (b == 0)
        {
            string s = "Divided by zero condition!" ;
            throw s;
        }
        else
        {
            return (double)a / (double)b;
        }
    }
    catch (const char& errmsg) //不同类型
    {
        cout << "Divide" << ":" << errmsg << endl;
    }

    return 0;
}

void Func()
{
    SmartPtr<int> sp1 = new int[10];
    SmartPtr<int> sp2 = new int[10];

    for(int i=0; i<10; ++i)
    {
        sp1[i] = sp2[i] = i;
    }

    int a, b; cin >> a >> b;
    cout << Divide(a, b) << endl;
}

// int main()
// {
//     try
//     {
//         Func();
//     }
//     catch(const char& c)
//     {
//         cout << c << endl;
//     }
//     catch(...)
//     {
//         cout << "未知异常" << endl;
//     }

//     return 0;
// }


//智能指针的发展
struct Date
{
    int _year;
    int _month;
    int _day;

    Date(int y = 2000, int m = 1, int d = 1)
    :_year(y)
    ,_month(m)
    ,_day(d)
    {}

    ~Date()
    {
        cout << "~Date" << endl;
    }
};


// int main()
// {
//     //auto_ptr
//     auto_ptr<Date> ap1(new Date());
//     auto_ptr<Date> ap2(ap1);
//     // ap1->_year; //访问空指针失效（拷贝悬空）

//     //unique_ptr
//     unique_ptr<Date> up1(new Date);
//     // unique_ptr<Date> up2 = up1; //不支持拷贝
//     unique_ptr<Date> up3(move(up1)); //移动悬空
//     // cout << up1->_year << endl; //在cout才报异常，是因为编译器优化。若想保留此行，需加上volatile关键字
//     up3->_year;

//     //shared_ptr
//     shared_ptr<Date> sp1(new Date);
//     shared_ptr<Date> sp2(sp1);
//     shared_ptr<Date> sp3(new Date);
//     cout << sp3->_day << endl;
//     shared_ptr<Date> sp4(move(sp3)); //移动悬空
//     // cout << sp1->_year << endl; //移动悬空
//     cout << sp2->_month << endl;
//     cout << sp4->_year << endl;

//     return 0;
// }

//std::shared_ptr的使用示例
// int main()
// {
// 	//报错：std::shared_ptr不支持指针隐式类型转换（explicit关键字修饰）
// 	//std::shared_ptr<Date> sp1 = new Date(2000, 1, 1); 

// 	std::shared_ptr<Date> sp1(new Date(2026, 9, 15));
// 	std::shared_ptr<Date> sp2 = std::make_shared<Date>(2026, 9, 16); //make_shared让内存集中到一起
// 	auto sp3 = std::make_shared<Date>(2026, 9, 17); //自动推导
// 	std::shared_ptr<Date> sp4; //默认值构造

// 	return 0;
// }

//删除器
//unique_ptr支持在类类型列表传入仿函数（lambda/函数指针须另在构造函数参数列表传入）
//smart_ptr支持在构造函数参数列表传入仿函数/lambda/函数指针
//仿函数
// template<class T>
// class DeleteArray
// {
// public:
//     void operator()(T* ptr)
//     {
//         delete[] ptr;
//     }
// };

// //函数
// template<class T>
// void DeleteArrayFunc(T* ptr)
// {
//     delete[] ptr;
// }

// //unique_ptr和smart_ptr的对比
// int main()
// {
//     Date* d1 = new Date[10]; //如果把同一个指针同时给两个智能指针管理，就会析构死循环

//     //特化版本
//     unique_ptr<Date[]> up(new Date[1]);
//     shared_ptr<Date[]> sp(new Date[2]);

//     //仿函数
//     unique_ptr<Date, DeleteArray<Date>> up1(new Date[1]);
//     shared_ptr<Date> sp1(new Date[2], DeleteArray<Date>());

//     //lambda(没有类型名，只能用decltype获取类型)
//     auto del = [](Date* ptr){delete[] ptr;};
//     unique_ptr<Date, decltype(del)> up2(new Date[1], del);
//     shared_ptr<Date> sp2(new Date[2], del);

//     //函数指针
//     unique_ptr<Date, void(*)(Date*)> up3(new Date[1], DeleteArrayFunc<Date>);
//     shared_ptr<Date> sp3(new Date[2], DeleteArrayFunc<Date>);

//     //其他资源的删除器
//     auto Fclose = [](FILE* file){fclose(file); cout << "Fclose()" << endl;};
//     shared_ptr<FILE> sp4(fopen("Cpp11.cpp", "r"), Fclose);

//     return 0;
// }


//shared_ptr的缺陷：循环引用
// namespace mzh
// {
//     struct ListNode
//     {
//         int _data;
//         std::shared_ptr<ListNode> _next;
//         std::shared_ptr<ListNode> _prev;
        
//         ~ListNode()
//         {
//             cout << "~ListNode()" << endl;
//         }
        
//     };
// }


// int main()
// {
//     std::shared_ptr<mzh::ListNode> n1(new mzh::ListNode);
//     std::shared_ptr<mzh::ListNode> n2(new mzh::ListNode);

//     cout << n1.use_count() << endl;
//     cout << n2.use_count() << endl;

//     //循环引用导致内存泄漏
//     n1->_next = n2;
//     n2->_prev = n1;

//     cout << n1.use_count() << endl;
//     cout << n2.use_count() << endl;

//     return 0;
// }

//解决方法：weak_ptr
// int main()
// {
//     std::shared_ptr<mzh::string> sp1(new mzh::string);
//     std::shared_ptr<mzh::string> sp2(sp1);
//     std::weak_ptr<mzh::string> wp1(sp1);

//     //sp1和sp2都指向其他资源：通过控制块计数了解对象的存在状态
//     cout << sp1.use_count() << endl;
//     cout << wp1.expired() << endl;
//     cout << wp1.use_count() << endl << endl;

//     sp1 = make_shared<mzh::string>("11111");
//     cout << sp1.use_count() << endl;
//     cout << wp1.expired() << endl;
//     cout << wp1.use_count() << endl << endl;

//     sp2 = make_shared<mzh::string>("22222");
//     cout << sp2.use_count() << endl;
//     cout << wp1.expired() << endl; //返回true表示资源已被销毁
//     cout << wp1.use_count() << endl << endl;
//
//     //通过调用lock访问对象
//     std::weak_ptr<mzh::string> wp2 = sp1;
//     auto sp3 = wp2.lock();
//     cout << wp2.expired() << endl;
//     cout << wp2.use_count() << endl;

//     *sp3 += '#';
//     cout << *sp3 << endl; //1111#
//     cout << *sp1 << endl; //1111#

//     return 0;
// }