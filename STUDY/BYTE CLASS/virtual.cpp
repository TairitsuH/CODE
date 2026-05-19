#include<iostream>
using namespace std;

// class A
// {
// public:
//     virtual void func(int val = 1)
//     {
//         cout << "A->" << val << endl;
//     }

//     virtual void test()
//     {
//         func();
//     }
// };

// class B: public A
// {
// public:
//     virtual void func(int val = 0)
//     {
//         cout << "B->" << val << endl;
//     }

// //     virtual void test()
// //     {
// //         func();
// //     }
// };

// int main()
// {
//     B* ptr = new B;
//     ptr->test();
//     return 0;
// }

// class A

// {

// public:

//   A ()
//   :m_iVal(0)
//   {
//     test();
//   }

//   virtual void func() { cout<<m_iVal<<' ';}

//   void test(){func();}

// public:

//   int m_iVal;

// };



// class B : public A

// {

// public:

//   B(){test();}

//   virtual void func()

//   {

//     ++m_iVal;

//     std::cout<<m_iVal<<' ';

//   }

// };



// int main(int argc ,char* argv[])

// {

//   A*p = new B;

//   p->test();

//   return 0;

// }

// class A {
// public:
//     virtual void func() { cout << "A::func" << endl; }
//     void test() { func(); }
// };

// class B : public A {
// public:
//     virtual void func() { cout << "B::func" << endl; }
// };

// int main() {
//     B b;
//     b.test();
//     return 0;
// }

// class A {
// public:
//     virtual void func() { cout << "A::func" << endl; }
//     virtual ~A() {}
// };

// class B : public A {
// public:
//     virtual void func() override { cout << "B::func" << endl; }
//     ~B() {}
// };

// int main() {
//     A* p = new B;
//     p->func();
//     delete p;
//     return 0;
// }

// class A {
// public:
//     virtual void f1() {}
//     virtual void f2() {}
//     int a;
// };

// class B : public A {
// public:
//     virtual void f1() override {}
//     virtual void f3() {}
//     int b;
// };

// int main()
// {
//     cout << sizeof(A) << endl << sizeof(B) << endl;
//     return 0;
// }

class Base {
public:
    virtual void show(int x = 1) { cout << "Base:" << x << endl; }
};

class Derive : public Base {
public:
    virtual void show(int x = 2) { cout << "Derive:" << x << endl; }
};

int main() {
    Base* p = new Derive;
    p->show();
    return 0;
}