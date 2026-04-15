// #include<stdio.h>

// int main()
// {
//     printf("Hello, C++!");
//     return 0;
// }

// #include<iostream>
// using namespace std;

// int main()
// {
//     cout << "Hello, C++!" << endl;
//     return 0;
// }

// #include<iostream>
// using namespace std;

// //声明
// void Add(int a = 10, int b = 10);


// void Add(int a = 10, int b = 10)
// {
//     cout << a + b << endl;
// }

// int main()
// {
//     int x = 20;
//     int y = 50;
//     Add(x, y); //已传入初始值
//     Add(); //未传入初始值
//     return 0;
// }



// int Add(int a, int b)
// {
//     return a + b;
// }

// //参数类型不同
// double Add(double a, double b)
// {
//     return a + b;
// }

// //参数数量不同
// int Add(int a)
// {
//     int b = 10;
//     return a + b;
// }

// //参数位置可以交换
// int Add(char a, int b)
// {
//     return a + b;
// }

// int Add(int b, char a)
// {
//     return a + b;
// }

// //错误写法
// // double Add(int a, int b)
// // {
// //     return a + b;
// // }


int a;

//类型& 引用别名 = 引用对象
int& ra = a;

#include<iostream>
using namespace std;

void Swap(int& rx, int& ry)
{
    int tmp = rx;
    rx = ry;
    ry = tmp;
}

int main()
{
    int x = 20;
    int y = 10;
    Swap(x, y);
    cout << x << endl << y << endl;
    return 0;
}