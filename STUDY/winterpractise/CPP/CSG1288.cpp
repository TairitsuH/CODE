#include<iostream>
using namespace std;

int a,b;

void Swap(int& a, int& b)
{
    int mid = a;
    a = b;
    b = mid;
}

int main()
{
    cin >> a >> b;
    Swap(a, b);

    cout << a << " " << b << endl; 
    return 0;
}