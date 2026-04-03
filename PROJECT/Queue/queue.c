#include "queue.h"
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

//初始化
void QueueInit(Queue* pq)
{
    assert(pq);
    pq->phead = NULL;
    pq->ptail = NULL;
    pq->size = 0;
}

//销毁
void QueueDestroy(Queue* pq)
{
    assert(pq);
    //一般都是复制一份指针，不会直接用phead
    QNode* pcur = pq->phead;
    while(pcur)
    {
        QNode* tmp = pcur->next;
        free(pcur);
        pcur = tmp;
    }
    pq->phead = NULL;
    pq->ptail = NULL;
    pq->size = 0;
}

//尾插
void QueuePush(Queue* pq, QLNDataType x)
{
    assert(pq);
    //为新节点开辟空间
    QNode* newnode = (QNode*)malloc(sizeof(QNode));
    if(newnode == NULL) //开辟失败
    {
        perror("malloc fail");
        exit(1);
    }

    //初始化新节点
    newnode->next = NULL;
    newnode->val = x;
    //列表为空
    if(pq->phead == NULL)
    {
        pq->phead = newnode;
        pq->ptail = newnode;
    }
    //列表不为空
    else
    {
        pq->ptail->next = newnode;
        pq->ptail = newnode;
    }
    pq->size++; //不要漏掉！
}

//头删
void QueuePop(Queue* pq)
{
    assert(pq && pq->size > 0);

    //队列仅有一个节点
    if(pq->phead->next == NULL)
    {
        free(pq->phead);
        pq->phead = NULL;
        pq->ptail = NULL;
    }
    //队列中有多个节点
    else
    {
        QNode* del = pq->phead;
        pq->phead = pq->phead->next;
        free(del);
    }
    pq->size--; //不要漏掉！
}

//获取数据个数（队列长度）
int QueueSize(Queue* pq)
{
    assert(pq);
    return pq->size;
}

//打印队列(左边是头，右边是尾)
void QueuePrint(Queue* pq)
{
    assert(pq);
    QNode* pcur = pq->phead;
    if(pcur == NULL)
    {
        printf("NULL\n");
        return;
    }
    while(pcur)
    {
        printf("%d->", pcur->val);
        pcur = pcur->next;
    }
    printf("\n");
}

//取队头元素
QLNDataType QueueFront(Queue* pq)
{
    assert(pq && pq->phead); 
    //第二个条件也可以写pq->size!=0，但要确保两者的结果一致
    return pq->phead->val;
}

//取队尾元素
QLNDataType QueueBack(Queue* pq)
{
    assert(pq && pq->ptail);
    return pq->ptail->val;
}

//判空
bool QueueEmpty(Queue* pq)
{
    assert(pq);
    return pq->phead == NULL;
}