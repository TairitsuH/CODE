#include<iostream>
using namespace std;

namespace mzh
{
    int a = 100;
    int b = 200;
    char c = 'a';

    int Add(int left, int right)
    {
        return left + right;
    }

    struct Student
    {
        std::string name;
        int age;
    };

    namespace jiu
    {
        int n = 1;
    }

    namespace yun
    {
        int m = 10;
    }
}

int main()
{
    cout << "a = " << mzh::a << endl;
    cout << "b = " << mzh::b << endl;
    cout << "n = " << mzh::jiu::n << endl;
    cout << "m = " << mzh::yun::m << endl;

    cout << "a + b = " << mzh::Add(mzh::a, mzh::b) << endl;
}