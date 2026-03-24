#include<iostream>
using namespace std;

string x;
string y = "";

int main()
{
    cin >> x;
    for(int i=x.size()-1; i>=0; i--)
    {
        y.push_back(x[i]);
    }

    if(x == y)
    {
        cout << "yes";
    }
    else
    {
        cout << "no";
    }

    return 0;
}