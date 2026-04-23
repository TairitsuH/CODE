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
    pst->top = pst->capacity = 0;
}

//入栈
void STPush(ST* pst, STDataType x)
{
    assert(pst);

    //需要扩容的情况
    if(pst->top == pst->capacity)
    {
        int newcapacity = pst->capacity == 0 ? 4 : 2*pst->capacity;
        STDataType* tmp = (STDataType*)realloc(pst->a, sizeof(STDataType) * newcapacity);
        if(tmp == NULL)
        {
            perror("realloc fail");
            exit(1);
        }
        pst->a = tmp;
        pst->capacity = newcapacity;
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
    assert(pst && pst->top>0);
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
    return pst->top;
}

//打印栈的元素
//如果需要更改STDataType的类型则对应的输出格式也要更改
void STPrint(ST *pst)
{
    assert(pst);
    for(int i=0; i<pst->top; i++)
    {
        printf("%d ", pst->a[i]);
    }
    printf("\n");
}