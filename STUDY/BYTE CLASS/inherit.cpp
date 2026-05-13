#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

class Person
{
protected:
    string _name;

public:
    //用const char* 保留了C风格，不涉及临时对象的构造，现代风格常用const string&
    Person(const char* name = "peter")
        :_name(name)
    {
        cout << "Person()" << endl;
    }

    //拷贝构造
    Person(const Person& p)
        :_name(p._name)
    {}

    //赋值重载
    void Swap(Person& p)
    {
        swap(p._name, _name);
    }
    Person& operator=(Person p)
    {
        cout << "Person& operator=(Person p)" << endl;
        Swap(p);
        return *this;
    }

    //析构
    ~Person()
    {
        cout << "~Person()" << endl;
    }
};

int main()
{

    return 0;
}