#include "Heap.h"
#include "Heap.c"
#include<time.h>
#include<stdio.h>
#include<stdlib.h>

//堆排序
void HeapSort(int* a, int n)
{
    //建堆：降序小堆，升序大堆
    for(int i=1; i<n; i++)
    {
        AdjustUp(a, i); //向上调整，时间复杂度O(logN)
    }

    int end = n - 1;
    while(end > 0)
    {
        //和删除堆顶元素类似
        Swap(&a[0], &a[end]);
        AdjustDown(a, end, 0);
        end--;
    }
}

int main()
{
    srand((unsigned int)time(NULL));

    Heap hp;
    Heap* php = &hp;
    HPInit(php);

    int n = 11;


    for(int i=0; i<n; i++)
    {
        int num = rand() % 50;
        HPPush(php, num); //push会自动调整为堆
    }

    HPPrint(php);

    return 0;
}
