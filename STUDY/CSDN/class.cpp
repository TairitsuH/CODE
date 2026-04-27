// #include<iostream>
// using namespace std;

// class Stack
// {
// private:

//     int* arr;
//     int _size;
//     int _capacity;

// public:

//     void Print();
//     void Destroy();
//     void Push(int x);
// };

// int main()
// {
//     return 0;
// }

// class A
// {
// public:
//     void Print();
// };

// int main()
// {
//     A a;
//     cout << sizeof(a) << endl;
//     return 0;
// }

// void A::Print()
// {
//     cout << _size << endl;
//     cout << _capacity << endl;
// }

// void A::Print(A* const this)
// {
//     cout << this->_size << end;
//     cout << this->_capacity << endl;
// }

#include <iostream>
using namespace std;

class A {
public:
    A(int x, int y) 
        : _b(y)           // ①
        , _c(_a)          // ②
    {
        _a = x;           // ③
        _b = x + y;       // ④
    }

    void Print() const {
        cout << "_a = " << _a << ", _b = " << _b << ", _c = " << _c << endl;
    }

private:
    int _a = 10;          // 声明缺省值
    int _b = 20;          // 声明缺省值
    int _c = 30;          // 声明缺省值
};

int main() {
    A obj(5, 7);
    obj.Print();
    return 0;
}