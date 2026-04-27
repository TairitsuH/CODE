#include<iostream>
#include<cmath>
using namespace std;

string x,y;
int sub;

int main()
{
    cin >> x >> y;
    sub = x.size()-y.size();
    cout << abs(sub);
    return 0;
}