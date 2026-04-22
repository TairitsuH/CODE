#include<iostream>
using namespace std;

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

class A
{
public:
    void Print();
};

int main()
{
    A a;
    cout << sizeof(a) << endl;
    return 0;
}

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