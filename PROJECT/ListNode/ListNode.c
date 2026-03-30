#pragma once
#include "ListNode.h"
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>

//新建节点
LTNode* LTBuyNode(LTDataType x)
{
    LTNode* tmp = (LTNode*)malloc(sizeof(LTDataType));
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