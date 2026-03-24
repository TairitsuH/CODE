#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    scanf("%d",&n);
    switch(n)
    {
        case 1:
        {
            printf("I love Luogu!");
            break;
        }
        case 2:
        {
            printf("6 4");
            break;
        }
        case 3:
        {
            printf("%d\n",14/4);
            printf("%d\n",14/4*4);
            printf("%d\n",14-14/4*4);
            break;
        }
        case 4:
        {
            double water = 500;
            printf("%.3lf\n",water/3);
            break;
        }
        case 5:
        {
            printf("%d\n",480/32);
            break;
        }
        case 6:
        {
            printf("%.4f\n",sqrt(6*6+9*9));
            break;
        }
        case 7:
        {
            printf("110\n");
            printf("90\n");
            printf("0\n");
            break;
        }
        case 8:
        {
            float pi = 3.141593;
            float C = 2*pi*5;
            float S = pi*5*5;
            float V = 4/3.0*pi*5*5*5;
            printf("%.6g\n%.6g\n%.6g\n",C,S,V);
            break;
        }
        case 9:
        {
            printf("22\n");
            break;
        }
        case 10:
        {
            printf("9\n");
            break;
        }
        case 11:
        {
            printf("%.6g\n",100/3.0);
            break;
        }
        case 12:
        {
            printf("13\n");
            printf("R\n");
            break;
        }
        case 13:
        {
            double pi = 3.141593;
            double V = 4/3.0*4*4*4*pi+4/3.0*10*10*10*pi;
            int a = floor(cbrt(V));
            printf("%d",a);
            break;
        }
        case 14:
        {
            printf("50\n");
            break;
        }
    }
    return 0;
}