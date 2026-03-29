#pragma once

typedef int SLTDataType;

typedef struct SListNode
{
    SLTDataType data;
    struct SListNode* next; //还未声明结束，不能省略struct
}SLTNode;

//打印链表元素
//不需要修改指针变量中存的地址，仅需把这个地址复制给函数
void SLTPrint(SLTNode* pphead);

//创建新节点
SLTNode* SLTBuyNode(SLTDataType x);

//头部插入删除 & 尾部插入删除
void SLTPushFront(SLTNode** pphead, SLTDataType x);
void SLTPushBack(SLTNode** pphead, SLTDataType x);
void SLTPopBack(SLTNode** pphead);
void SLTPopFront(SLTNode** pphead);

//根据值查找节点
void SLTFind(SLTNode* pphead, SLTDataType x);

//指定位置前插
void SLTInsertFront(SLTNode** pphead, SLTNode* pos, SLTDataType x);
//指定位置后插
void SLTInsertBack(SLTNode* pos, SLTDataType x);
//删除pos节点
void SLTErase(SLTNode** pphead, SLTNode* pos);
//删除pos后的节点
void SLTEraseAfter(SLTNode* pos);
//销毁链表
void SLTDestroy(SLTNode** pphead);

