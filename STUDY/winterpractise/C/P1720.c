#include<stdio.h>
#include<math.h>
int main()
{   
    int n;
    double a = 1, b = 1;
    double Fn;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        a *= (1+sqrt(5.0))/2.0;
        b *= (1-sqrt(5.0))/2.0;
    }
    Fn = (a-b)/sqrt(5.0);
    printf("%.2lf",Fn);

    return 0;
}