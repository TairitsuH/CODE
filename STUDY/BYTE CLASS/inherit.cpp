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
    Person& operator=(const Person& p)
    {
        cout << "Person& operator=(Person p)" << endl;
        if(this != &p)
        {
            _name = p._name;
        }
        
        return *this;
    }

    //析构
    ~Person()
    {
        cout << "~Person()" << endl;
    }
};

class Student: public Person
{
private:
    int _num;

public:
    Student(const char* name = "NULL", int num = 0)
        :Person(name)
        ,_num(num)
    {
        cout << "Student(const char* name, int num)" << endl;
    }

    //拷贝构造(C++中，派生类对象可以当作基类对象使用)
    Student(const Student& stu)
        :Person(stu)
        ,_num(stu._num)
    {
        // Person(stu);不能写在内部
        cout << "Student(const Student& stu)" << endl;
    }

    //赋值重载
    Student& operator=(const Student& stu)
    {
        cout << "Student& operator=(const Student& stu)" << endl;
         if(this != &stu)
         {
            Person::operator=(stu); //构成了隐藏，需要显式调用
            _num = stu._num;
         }

         return *this;
    }

    //析构
    ~Student()
    {
        cout << "~Student()" << endl;
    }

    void Print_Student()
    {
        cout << _name << " " << _num << endl;
    }
};

int main()
{
    Student s1("Tairitsu", 2025);
    Student s2("Hikari", 2026);
    Student s3;
    s1.Print_Student();
    s2.Print_Student();
    s3.Print_Student();
    s3 = s1;
    s3.Print_Student();

    return 0;
}