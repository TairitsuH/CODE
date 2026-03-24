#include<iostream>
using namespace std;

int n;
string min1;

int main()
{
    cin >> n;
    n--;
    cin >> min1;
    while(n--)
    {
        string a;
        cin >> a;
        min1 = (min1 < a ? min1 : a);
    }
    cout << min1;
    return 0;
}