#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    string X;
    cin >> X;
    reverse(X.begin(), X.end());
    cout << X;
    return 0;
}