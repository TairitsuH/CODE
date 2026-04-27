#include<iostream>
using namespace std;

int L,R,cnt;

int main()
{
    cin >> L >> R;
    for(int i=L; i<=R; i++)
    {
        int num = i;
        while(num)
        {
            if(num % 10 == 2) cnt++;
            num /= 10;
        }
    }

    cout << cnt;
    return 0;
}