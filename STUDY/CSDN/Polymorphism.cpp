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

int main()
{
    
    return 0;
}