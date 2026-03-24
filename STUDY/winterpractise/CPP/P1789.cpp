#include<iostream>
using namespace std;

int m, n, k;
const int N = 120;
int arr[N][N];
int dx[] = {-2,-1,0,1,2,0,0,0,0,-1,-1,1,1};
int dy[] = {0,0,0,0,0,2,1,-1,-2,-1,1,-1,1};

void fire(int x, int y)
{
    x+=1;
    y+=1;
    for(int l=0; l<13; l++)
    {
        int a = x + dx[l];
        int b = y + dy[l];
        arr[a][b]++;
    }
}

void stone(int x, int y)
{
    for(int l=x; l<=x+4; l++)
    {
        for(int q=y; q<=y+4; q++)
        {
            arr[l][q]++;
        }
    } 

}

int main()
{
    cin >> n >> m >> k;
    while(m--) //火把
    {
        int x, y;
        cin >> x >> y;
        fire(x, y);
    }

    while(k--)
    {
        int o, p;
        cin >> o >> p;
        stone(o, p);
    }

    int cnt = 0;
    for(int i=2; i<=n+1; i++)
    {
        for(int j=2; j<=n+1; j++)
            {
                if(arr[i][j] == 0) cnt++;
            }
    }

    cout << cnt;
    return 0;
}