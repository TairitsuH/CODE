#include<iostream>
#include<cstdio>
using namespace std;

int m,n,sum;
double cnt;
int arr1[200][200];
int arr2[200][200];

int main()
{
    cin >> m >> n;
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cin >> arr1[i][j];
        }
    }
    
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cin >> arr2[i][j];
        }
    }

    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(arr1[i][j] == arr2[i][j]) cnt++;
        }
    }

    printf("%.2lf",cnt/m/n*100);

    return 0;
}