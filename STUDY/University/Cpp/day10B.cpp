#include<iostream>
#include<string>
using namespace std;

int main()
{
    string X;
    int a;
    cin >> X >> a;
    a %= 26;

    int sz = X.size();

    for(int i=0; i<sz; i++)
    {
        if(X[i] >= 'a' && X[i] <= 'z')
        {
            X[i] = 'a' + (X[i] - 'a' + a + 26) % 26;
        }
        else if(X[i] >= 'A' && X[i] <='Z')
        {
            X[i] = 'A' + (X[i] - 'A' + a + 26) % 26;
        }
    }

    cout << X;

    return 0;
}