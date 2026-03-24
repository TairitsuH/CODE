//利用数组解决多个字符从两端移动，向中间汇聚的问题
#include<stdio.h>
#include<string.h>
#include<windows.h>//头文件可以使用Sleep指令
#include<stdlib.h>
int main()
{
  char arr1[] = "welcome to bit!!!";
  char arr2[] = "*****************";
  size_t left = 0;
  size_t right = strlen(arr1)-1;
  //strlen仅适用于计算以\0结尾的字符串，sizeof适用于任意类型并且将\0计入其中
  while(left<=right)
  {
    arr2[left] = arr1[left];
    arr2[right] = arr1[right];
    printf("%s\n",arr2);
    Sleep(1000);//休眠1000毫秒，注意大写
    // system("cls");//清屏
    left++;
    right--;
  }
  // printf("%s\n",arr2);//再次打印防止被删除
  return 0;
}
//vscode貌似执行不了windows的system指令，故改为注释