#include<iostream>
using namespace std;

int a1,b1,a2,b2;
int sum1, sum2;


int main()
{
    cin >> a1 >> b1 >> a2 >> b2;
    for(int i=a1; i<=b1; i++) sum1 += i;
    for(int i=a2; i<=b2; i++) sum2 += i;

    cout << sum1 << endl << sum2;
    return 0;
}