#include<iostream>
using namespace std;

class CPeople
{
public:
    string name;
    char gender;
    int age;

    CPeople(string name,char gender,int age)
    :name(name)
    ,gender(gender)
    ,age(age)
    {}

    void display1()
    {
        printf("People:\n"
        "Name: %s\n"
        "Sex: %c\n"
        "Age: %d\n\n", name.c_str(), gender, age);
    }

};

class CStudent: virtual public CPeople
{
public:
    string number;
    double score;

    CStudent(string name,char gender,int age,string number, double score)
    :CPeople(name, gender, age)
    ,number(number)
    ,score(score)
    {}


    void display2()
    {
        printf("Student:\n"
        "Name: %s\n"
        "Sex: %c\n"
        "Age: %d\n"
        "No.: %s\n"
        "Score: %.1lf\n\n", name.c_str(), gender, age, number.c_str(), score);
    }
};

class CTeacher: virtual public CPeople
{
public:
    string job;
    string sector;

    CTeacher(string name,char gender,int age,string number, string score)
    :CPeople(name, gender, age)
    ,job(number)
    ,sector(score)
    {}

    void display3()
    {
        printf("Teacher:\n"
        "Name: %s\n"
        "Sex: %c\n"
        "Age: %d\n"
        "Position: %s\n"
        "Department: %s\n\n", name.c_str(), gender, age, job.c_str(), sector.c_str());
    }

};

class CGradOnWork: public CStudent, public CTeacher
{
public:
    string research;
    string tutor;

    CGradOnWork(string name,char gender,int age,string number, double score, string job, string sector, string research, string tutor)
    :CPeople(name, gender, age)
    ,CStudent(name, gender, age, number, score)
    ,CTeacher( name, gender, age, job,  sector)
    ,research(research)
    ,tutor(tutor)
    {}

    void display4()
    {
        printf("GradOnWork:\n"
        "Name: %s\n"
        "Sex: %c\n"
        "Age: %d\n"
        "No.: %s\n"
        "Score: %.1lf\n"
        "Position: %s\n"
        "Department: %s\n"
        "Direction: %s\n"
        "Tutor: %s\n", name.c_str(), gender, age, number.c_str(), score, job.c_str(), sector.c_str(), research.c_str(), tutor.c_str());        
    }

};

int main()
{
    string n, num, j, sec, res, t;
    char g;
    int a;
    double sc;

    cin >> n >> g >> a >> num >> sc >> j >> sec >> res >> t;

    CPeople c1(n, g, a);
    CStudent c2(n, g, a, num, sc);
    CTeacher c3(n, g, a, j, sec);
    CGradOnWork c4(n, g, a, num, sc, j, sec, res, t);
    
    c1.display1();
    c2.display2();
    c3.display3();
    c4.display4();

    return 0;
}