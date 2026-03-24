#include<stdio.h>
int main()
{
  int n = 1;
  int m = 1;
  int out = 0;
  int i,j;
  for(i=0; i<9; i++)
  {
      int out = n * m;
      printf("%d*%d=%d  ",n,m,out);
      for(j=0; j<9; j++)
      {
        int out = n * m;
        printf("%d*%d=%d  ",n,m,out);
        m++;
      }
      printf("\n");
      m = 1;
      n++;
  }
  return 0;
}