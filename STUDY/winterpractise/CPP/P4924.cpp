#include<iostream>
using namespace std;

const int N = 100;
int m,n,x,y,r,z;
int a[N][N];

void cpy(int a[][N], int b[][N], int R)
{
    for(int i=1; i<=R; i++)
    {
        for(int j=1; j<=R; j++)
        {
            a[i][j] = b[i][j];
        }
    }
}

void clkwise(int run[][N], int R)
{
    int test[N][N];
    for(int i=1; i<=R; i++)
    {
        for(int j=1; j<=R; j++)
        {
            test[i][j] = run[j][n-i-1];
        }
    }
    cpy(run, test, R);
}

void atclkwise(int run[][N], int R)
{
    int test[N][N];
    for(int i=1; i<=R; i++)
    {
        for(int j=1; j<=R; j++)
        {
            test[i][j] = run[i][n-j-1];
        }
    }
    cpy(run, test, R);
}


int main()
{
    cin >> n >> m;
    int num = 1;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            a[i][j] = num;
            num++;
        }
    }

    while(m--)
    {
        cin >> x >> y >> r >> z;
        int R = 2*r+1;
        int run[N][N] = {0};
        int X = x-r, Y = y-r;
        for(int i=1; i<=R; i++)
        {
            for(int j=1; j<=R; j++)
            {
                run[i][j] = a[X][Y];
                X++;
                Y++;
            }
        }
        if(z == 0) 
        {
            clkwise(run, R);
            X = x-r, Y = y-r;
            for(int i=1; i<=R; i++)
            {
                for(int j=1; j<=R; j++)
                {
                    a[X][Y] = run[i][j];
                    X++;
                    Y++;
                }
            }
        }
        else
        {
            atclkwise(run, R);
            X = x-r, Y = y-r;
            for(int i=1; i<=R; i++)
            {
                for(int j=1; j<=R; j++)
                {
                    a[X][Y] = run[i][j];
                    X++;
                    Y++;
                }
            }
        }
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}