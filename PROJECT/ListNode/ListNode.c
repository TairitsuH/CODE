#include "ListNode.h"
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>

//新建节点
LTNode* LTBuyNode(LTDataType x)
{
    LTNode* tmp = (LTNode*)malloc(sizeof(LTNode));
    if(tmp == NULL)
    {
        perror("malloc fail");
        exit(1);
    }
    tmp->data = x;
    tmp->prev = tmp->next = tmp; //要指向自己！！（循环链表！）
    return tmp;
}

//无返回值的初始化，传二级指针(不推荐，因为接口不一致)
void LTInit1(LTNode** pphead)
{
    //创建哨兵位
    *pphead = LTBuyNode(-1);
}

//有返回值的初始化，传一级指针（推荐）
LTNode* LTInit2()
{
    LTNode* phead = LTBuyNode(-1);
    return phead;
}

void LTPrint(LTNode* phead) //打印链表
{
    LTNode* pcur = phead->next;
    while(pcur != phead)
    {
        printf("%d->", pcur->data);
        pcur = pcur->next;
    }
    printf("\n");
}

void LTPushBack(LTNode* phead, LTDataType x) //尾插
{
    assert(phead);
    LTNode* newnode = LTBuyNode(x);
    
    newnode->prev = phead->prev;
    newnode->next = phead;

    phead->prev->next = newnode;
    phead->prev = newnode;
}

void LTPushFront(LTNode* phead, LTDataType x) //头插
{
    assert(phead);
    LTNode* newnode = LTBuyNode(x);

    newnode->next = phead->next;
    newnode->prev = phead;

    phead->next->prev = newnode;
    phead->next = newnode;
}

void LTPopBack(LTNode* phead) //尾删
{
    assert(phead && phead->next != phead);

    LTNode* del = phead->prev;

    del->prev->next = phead;
    phead->prev = del->prev;

    free(del);
    del = NULL;
}

void LTPopFront(LTNode* phead) //头删
{
    assert(phead && phead->next != phead);
    
    LTNode* del = phead->next;

    phead->next = del->next;
    del->next->prev = phead;

    free(del);
    del = NULL;
}

LTNode* LTFind(LTNode* phead, LTDataType x) //查找元素
{
    LTNode* pcur = phead->next;

    while(pcur != phead)
    {
        if(pcur->data == x)
        {
            return pcur;
        }
        else
        {
            pcur = pcur->next;
        }
    }
    return NULL;
}

void LTInsert(LTNode* pos, LTDataType x) //在pos之后插入节点（之前和之后一个原理，这里只演示后插
{
    assert(pos);

    LTNode* newnode = LTBuyNode(x);

    newnode->next = pos->next;
    newnode->prev = pos;

    pos->next->prev = newnode;
    pos->next = newnode;
}

void LTErase(LTNode* pos) //删除pos元素
{
    assert(pos);
    
    pos->prev->next = pos->next;
    pos->next->prev = pos->prev;

    free(pos);
}
//要在函数外将pos置NULL

void LTDestroy(LTNode* phead) //销毁链表
{
    assert(phead);

    LTNode* cur = phead->next;

    while(cur != phead)
    {
        LTNode* next = cur->next;
        free(cur);
        cur = next;
    }
    free(phead);
}