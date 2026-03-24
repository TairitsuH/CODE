//蛇形方阵 P5731
//2026.3.13 复盘
#include<iostream>
#include<cstdio>
using namespace std;

const int N = 15;
int arr[N][N];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int pos;

int main()
{
    int n; cin >> n;
    int i = 1;
    int x = 1, y = 1;

    while(i <= n*n)
    {
        int a, b;
        arr[x][y] = i;

        a = x + dx[pos];
        b = y + dy[pos];

        if(a > n || b > n || b < 1 || arr[a][b] != 0)
        {
            pos = (pos + 1) % 4;
            a = x + dx[pos];
            b = y + dy[pos];
        }

        x = a;
        y = b;
        i++;
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            printf("%3d", arr[i][j]);
        }
        cout << endl;
    }

    return 0;
}