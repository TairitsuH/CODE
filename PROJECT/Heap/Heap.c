#include "Heap.h"

//初始化
void HPInit(Heap* php)
{
    assert(php);
    php->a = NULL;
    php->size = 0; //size指向顺序表（堆）中有效元素的下一位
    php->capacity = 0;
}

//销毁
void HPDestroy(Heap* php)
{
    assert(php);
    
    //动态申请的空间实际上是结构体内部的顺序表
    free(php->a);
    php->a = NULL;
    php->size = 0;
    php->capacity = 0;
}

//交换
void Swap(HPDataType* a, HPDataType* b)
{
    HPDataType tmp = *a;
    *a = *b;
    *b = tmp;
}

//向上调整(小根堆)
void AdjustUp(HPDataType* a, int child)
{
    //父->子：*2+1
    //子->父：-1)/2
    while(child > 0)
    {
        int parent = (child - 1) / 2;
        if(a[child] < a[parent]) //大根堆改为>
        {
            Swap(&a[child], &a[parent]);
            child = parent;
        }
        else
        {
            break;
        }
    }
}

//向下调整（小根堆）
void AdjustDown(HPDataType* a, int n, int parent)
{
    //父->子：*2+1
    //子->父：-1)/2
    while(parent <= (n-1)/2)
    {
        //假设法（左孩子小）
        int child = parent * 2 + 1;
        if(child+1 < n && a[child+1] < a[child])
        {
            child += 1;
        }

        if(a[parent] > a[child]) //大根堆改为<
        {
            Swap(&a[parent], &a[child]);
            parent = child;
        }
        else
        {
            break;
        }
    }
}

//插入元素
void HPPush(Heap* php, HPDataType x)
{
    assert(php);
    //判断是否需要扩容
    if(php->size == php->capacity)
    {
        //初始空间或两倍扩容(注意malloc和realloc的区别)
        int newcapacity = php->capacity == 0 ? 4 : 2*php->capacity;
        HPDataType* tmp = (HPDataType*)realloc(php->a, newcapacity*sizeof(HPDataType));
        if(tmp == NULL)
        {
            perror("realloc fail");
            exit(1);
        }

        php->capacity = newcapacity;
        php->a = tmp;
    }

    //尾部插入
    php->a[php->size++] = x;
    //向上调整为堆
    AdjustUp(php->a, php->size-1);
}

//删除堆顶元素
void HPPop(Heap* php)
{
    assert(php && php->size > 0);
    //交换首尾元素
    Swap(&php->a[0], &php->a[php->size-1]);

    //删除尾元素
    php->size--;
    
    //向下调整
    AdjustDown(php->a, php->size, 0);
}

//获取堆顶元素
HPDataType HPTop(Heap* php)
{
    assert(php && php->size > 0);
    return php->a[php->size-1];
}

//判空
bool HPEmpty(Heap* php)
{
    assert(php);
    return php->size == 0;
}

//打印堆
void HPPrint(Heap* php)
{
    for(int i=0; i<php->size; i++)
    {
        printf("%d ", php->a[i]);
    }
    printf("\n");
}