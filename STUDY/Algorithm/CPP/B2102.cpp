#include<iostream>
using namespace std;

int a[6][6];

int main()
{
    for(int i=1; i<=5; i++)
    {
        for(int j=1; j<=5; j++)
        {
            cin >> a[i][j];
        }
    }

    for(int i=1; i<=5; i++)
    {
        int m = a[i][1];
        int p1 = 0, p2 = 0, flag = 1;
        for(int j=1; j<=5; j++)
        {
            if(a[i][j] >= m) 
            {
                m = a[i][j];
                p1 = i;
                p2 = j;
            }
        }
        for(int k=1; k<=5; k++)
        {
            if(a[k][p2] < m) 
            {
                flag = 0;
                break;
            }
        }
        if(flag == 1)
        {
            cout << p1 << " " << p2 << " " << a[p1][p2];
            return 0;
        }
    }
    cout << "not found";

    return 0;

}