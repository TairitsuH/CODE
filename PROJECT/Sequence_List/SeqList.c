#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include "SeqList.h"

void SLInit(SL* ps) //传入结构体
{
    ps -> arr = NULL;
    ps -> size = 0;
    ps -> capacity = 0;
}

void SLDestroy(SL* ps) //销毁
{
    if(ps -> arr) //arr不为空
    {
        free(ps -> arr);
    }
    ps -> arr = NULL;
    ps -> size = 0;
    ps -> capacity = 0;
}

void SLCheckCapacity(SL* ps) //检查内存，扩容
{
    assert(ps);
    if(ps -> capacity == ps -> size) //包含空间不足和空间为空两种情况
    {
        int newcapacity = ps->capacity == 0 ? INIT_CAPACITY : 2*ps->capacity;
        SLDataType* tmp = (SLDataType*)realloc(ps->arr, newcapacity*sizeof(SLDataType));

        if(tmp == NULL) //开辟失败
        {
            perror("realloc fail");
            exit(1); //异常退出
        }
        else
        {
            ps -> arr = tmp; //不要忘记把临时变量赋值给arr！！
            ps->capacity = newcapacity;
        }
    }
}

void SLPushFront(SL* ps, SLDataType x)
//头插:在下标为0处插入x
{
    assert(ps);
    SLCheckCapacity(ps);

    for(int i=ps->size-1; i>=0; i--)
    {
        ps->arr[i+1] = ps->arr[i];
    } //最后一次：ps->arr[1] = ps->arr[0]

    ps->arr[0] = x;
    ps->size++;
}

void SLPushBack(SL* ps, SLDataType x) //尾插
{
    assert(ps);
    SLCheckCapacity(ps);

    ps->arr[ps->size] = x;
    ps->size++;
}

void SLPopFront(SL* ps) //头删
{
    assert(ps);
    assert(ps->size); //有元素才能删

    for(int i=1; i<=ps->size-1; i++)
    {
        ps->arr[i-1] = ps->arr[i];
        //第一次：ps->arr[0] = ps->arr[1];
        //最后一次：ps->arr[size-2] = ps->arr[size-1];

    }
    ps->size--;
}

void SLPopBack(SL* ps) //尾删
{
    assert(ps);
    assert(ps->size); //有元素才能删

    ps->size--;
}

void SLInsert(SL* ps, int pos, SLDataType x) //指定插入
{
    assert(ps);
    assert(pos>=0 && pos<=ps->size); //还需断言pos的合法性

    SLCheckCapacity(ps);

    for(int i=ps->size; i>pos; i--)
    {
        ps->arr[i] = ps->arr[i-1];
    }
    //最后一次：ps->arr[pos+1] = ps->arr[pos];
    ps->arr[pos] = x;
    ps->size++;
}

void SLErase(SL* ps, int pos) //指定删除
{
    assert(ps);
    assert(pos>=0 && pos<ps->size);

    for(int i=pos; i<ps->size-1; i++)
    {
        ps->arr[i] = ps->arr[i+1];
    }
    //最后一次：ps->arr[ps->size-2] = ps->arr[ps->size-1];

    ps->size--;
}

void SLFind(SL* ps, SLDataType x) //查找
{
    assert(ps);
    int flag = 1;
    for(int i=0; i<=ps->size-1; i++)
    {
        if(ps->arr[i] == x)
        {
            printf("找到了！下标是%d\n", i);
            flag = 0;
        }
    }
    if(flag == 1)
    {
        printf("没找到TvT\n");
    }
}

void SLPrint(SL* ps) //打印
{
    assert(ps);
    for(int i=0; i<ps->size; i++)
    {
        printf("%d ", ps->arr[i]);
    }
    printf("\n");
}