#include<iostream>
#include<memory>
#include<cstdio>
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


// int main()
// {
//     //auto_ptr
//     auto_ptr<Date> ap1(new Date());
//     auto_ptr<Date> ap2(ap1);
//     // ap1->_year; //访问空指针失效（拷贝悬空）
//
//     //unique_ptr
//     unique_ptr<Date> up1(new Date);
//     // unique_ptr<Date> up2 = up1; //不支持拷贝
//     unique_ptr<Date> up3(move(up1)); //移动悬空
//     // cout << up1->_year << endl; //在cout才报异常，是因为编译器优化。若想保留此行，需加上volatile关键字
//     up3->_year;
//
//     //shared_ptr
//     shared_ptr<Date> sp1(new Date);
//     shared_ptr<Date> sp2(sp1);
//     shared_ptr<Date> sp3(new Date);
//     cout << sp3->_day << endl;
//     shared_ptr<Date> sp4(move(sp3)); //移动悬空
//     // cout << sp1->_year << endl; //移动悬空
//     cout << sp2->_month << endl;
//     cout << sp4->_year << endl;
//
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
template<class T>
class DeleteArray
{
public:
    void operator()(T* ptr)
    {
        delete[] ptr;
    }
};

//函数
template<class T>
void DeleteArrayFunc(T* ptr)
{
    delete[] ptr;
}


//unique_ptr和smart_ptr的对比
int main()
{
    Date* d1 = new Date[10]; //如果把同一个指针同时给两个智能指针管理，就会析构死循环

    //特化版本
    unique_ptr<Date[]> up(new Date[1]);
    shared_ptr<Date[]> sp(new Date[2]);

    //仿函数
    unique_ptr<Date, DeleteArray<Date>> up1(new Date[1]);
    shared_ptr<Date> sp1(new Date[2], DeleteArray<Date>());

    //lambda(没有类型名，只能用decltype获取类型)
    auto del = [](Date* ptr){delete[] ptr;};
    unique_ptr<Date, decltype(del)> up2(new Date[1], del);
    shared_ptr<Date> sp2(new Date[2], del);

    //函数指针
    unique_ptr<Date, void(*)(Date*)> up3(new Date[1], DeleteArrayFunc<Date>);
    shared_ptr<Date> sp3(new Date[2], DeleteArrayFunc<Date>);

    //其他资源的删除器
    auto Fclose = [](FILE* file){fclose(file); cout << "Fclose()" << endl;};
    shared_ptr<FILE> sp4(fopen("Cpp11.cpp", "r"), Fclose);

    return 0;
}