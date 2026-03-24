#include<stdio.h>
int main()
{
  int s;
  scanf("%d",&s);
  //走路多走60m，自行车赶上：需要60/1.8=100/3s,共走了100m
  if(s > 100)
  {
    printf("Bike");
  }
  else if(s == 100)
  {
    printf("All");
  }
  else
  {
    printf("Walk");
  }
  return 0;
}