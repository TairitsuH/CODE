#include<iostream>
#include<string>
using namespace std;

class Student
{
private:
    string name;
    string id;
    string gender;
    string college;
    string phone;

public:
    Student()
    {
        name = "";
        id = "";
        college = "";
        phone = "";
    }

    void input()
    {
        cin >> name >> id >> gender >> college >> phone;
    }
    void printname()
    {
        cout << name << endl;
    }

    string getname()
    {
        return name;
    }

};

    

int main()
{
    int n;
    cin >> n;

    Student students[100];
    for(int i=0; i<n; i++)
    {
        students[i].input();
    }

    for(int i=0; i<n; i++)
    {
        students[i].printname();
    }

    return 0;
}