#include "Heap.h"
#include "Heap.c"
#include<time.h>

//造数据
void CreatData()
{
    int n = 100;
    srand(time(0));
    const char* file = "data.txt";
    FILE* fin = fopen(file, "w");
    if(fin == NULL)
    {
        perror("fopen error");
        exit(1);
    }

    for(int i=0; i<n; i++)
    {
        int x = (rand() + i) % 1000;
        fprintf(fin, "%d\n", x);
    }

    fclose(fin);
}

//找前k个数
void HeapSortTopK()
{
    int k;
    printf("请输入你要查找的前K个数：\n");
    scanf("%d", &k);

    //开出k个元素的堆空间
    int* KMinHeap = (int*)malloc(sizeof(int)*k);
    if(!KMinHeap)
    {
        perror("malloc fail");
        exit(1);
    }

    //打开文件
    const char* file = "data.txt";
    FILE* fout = fopen(file, "r");
    if(!fout)
    {
        perror("fopen fail");
        exit(1);
    }

    //读取前k个数，建堆
    for(int i=0; i<k; i++)
    {
        fscanf(fout, "%d", &KMinHeap[i]);
    }
    for(int i=(k-1-1)/2; i>=0; i--)
    {
        AdjustDown(KMinHeap, k, i);
    }

    //读取剩下的k个数
    int x = 0;
    while(fscanf(fout, "%d", &x) > 0)
    {
        if(x > KMinHeap[0])
        {
            KMinHeap[0] = x;
            AdjustDown(KMinHeap, k, 0);
        }
    }

    //打印
    printf("最大的前K个数为：");
    for(int i=0; i<k; i++)
    {
        printf("%d ", KMinHeap[i]);
    }
    printf("\n");
}

int main()
{
    CreatData();
    HeapSortTopK();
    return 0;
}
