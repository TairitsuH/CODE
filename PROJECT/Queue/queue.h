#pragma once
#include<stdbool.h>

typedef int QLNDataType;

//队列的节点
typedef struct QListNode
{
    struct QListNode* next;
    QLNDataType val;
}QNode;

//队列的结构
typedef struct Queue
{
    QNode* phead; //队头指针
    QNode* ptail; //队尾指针
    int size; //队列长度
}Queue;

//初始化
void QueueInit(Queue* pq);
//销毁
void QueueDestroy(Queue* pq);

//尾插
void QueuePush(Queue* pq, QLNDataType x);

//头删
void QueuePop(Queue* pq);

//获取数据个数（队列长度）
int QueueSize(Queue* pq);

//取队头 / 队尾元素
QLNDataType QueueFront(Queue* pq);
QLNDataType QueueBack(Queue* pq);

//判空
bool QueueEmpty(Queue* pq);
 
//打印队列(左边是头，右边是尾)
void QueuePrint(Queue* pq);