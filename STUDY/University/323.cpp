#include<iostream>
using namespace std;

void my_sort(int &a, int &b, int &c)
{
    if(a < b)
    {
        swap(a, b);
    }
    if(b < c)
    {
        swap(b, c);
    }
    if(a < b)
    {
        swap(a, b);
    }
}

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int a, b, c; cin >> a >> b >> c;
        my_sort(a, b, c);
        cout << a << " " << b << " " << c << endl;
    }

    return 0;
}