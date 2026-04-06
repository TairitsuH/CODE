#include "Heap.h"
#include "Heap.c"
#include<time.h>
#include<stdio.h>
#include<stdlib.h>

// //堆排序（向上调整）
// void HeapSort(int* a, int n)
// {
//     //建堆：降序小堆，升序大堆
//     for(int i=1; i<n; i++)
//     {
//         AdjustUp(a, i); //向上调整，时间复杂度O(logN)
//     }

//     int end = n - 1;
//     while(end > 0)
//     {
//         //和删除堆顶元素类似
//         Swap(&a[0], &a[end]);
//         AdjustDown(a, end, 0);
//         end--;
//     }
// }


//堆排序（向下调整：O(N)
void HeapSort(int* a, int n)
{
    //在原数组上建堆，从最后一个根节点开始向下调整
    for(int i=(n-1-1)/2; i>=0; i--)
    {
        AdjustDown(a, n, i);
    }

    //变为倒序数组
    int end = n - 1;
    while(end > 0) //end为0时，剩下的个数已经全部有序，此时根为最大元素，可以退出循环了
    {
        Swap(a, a+end);
        AdjustDown(a, end, 0);
        end--;
    }
}

int main()
{
    srand(time(0));
    int num;
    printf("请输入要排序的数据个数：\n");
    scanf("%d", &num);
    int a[num];

    for(int i=0; i<num; i++)
    {
        a[i] = (rand()+i) % 100;
    }

    HeapSort(a, num);

    for(int i=0; i<num; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}