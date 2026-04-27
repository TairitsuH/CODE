#include<stdio.h>

const int N = 1e6 + 10;
int a[N];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    int max = 0;
    for(int i=0; i<m+n; i++)
    {
        int j = 0, cnt;
        scanf("%d%d", &j, &cnt);
        a[j] += cnt;
        if(j > max)
        {
            max = j;
        }
    }

    for(int i=0; i<=max; i++)
    {
        if(a[i] != 0)
        {
            printf("%d %d\n", i, a[i]);
        }
    }
    return 0;
}