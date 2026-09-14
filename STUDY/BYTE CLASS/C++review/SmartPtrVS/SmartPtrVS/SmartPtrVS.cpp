#include<iostream>
#include<memory>
using namespace std;

//模拟实现简单智能指针
// template<class T>
// class SmartPtr
// {
// private:
//     T* _ptr;

// public:
//     SmartPtr(T* ptr)
//     :_ptr(ptr)
//     {}

//     ~SmartPtr()
//     {
//         cout << "delete[]" << _ptr << endl;
//         delete[] _ptr;
//     }

//     T& operator*()
//     {
//         return *_ptr;
//     }

//     T* operator->()
//     {
//         return _ptr;
//     }

//     T& operator[](size_t i)
//     {
//         return _ptr[i];
//     }
// };

// double Divide(int a, int b)
// {
//     try
//     {
//         if (b == 0)
//         {
//             string s = "Divided by zero condition!" ;
//             throw s;
//         }
//         else
//         {
//             return (double)a / (double)b;
//         }
//     }
//     catch (const char& errmsg) //不同类型
//     {
//         cout << "Divide" << ":" << errmsg << endl;
//     }

//     return 0;
// }

// void Func()
// {
//     SmartPtr<int> sp1 = new int[10];
//     SmartPtr<int> sp2 = new int[10];

//     for(int i=0; i<10; ++i)
//     {
//         sp1[i] = sp2[i] = i;
//     }

//     int a, b; cin >> a >> b;
//     cout << Divide(a, b) << endl;
// }

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

    Date(int y, int m, int d)
        :_year(y)
        , _month(m)
        , _day(d)
    {
    }

    ~Date()
    {
        cout << "~Date" << endl;
    }
};


int main()
{
    //auto_ptr
    auto_ptr<Date> ap1(new Date);
    auto_ptr<Date> ap2(ap1);

    return 0;
}