#include <stdio.h>

int T[1010], P[1010];
int fin[12];

int main()
{
    int n, k;
    while (scanf("%d", &n) == 1)     /* 单组数据时读完即退出，不影响 */
    {
        if (n <= 0) break;
        for (int i = 0; i < n; i++)
            scanf("%d %d", &T[i], &P[i]);
        scanf("%d", &k);

        int total = 0, maxwait = 0;
        for (int i = 0; i < n; i++)
        {
            int best = 0;                    /* 最早空闲窗口，并列取编号小 */
            for (int j = 1; j < k; j++)
                if (fin[j] < fin[best]) best = j;
            int start = fin[best] > T[i] ? fin[best] : T[i];
            int wait = start - T[i];
            total += wait;
            if (wait > maxwait) maxwait = wait;
            fin[best] = start + P[i];
        }
        int last = 0;
        for (int j = 0; j < k; j++)
            if (fin[j] > last) last = fin[j];

        int a = total * 10 / n;              /* 截断到1位小数，不四舍五入 */
        printf("%d.%d %d %d\n", a / 10, a % 10, maxwait, last);

        for (int j = 0; j < 12; j++) fin[j] = 0;   /* 多组时重置 */
    }
    return 0;
}
