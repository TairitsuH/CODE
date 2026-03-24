#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    int count = 1, max1 = 0, flag = 0;
    cin >> n;
    int m, N;
    for(int i=0; i<n; i++)
    {
        if(i == 0)
        {
            cin >> N;
        }
        else
        {
            cin >> m;
            if(N == m-1)
            {
                flag = 1;
                count++;
                max1 = max(max1, count);
            }
            else
            {
                count = 1;
            }
            N = m;
        }
    }

    if(flag == 0)
    {
        cout << "1" << endl;
    }
    else
    {
        cout << max1 << endl;
    }
    return 0;
}