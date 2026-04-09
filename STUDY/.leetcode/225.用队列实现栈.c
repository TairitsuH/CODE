/*
 * @lc app=leetcode.cn id=225 lang=c
 *
 * [225] 用队列实现栈
 */

// @lc code=start

typedef struct QueueListNode
{
    int val;
    struct QueueListNode* next;
}QLNode;

typedef struct Queue
{
    QLNode* phead;
    QLNode* ptail;
    int size;
}Queue;

//初始化
void QueueInit(Queue* pq)
{
    assert(pq);
    pq->phead = NULL;
    pq->ptail = NULL;
    pq->size = 0;
}

//尾插
void QueuePush(Queue* pq, int x)
{
    assert(pq);

    //初始化节点
    QLNode* tmp = (QLNode*)malloc(sizeof(QLNode));
    tmp->val = x;
    tmp->next = NULL;

    //移动（分类讨论）
    if(!pq->phead) //空队列
    {
        pq->phead = tmp;
        pq->ptail = tmp;
    }
    else
    {
        pq->ptail->next = tmp;
        pq->ptail = pq->ptail->next;
    }

    pq->size++;
}

//头删
void QueuePop(Queue* pq)
{
    assert(pq && pq->phead);

    QLNode* tmp = pq->phead;
    pq->phead = pq->phead->next;

    if(!pq->phead)
    {
        pq->ptail = NULL;
    }

    free(tmp);
    pq->size--;
}

//获取队首元素
int QueueTop(Queue* pq)
{
    assert(pq && pq->phead);
    return pq->phead->val;
}

//获取队尾元素
int QueueBack(Queue* pq)
{
    assert(pq && pq->ptail);
    return pq->ptail->val;
}

//判空
bool QueueEmpty(Queue* pq)
{
    assert(pq);
    return pq->phead==NULL;
}

//销毁
void QueueDestroy(Queue* pq)
{
    assert(pq);
    while(pq->phead)
    {
        QLNode* tmp = pq->phead;
        pq->phead = pq->phead->next;
        free(tmp);
    }
    pq->phead = NULL;
    pq->ptail = NULL;
    pq->size = 0;
}

//获取元素个数
int QueueSize(Queue* pq)
{
    assert(pq);
    return pq->size;
}

typedef struct
{
    Queue q1;
    Queue q2;
} MyStack;


MyStack* myStackCreate()
{
    MyStack* st = (MyStack*)malloc(sizeof(MyStack));
    QueueInit(&st->q1);    
    QueueInit(&st->q2);
    return st;    
}

void myStackPush(MyStack* obj, int x)
{
    //假设法
    Queue* Empty = &obj->q1;
    Queue* NotEmpty = &obj->q2;
    if(!QueueEmpty(&obj->q1))
    {
        NotEmpty = Empty;
        Empty = &obj->q2;
    }

    QueuePush(NotEmpty, x);
}

int myStackPop(MyStack* obj)
{
    //假设法
    Queue* Empty = &obj->q1;
    Queue* NotEmpty = &obj->q2;
    if(!QueueEmpty(&obj->q1))
    {
        NotEmpty = Empty;
        Empty = &obj->q2;
    }

    int size = QueueSize(NotEmpty);
    while(size-- > 1)
    {
        int x = QueueTop(NotEmpty);
        QueuePush(Empty, x);

        QueuePop(NotEmpty);
    }

    int top = QueueTop(NotEmpty);
    QueuePop(NotEmpty);

    return top;
}

int myStackTop(MyStack* obj)
{
    //假设法
    Queue* Empty = &obj->q1;
    Queue* NotEmpty = &obj->q2;
    if(!QueueEmpty(&obj->q1))
    {
        NotEmpty = Empty;
        Empty = &obj->q2;
    }
    return NotEmpty->ptail->val;
}

bool myStackEmpty(MyStack* obj)
{
    return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);  
}

void myStackFree(MyStack* obj)
{
    QueueDestroy(&obj->q1); 
    QueueDestroy(&obj->q2);
    free(obj); 
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

//二刷：OMG，我竟然一遍就写对了所有队列函数？除了在栈的假设法if判断那里出了点问题，其他地方竟然都对了欸！
//一刷：关键点在于一个队列为空，一个队列用于存放数据，需要删除时则将前size-1个数移动至另一队列，然后执行删除。
//只能说只有教育意义，对实战没什么帮助( $ _ $ ) 造轮子中...
// typedef int QLNDataType;

// //队列的节点
// typedef struct QListNode
// {
//     struct QListNode* next;
//     QLNDataType val;
// }QNode;

// //队列的结构
// typedef struct Queue
// {
//     QNode* phead; //队头指针
//     QNode* ptail; //队尾指针
//     int size; //队列长度
// }Queue;

// //初始化
// void QueueInit(Queue* pq)
// {
//     assert(pq);
//     pq->phead = NULL;
//     pq->ptail = NULL;
//     pq->size = 0;
// }

// //销毁
// void QueueDestroy(Queue* pq)
// {
//     assert(pq);
//     //一般都是复制一份指针，不会直接用phead
//     QNode* pcur = pq->phead;
//     while(pcur)
//     {
//         QNode* tmp = pcur->next;
//         free(pcur);
//         pcur = tmp;
//     }
//     pq->phead = NULL;
//     pq->ptail = NULL;
//     pq->size = 0;
// }

// //尾插
// void QueuePush(Queue* pq, QLNDataType x)
// {
//     assert(pq);
//     //为新节点开辟空间
//     QNode* newnode = (QNode*)malloc(sizeof(QNode));
//     if(newnode == NULL) //开辟失败
//     {
//         perror("malloc fail");
//         exit(1);
//     }

//     //初始化新节点
//     newnode->next = NULL;
//     newnode->val = x;
//     //列表为空
//     if(pq->phead == NULL)
//     {
//         pq->phead = newnode;
//         pq->ptail = newnode;
//     }
//     //列表不为空
//     else
//     {
//         pq->ptail->next = newnode;
//         pq->ptail = newnode;
//     }
//     pq->size++; //不要漏掉！
// }

// //头删
// void QueuePop(Queue* pq)
// {
//     assert(pq && pq->size > 0);

//     //队列仅有一个节点
//     if(pq->phead->next == NULL)
//     {
//         free(pq->phead);
//         pq->phead = NULL;
//         pq->ptail = NULL;
//     }
//     //队列中有多个节点
//     else
//     {
//         QNode* del = pq->phead;
//         pq->phead = pq->phead->next;
//         free(del);
//     }
//     pq->size--; //不要漏掉！
// }

// //获取数据个数（队列长度）
// int QueueSize(Queue* pq)
// {
//     assert(pq);
//     return pq->size;
// }

// //打印队列(左边是头，右边是尾)
// void QueuePrint(Queue* pq)
// {
//     assert(pq);
//     QNode* pcur = pq->phead;
//     if(pcur == NULL)
//     {
//         printf("NULL\n");
//         return;
//     }
//     while(pcur)
//     {
//         printf("%d->", pcur->val);
//         pcur = pcur->next;
//     }
//     printf("\n");
// }

// //取队头元素
// QLNDataType QueueFront(Queue* pq)
// {
//     assert(pq && pq->phead); 
//     //第二个条件也可以写pq->size!=0，但要确保两者的结果一致
//     return pq->phead->val;
// }

// //取队尾元素
// QLNDataType QueueBack(Queue* pq)
// {
//     assert(pq && pq->ptail);
//     return pq->ptail->val;
// }

// //判空
// bool QueueEmpty(Queue* pq)
// {
//     assert(pq);
//     return pq->phead == NULL;
// }

// typedef struct
// {
//     Queue q1;    
//     Queue q2;    
// } MyStack;


// MyStack* myStackCreate()
// {
//     MyStack* pst = (MyStack*)malloc(sizeof(MyStack));
//     //用指针开辟空间，否则使用局部变量会在回传时销毁
//     //不能用全局，多次调用无法解决
    
//     QueueInit(&(pst->q1));
//     QueueInit(&(pst->q2));

//     return pst;
// }

// void myStackPush(MyStack* obj, int x)
// {
//     if(!QueueEmpty(&(obj->q1)))
//     {
//         QueuePush(&(obj->q1), x);
//     }   
//     else
//     {
//         QueuePush(&(obj->q2), x);
//     }
//     //保证有一个队列为空
// }

// int myStackPop(MyStack* obj)
// {
//     //不为空的前size-1个数放入另一个队列，再把第size个数先复制后删除
//     //假设法
//     Queue* empty = &(obj->q1);
//     Queue* NoEmpty = &(obj->q2);
//     if(!QueueEmpty(&(obj->q1)))
//     {
//         empty = NoEmpty;
//         NoEmpty =&(obj->q1);
//     }

//     while(QueueSize(NoEmpty) > 1)
//     {
//         QueuePush(empty, QueueFront(NoEmpty));
//         QueuePop(NoEmpty);
//     }

//     int top = QueueFront(NoEmpty);
//     QueuePop(NoEmpty);

//     return top;
// }

// int myStackTop(MyStack* obj)
// {
//     if(!QueueEmpty(&(obj->q1)))
//     {
//         return QueueBack(&(obj->q1));
//     }
//     else
//     {
//         return QueueBack(&(obj->q2));
//     }

// }

// bool myStackEmpty(MyStack* obj)
// {
//     return QueueEmpty(&(obj->q1)) && QueueEmpty(&(obj->q2));
// }

// void myStackFree(MyStack* obj)
// {
//     QueueDestroy(&(obj->q1));
//     QueueDestroy(&(obj->q2));

//     free(obj);
//     //不能仅free掉obj，否则会导致队列未释放，造成内存泄漏
// }
