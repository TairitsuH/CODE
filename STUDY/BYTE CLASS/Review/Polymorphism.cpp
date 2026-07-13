#include<iostream>
using namespace std;

class A
{};

class B: public A
{};

class Person
{
public:
    virtual A* BuyTicket() 
    {
        cout << "full-price" << endl;
        return nullptr;
    }
};

class Student: public Person
{
public:
    virtual B* BuyTicket() override //派生类重写，加override防止错误
    {
        cout << "half-price" << endl;
        return nullptr;
    }
};

void Func(Person* p) //用基类的指针/引用调用(可以指向基类也可以指向派生类)
{
    p->BuyTicket();
}

int main()
{
    Student s; //建立在栈上
    Person* s1 = new Student(); //建立在堆上
    Student* s2 = new Student();
    Person p;

    Func(&s);
    Func(&p);
    Func(s1);
    Func(s2); //自动向上转型

    return 0;
}
