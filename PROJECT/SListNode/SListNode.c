#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include "SListNode.h"

//打印链表元素
void SLTPrint(SLTNode* pphead)
{
    SLTNode* pcur = pphead;
    while(pcur)
    {
        printf("%d->", pcur->data);
        pcur = pcur->next;
    }
    printf("NULL\n");
}

//创建新节点
SLTNode* SLTBuyNode(SLTDataType x)
{
    SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
    if(newnode == NULL)
    {
        perror("malloc fail");
        exit(1); //异常退出
    }
    newnode->data = x;
    newnode->next = NULL;

    return newnode;
}

//头插
void SLTPushFront(SLTNode** pphead, SLTDataType x)
{
    assert(pphead); 
    //assert仅判断pphead是否为有效指针，和*pphead中存储的内容是否为空无关
    SLTNode* newnode = SLTBuyNode(x);
    newnode->next = *pphead;
    *pphead = newnode;
}

//尾插
void SLTPushBack(SLTNode** pphead, SLTDataType x)
{
    assert(pphead);
    //没有头节点:头插
    if(*pphead == NULL)
    {
        SLTPushFront(pphead, x);
        return;
    }

    //有头节点
    SLTNode* pcur = *pphead;
    while(pcur->next)
    {
        pcur = pcur->next;
    }

    SLTNode* newnode = SLTBuyNode(x);

    pcur->next = newnode;
}

//尾删
void SLTPopBack(SLTNode** pphead)
{
    assert(pphead && *pphead); //确保链表不为空

    //仅有头结点：头删
    if((*pphead)->next == NULL) //注意运算符的优先级！
    {
        SLTPopFront(pphead);
        return;
    }

    SLTNode* pcur = *pphead;
    while(pcur->next->next)
    {
        pcur = pcur->next;
    }

    free(pcur->next);
    pcur->next = NULL;
}

//头删
void SLTPopFront(SLTNode** pphead)
{
    assert(pphead && *pphead);

    SLTNode* tmp = *pphead;
    *pphead = (*pphead)->next; //注意运算符的优先级！
    free(tmp);
    tmp = NULL;
}

//查找
void SLTFind(SLTNode* pphead, SLTDataType x)
{
    assert(pphead);
    SLTNode* pcur = pphead;
    while(pcur)
    {
        if(pcur->data == x)
        {
            printf("找到了！\n");
            return;
        }
        pcur = pcur->next;
    }
    printf("没找到TvT\n");
}

//指定位置前插
void SLTInsertFront(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
    assert(pphead && *pphead);
    assert(pos);
    SLTNode* newnode = SLTBuyNode(x);
    //头插
    if(pos == *pphead)
    {
        SLTPushFront(pphead, x);
        return;
    }

    //非头插
    SLTNode* prev = *pphead;
    while(prev->next != pos)
    {
        prev = prev->next;
    }

    newnode->next = pos;
    prev->next = newnode;
}

//指定位置后插
void SLTInsertBack(SLTNode* pos, SLTDataType x)
{
    assert(pos);
    SLTNode* newnode = SLTBuyNode(x);

    newnode->next = pos->next;
    pos->next = newnode;
}

//删除pos节点
void SLTErase(SLTNode** pphead, SLTNode* pos)
{
    assert(pphead && *pphead);
    assert(pos);
    //pos为头节点
    if(pos == *pphead)
    {
        *pphead = pos->next;
    }
    //pos非头节点
    else
    {
        SLTNode* prev = *pphead;
        while(prev->next != pos)
        {
            prev = prev->next;
        }
        prev->next = pos->next;
    }

    free(pos);
    pos = NULL;
}

//删除pos后的节点
void SLTEraseAfter(SLTNode* pos)
{
    assert(pos && pos->next);
    SLTNode* del = pos->next;
    pos->next = pos->next->next;
    free(del);
    del = NULL;
}

//销毁链表
void SLTDestroy(SLTNode** pphead)
{
    assert(pphead && *pphead);
    SLTNode* del = *pphead;
    *pphead = NULL;
    while(del ->next != NULL)
    {
        SLTNode* tmp = del -> next;
        free(del);
        del = tmp;
    }
} //没必要对del置空，因为临时变量出函数就会销毁