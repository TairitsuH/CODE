#pragma once

typedef int LTDataType;

typedef struct ListNode
{
    LTDataType data;
    struct ListNode* prev;
    struct ListNode* next;
}LTNode;


LTNode* LTBuyNode(LTDataType x); //新建节点

//无返回值的初始化，传二级指针(不推荐，因为接口不一致)
void LTInit1(LTNode** pphead);

//有返回值的初始化（推荐）
LTNode* LTInit2();


void LTPrint(LTNode* phead); //打印链表

void LTPushBack(LTNode* phead, LTDataType x); //尾插
void LTPushFront(LTNode* phead, LTDataType x); //头插

void LTPopBack(LTNode* phead); //尾删
void LTPopFront(LTNode* phead); //头删

LTNode* LTFind(LTNode* phead, LTDataType x); //查找元素

void LTInsert(LTNode* pos, LTDataType x); //在pos之后插入节点（之前和之后一个原理，这里只演示后插
void LTErase(LTNode* pos); //删除pos元素

void LTDestroy(LTNode* phead); //销毁链表

//插入和删除都要使用assert判断链表有效，而且删除还要判断链表不为空