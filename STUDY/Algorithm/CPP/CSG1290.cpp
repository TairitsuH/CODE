#include<iostream>
using namespace std;

int n;
char a, b, c;

void hano(int n, char a, char b, char c)
{
    if(n == 0) return;

    hano(n - 1, a, c, b);
    cout << a << " " << "to" << " " << c << endl;
    //把第n个盘子从a移动至c
    hano(n - 1, b, a, c);
}

int main()
{
    cin >> n;
    a = 'A', b = 'B', c = 'C';
    hano(n, a, b, c);
    return 0;
}