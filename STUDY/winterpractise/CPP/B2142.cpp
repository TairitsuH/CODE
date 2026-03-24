#include<iostream>
using namespace std;

int N;

int add(int N)
{
    if(N == 1) //控制递归起点，防止无限递归
        return 1;
    else
    return N + add(N-1);
}

int main()
{
    cin >> N;
    cout << add(N) << endl;
    return 0;
}