#include<iostream>
using namespace std;

int n;
int ret;
int hanoi(int n, char a, char b, char c)
{
    if(n == 1) return ret;
    hanoi(n-1, a, c, b);
    ret++;
    hanoi(n-1, b, a, c);
}

int main()
{
    cin >> n;
    char a, b, c;
    a = 'A', b = 'B', c = 'C';
    cout << hanoi(n, a, b, c) << endl;
    
    return 0;
}