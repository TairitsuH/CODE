#include<stdio.h>
int main()
{
  int day;
  scanf("%d",&day);
  switch(day)
  {
    case 1 :
    case 3 :
    case 5 :
    {
      printf("NO");
      break;
    }
    case 2 :
    case 4 :
    case 6 :
    case 7 :
    {
      printf("YES");
      break;
    }

  }
  return 0;
}