//数组计算：给十个整数，计算总和
#include<stdio.h>
int main()
{
  int arr[10] = {0};
  int sz = sizeof(arr)/sizeof(arr[0]);//求数据个数：总字节/每个数据的字节
  int i = 0;
  for(i=0; i<sz; i++)
  {
    scanf("%d",&arr[i]);
  }
  int sum = 0;
  for(i=0; i<sz; i++)
  {
    sum += arr[i];
  }
  printf("sum = %d",sum);
  return 0;
}

//二维数组输入输出
#include<stdio.h>
int main()
{
  int i = 0;
  int arr[3][6];
  for(i=0; i<3; i++)//行循环
  {
    int j = 0;
    for(j=0; j<5; j++)//列循环
    {
      scanf("%d",&arr[i][j]);//数据输入
    }
  }
  for(i=0; i<3; i++)//行循环
  {
    int j = 0;
    for(j=0; j<5; j++)//列循环
    {
      printf("%d ",arr[i][j]);//打印数组（一行行打印）
    }
    printf("\n");
  }
  return 0;
}

//二维数组：按照一列列打印
#include<stdio.h>
int main()
{
  int i = 0;
  int j = 0;
  int arr[3][5];
  for(i=0; i<3; i++)//行循环
  {
    int j = 0;
    for(j=0; j<5; j++)//列循环
    {
      scanf("%d",&arr[i][j]);//数据输入
    }
  }
  for(i=0; i<5; i++)
  {
    for(j=0; j<3;j++)
    {
      printf("%d ",arr[j][i]);//打印数组（一列列打印）
    }
    printf("\n");
  }
  return 0;
}

//C99可变数组输入输出
#include<stdio.h>
int main()
{
  int i = 0;
  int n = 0;
  printf("请输入你想存储的数据数量：");
  scanf("%d",&n);
  int arr[n];
  for(i=0; i<n; i++)
  {
    scanf("%d",&arr[i]);    
  }
  for(i=0; i<n; i++)
  {
    printf("%d ",arr[i]);
  }
  return 0;
}