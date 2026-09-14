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


int main()
{
    //auto_ptr
    auto_ptr<Date> ap1(new Date());
    auto_ptr<Date> ap2(ap1);
    // ap1->_year; //访问空指针失效（拷贝悬空）

    //unique_ptr
    unique_ptr<Date> up1(new Date);
    // unique_ptr<Date> up2 = up1; //不支持拷贝
    unique_ptr<Date> up3(move(up1)); //移动悬空
    // cout << up1->_year << endl; //在cout才报异常，是因为编译器优化。若想保留此行，需加上volatile关键字
    up3->_year;

    //shared_ptr
    shared_ptr<Date> sp1(new Date);
    shared_ptr<Date> sp2(sp1);
    shared_ptr<Date> sp3(new Date);
    cout << sp3->_day << endl;
    shared_ptr<Date> sp4(move(sp3)); //移动悬空
    // cout << sp1->_year << endl; //移动悬空
    cout << sp2->_month << endl;
    cout << sp4->_year << endl;

    return 0;
}