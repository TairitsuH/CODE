#include <stdio.h>

int stk[70];
int que[5];

int main()
{
    int t;
    if(scanf("%d", &t) != 1) return 0;
    while(t--)
    {
        double n;
        int k;
        scanf("%lf %d", &n, &k);

        int neg = 0;
        if(n < 0) { neg = 1; n = -n; }

        long long a = (long long)n;
        double b = n - a;

        int top = 0;
        if(a == 0) stk[top++] = 0;
        while(a > 0)
        {
            stk[top++] = (int)(a % k);
            a /= k;
        }

        for(int i = 0; i < 3; i++)
        {
            int d = (int)(b * k);
            b = b * k - d;
            que[i] = d;
        }

        if(neg) putchar('-');
        while(top > 0)
        {
            int d = stk[--top];
            putchar(d < 10 ? '0' + d : 'A' + d - 10);
        }
        putchar('.');
        for(int i = 0; i < 3; i++)
        {
            int d = que[i];
            putchar(d < 10 ? '0' + d : 'A' + d - 10);
        }
        putchar('\n');
    }
    return 0;
}
