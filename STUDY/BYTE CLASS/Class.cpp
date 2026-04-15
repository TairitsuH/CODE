#include<iostream>
using namespace std;

class A
{
public:
    void Print()
    {
        cout << "A::Print()" << endl;
    }

private:
    int _a;
};

int main()
{
    A* p = nullptr;
    p->Print();
    return 0;
}