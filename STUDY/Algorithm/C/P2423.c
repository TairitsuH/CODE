#include<stdio.h>
#include<math.h>
int main() 
{
    int T;
    scanf("%d",&T);
    if (T == 1) 
    {
      printf("I love Luogu!");
    }
     else if (T == 2)
    {
      printf("6 4");
    } 
    else if (T == 3)
    {
      printf("3\n12\n2\n");
    } 
    else if (T == 4) 
    {
      double water = 500/3;
      printf("%.6lf",water);
    } 
    else if (T == 5) 
    {
       printf("15");
    } 
    else if (T == 6) 
    {
      double a = 6;
      double b = 9;
      double c = sqrt(pow(a,2)+pow(b,2));
      printf("%lf",c);
    }
     else if (T == 7) 
    {
      printf("110\n90\n0\n");
    }  
    else if (T == 8)
    {
      double pai = 3.141593;
      double r = 5;
      double C = 2*pai*r;
      double S = pai*pow(r,2);
      double V = 4/3*pai*pow(r,2);
      printf("%lf\n%lf\n%lf\n",C,S,V);
    }
    else if (T == 9) 
    {
      printf("22");
    } 
    else if (T == 10)
    {
      printf("9");
    }
    else if (T == 11)
    {
      double t = 100/3;
      printf("%lf",t);
    } 
    else if (T == 12) 
    {
      printf("13\nR\n");
    } 
    else if (T == 13) 
    {
      double pai = 3.141593;
      double V1 = 4/3*pai*pow(4,3);
      double V2 = 4/3*pai*pow(10,3);
      double V3 = V1 + V2;
      double a = cbrt(V3);
      printf("%d",a);
    } 
    else if (T == 14) 
    {
      printf("50");
    }
    return 0;
}