#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include "stack.h"

//栈的初始化
void STInit(ST* pst)
{
    assert(pst);
    pst->a = NULL;
    pst->top = 0; //指向数组末尾有效元素的下一位
    pst->capacity = 0;
}

//销毁
void STDestroy(ST* pst)
{
    assert(pst);
    free(pst->a);
    pst->a = NULL;
    pst->top = pst->capacity = NULL;
}

//入栈
void STPush(ST* pst, STDataType x)
{
    assert(pst);

    //需要扩容的情况
    if(pst->top == pst->capacity)
    {
        int newcapacity = pst->capacity == 0 ? 4 : 2*pst->capacity;
        ST* tmp = (ST*)realloc(pst->a, sizeof(STDataType)*pst->capacity);
        if(tmp == NULL)
        {
            perror("realloc fail");
            exit(1);
        }
        pst->a = tmp;
    }
    
    pst->a[pst->top] = x;
    pst->top++; 
}

//出栈
void STPop(ST* pst)
{
    assert(pst && pst->top != 0);
    pst->top--;
}

//查询栈顶元素
STDataType STTop(ST* pst)
{
    assert(pst && pst->top);
    return pst->a[pst->top-1];
}

//判空
bool STEmpty(ST* pst)
{
    assert(pst);
    return pst->top == 0;
}

//查询数据个数
int STSize(ST* pst)
{
    assert(pst);
    return pst->top+1;
}