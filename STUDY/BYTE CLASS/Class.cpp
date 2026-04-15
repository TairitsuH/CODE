// class A
// {
// public:
//     void Print()
//     {
//         cout << "A::Print()" << endl;
//     }

// private:
//     int _a;
// };

// int main()
// {
//     A* p = nullptr;
//     p->Print();
//     return 0;
// }

#include<iostream>
using namespace std;

class Student
{
private:
    string _name;
    int _age;
    int* _scores;
    int _scoreCount;

public:
    Student(const string& name, int age, int s1, int s2, int s3)
    {
        _name = name;
        _age = age;
        _scores = (int*)malloc(sizeof(int)*3);
        _scores[0] = s1;
        _scores[1] = s2;
        _scores[2] = s3;
    }

    ~Student()
    {
        free(_scores);
        _scores = nullptr;
    }

    double GetAverage()
    {
        double sum = 0;
        for(int i=0; i<3; i++)
        {
            sum += _scores[i];
        }
        return sum / 3;
    }

    void Print()
    {
        cout << "姓名：" << _name << endl;
        cout << "年龄：" << _age << endl;
        cout << "平均分：" << GetAverage() << endl;
    }

    void CompareAge(const Student& other)
    {
        if(this->_age > other._age)
        {
            cout << _name << "的年龄大" << endl;
        }
        else if(this->_age == other._age)
        {
            cout << "你们的年龄一样大" << endl;
        }
        else
        {
            cout << other._name << "的年龄大" << endl;
        }
    }
};

int main()
{
    Student Stu1("Hikari", 18, 150, 100, 150);
    Student Stu2("Tairitsu", 19, 120, 130, 140);

    Stu1.Print();
    Stu2.Print();

    Stu1.CompareAge(Stu2);

    return 0;
}