#include<iostream>
using namespace std;

class A
{
public:
    virtual void func(int val = 1)
    {
        cout << "A->" << val << endl;
    }

    virtual void test()
    {
        func();
    }
};

class B: public A
{
public:
    virtual void func(int val = 0)
    {
        cout << "B->" << val << endl;
    }

//     virtual void test()
//     {
//         func();
//     }
};

int main()
{
    B* ptr = new B;
    ptr->test();
    return 0;
}