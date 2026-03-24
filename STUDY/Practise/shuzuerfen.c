//二分法查找数组元素
#include<stdio.h>
int main()
{
  int arr[10] = {1,2,3,4,5,6,7,8,9,10};
  int sz = sizeof(arr)/sizeof(arr[0]);
  int left = 0;
  int right = sz - 1;
  int k = 0;
  int flag = 0;
  scanf("%d",&k);
  while(left<=right)
  {
    int mid = (left-right)/2+right;//每次循环都要计算一次mid
    // int mid = (left+right)/2; 这种方法可能会出现误差
    if(arr[mid] > k)//用下标锁定元素进行比较而不是比较下标
    {
      right = mid-1;
    }
    else if(arr[mid] < k)
    {
      left = mid+1;
    }
    else if(arr[mid] == k)
    {
      printf("找到了！这个数的下标是%d\n",mid);
      flag = 1;
      break;
    }
  }
  if(flag == 0)
  {
    printf("输入错误，目标无法找到。");
  }
  return 0;
}