#include<iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;
    int a,b,c;
    while(T--)
    {
        cin >> a >> b >> c;

        int S = 2*(a*b + b*c + a*c);

        cout << S << endl;
    }

    return 0;
}