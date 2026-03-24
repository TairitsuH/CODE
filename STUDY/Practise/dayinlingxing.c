#include<stdio.h>
int main()
{
  int n = 0;
  scanf("%d",&n);
  printf("   +---+\n");
  while(n)
  {
    printf("  /     \\\n +       +\n  \\     /\n");
    printf("   +---+\n");
    n--;
  }
}