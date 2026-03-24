#include<iostream>
using namespace std;

int N, cnt, ct, sum;
int ans = 1;

int main()
{
    cin >> N;
    sum = N * N;
    while(ans < sum)
    {
        cin >> ct;
        for(int i=0; i<ct; i++)
        {
            cout << cnt;
            if(ans % N == 0)
            {
                cout << endl;
            }
            ans++;
        }
        cnt = 1 - cnt;
    }
    return 0;
}