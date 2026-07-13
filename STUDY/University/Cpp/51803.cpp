#include<iostream>
using namespace std;

char score_test(double s)
{
    if(s >= 85) return 'A';
    if(s >= 75 && s < 85) return 'B';
    if(s >= 65 && s < 75) return 'C';
    if(s >= 60 && s < 65) return 'D';
    return 'F';
}

class Person
{
public:
    string _name;
    int _age;

    Person(string name, int age)
        :_name(name)
        ,_age(age)
    {}

    void Display()
    {
        cout << _name << " " << _age << " ";
    }
};

class LStu: public Person
{
public:
    int normal;
    int test;

    LStu(string name, int age, int normal0, int test0)
        :Person(name, age)
        ,normal(normal0)
        ,test(test0)
    {}

    char all()
    {
        double score = normal*0.4 + test*0.6;
        return score_test(score);
    }
};

class NLStu: public Person
{
public:
    int test1;

    NLStu(string name, int age, int test00)
    :Person(name, age)
    ,test1(test00)
    {}

    char all()
    {
        return score_test(test1);
    }
};

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        char type;
        string name;
        int age;
        cin >> type >> name >> age;
        if(type == 'R')
        {
            int normal, test;
            cin >> normal >> test;
            LStu s(name, age, normal, test);

            s.Display();
            cout << s.all() << endl;
        }
        else
        {
            int test, all;
            cin >> test;
            NLStu s(name, age, test);

            s.Display();
            cout << s.all() << endl;
        }
    }
    return 0;
}