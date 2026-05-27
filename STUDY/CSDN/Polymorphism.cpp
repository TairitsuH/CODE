#include<iostream>
using namespace std;

class Person
{
public:
    virtual void BuyTicket()
    {
        cout << "买票全价" << endl;
    }
};

class Student: public Person
{
public:
    void BuyTicket()
    {
        cout << "买票打折" << endl;
    }
};

void Func(Person* ptr)
{
    ptr->BuyTicket();
}

int main()
{
    Student* stu = new Student;
    Person* ps1 = stu;

    Func(ps1);

    return 0;
}