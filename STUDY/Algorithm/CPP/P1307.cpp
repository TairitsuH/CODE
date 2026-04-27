#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int N;
    cin >> N;

    if(N < 0) cout << "-";

    N = abs(N);
    int s = 0, w = N;
    while(w)
    {
        s = s*10 +w%10;
        w /= 10;
    }
    cout << s;
    return 0;
}