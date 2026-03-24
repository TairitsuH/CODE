#include<iostream>
using namespace std;

string x,y;

int main()
{
    cin >> x >> y;
    size_t t = x.find(y);
    if(t != string::npos) cout<< t;
    else cout << -1;
    return 0;
}