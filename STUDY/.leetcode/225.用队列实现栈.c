/*
 * @lc app=leetcode.cn id=225 lang=c
 *
 * [225] 用队列实现栈
 */

// @lc code=start


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

typedef struct
{
    Queue q1;    
    Queue q2;    
} MyStack;


MyStack* myStackCreate()
{
    MyStack* pst = (MyStack*)malloc(sizeof(MyStack));
    //用指针开辟空间，否则使用局部变量会在回传时销毁
    //不能用全局，多次调用无法解决
    
    QueueInit(&(pst->q1));
    QueueInit(&(pst->q2));

    return pst;
}

void myStackPush(MyStack* obj, int x)
{
    if(!QueueEmpty(&(obj->q1)))
    {
        QueuePush(&(obj->q1), x);
    }   
    else
    {
        QueuePush(&(obj->q2), x);
    }
    //保证有一个队列为空
}

int myStackPop(MyStack* obj)
{
    //不为空的前size-1个数放入另一个队列，再把第size个数先复制后删除
    //假设法
    Queue* empty = &(obj->q1);
    Queue* NoEmpty = &(obj->q2);
    if(!QueueEmpty(&(obj->q1)))
    {
        empty = NoEmpty;
        NoEmpty =&(obj->q1);
    }

    while(QueueSize(NoEmpty) > 1)
    {
        QueuePush(empty, QueueFront(NoEmpty));
        QueuePop(NoEmpty);
    }

    int top = QueueFront(NoEmpty);
    QueuePop(NoEmpty);

    return top;
}

int myStackTop(MyStack* obj)
{
    if(!QueueEmpty(&(obj->q1)))
    {
        return QueueBack(&(obj->q1));
    }
    else
    {
        return QueueBack(&(obj->q2));
    }

}

bool myStackEmpty(MyStack* obj)
{
    return QueueEmpty(&(obj->q1)) && QueueEmpty(&(obj->q2));
}

void myStackFree(MyStack* obj)
{
    QueueDestroy(&(obj->q1));
    QueueDestroy(&(obj->q2));

    free(obj);
    //不能仅free掉obj，否则会导致队列未释放，造成内存泄漏
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/
// @lc code=end

