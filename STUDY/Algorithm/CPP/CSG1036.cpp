#include<iostream>
using namespace std;

int n, m, k;

int main()
{
    for(int j=0; j<10; j++)
    {
        start:
        cin >> n >> m >> k;
        int* a = new int [n+1];
        a[n + 1] = {0};

        if(n == 0 && m == 0 && k == 0)
        {
            break;
        }

        int round = 1;
        int num = 1;
        while(1)
        {
            if(round % 2 == 1)
            {
                for(int i=1; i<n; i++)
                {
                    if(a[m] < k)
                    {
                        if(num % 10 == 7 || num % 7 == 0)
                        {
                            a[i]++;
                        }
                        num++;
                    }
                    else if(a[m] == k)
                    {
                        cout << num-1 << endl;
                        delete [] a;
                        goto start;

                    }
                }
            }
            else
            {
                for(int i=n; i>1; i--)
                {
                    if(a[m] < k)
                    {
                        if(num % 10 == 7 || num % 7 == 0)
                        {
                            a[i]++;
                        }
                        num++;
                    }
                    else
                    {
                        cout << num-1 << endl;
                        delete [] a;
                        goto start;
                    }
                }
            }
            round++;
        }
    }

    return 0;
}