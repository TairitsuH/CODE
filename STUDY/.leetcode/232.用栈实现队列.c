/*
 * @lc app=leetcode.cn id=232 lang=c
 *
 * [232] 用栈实现队列
 */

// @lc code=start

typedef struct Stack
{
    int* a;
    int size;
    int capacity;
}Stack;

//初始化
void STInit(Stack* ps)
{
    ps->a = NULL;
    ps->size = 0;
    ps->capacity = 0;
}

//销毁
void STDestroy(Stack* ps)
{
    free(ps->a);
    ps->a = NULL;
    ps->size = 0;
    ps->capacity = 0;
}

//入栈
void STPush(Stack* ps, int val)
{
    assert(ps);
    //判断扩容
    if(ps->size == ps->capacity)
    {
        int newcapacity = ps->capacity == 0 ? 4 : 2*ps->capacity;
        int *tmp = (int*)realloc(ps->a, newcapacity * sizeof(int));

        ps->a = tmp;
        ps->capacity = newcapacity;
    }

    //插入
    ps->a[ps->size++] = val;
}

//出栈
void STPop(Stack* ps)
{
    assert(ps && ps->size > 0);
    ps->size--;
}

//获取栈顶元素
int STTop(Stack* ps)
{
    assert(ps && ps->size > 0);
    return ps->a[ps->size-1];
}

//元素个数
int STSize(Stack* ps)
{
    assert(ps);
    return ps->size;
}

//判空
bool STEmpty(Stack* ps)
{
    assert(ps);
    return ps->size == 0;
}


typedef struct {
    Stack s1;
    Stack s2;
} MyQueue;


MyQueue* myQueueCreate()
{
    MyQueue q;
    MyQueue* pq = &q;
    pq = (MyQueue*)malloc(sizeof(MyQueue));
    STInit(&pq->s1);
    STInit(&pq->s2);
    return pq;
}

void myQueuePush(MyQueue* obj, int x)
{
    assert(obj);
    //假设法
    Stack* Empty = &obj->s1;
    Stack* NotEmpty = &obj->s2;
    if(STEmpty(&obj->s2))
    {
        Empty = NotEmpty;
        NotEmpty = &obj->s1;
    }

    //插入
    STPush(NotEmpty, x);
}

int myQueuePop(MyQueue* obj)
{
    assert(obj && &obj->s1 && &obj->s2);

    //假设法
    Stack* Empty = &obj->s1;
    Stack* NotEmpty = &obj->s2;
    if(STEmpty(&obj->s2))
    {
        Empty = NotEmpty;
        NotEmpty = &obj->s1;
    }

    //删除操作
    //移出前size-1个元素
    for(int i=NotEmpty->size-1; i>0; i--)
    {
        int x = STTop(NotEmpty);
        STPush(Empty, x);
        STPop(NotEmpty);
    }

    //获取并删除
    int num = STTop(NotEmpty);
    STPop(NotEmpty);

    //size-1个元素放回
    for(int i=Empty->size-1; i>=0; i--)
    {
        int x = STTop(Empty);
        STPush(NotEmpty, x);
        STPop(Empty);
    }

    //返回删除的元素
    return num;
}

int myQueuePeek(MyQueue* obj)
{
    assert(obj);
    //假设法
    Stack* Empty = &obj->s1;
    Stack* NotEmpty = &obj->s2;
    if(STEmpty(&obj->s2))
    {
        Empty = NotEmpty;
        NotEmpty = &obj->s1;
    }

    //删除操作
    //移出前size-1个元素
    for(int i=NotEmpty->size-1; i>0; i--)
    {
        int x = STTop(NotEmpty);
        STPush(Empty, x);
        STPop(NotEmpty);
    }

    //获取
    int num = STTop(NotEmpty);

    //size-1个元素放回
    for(int i=Empty->size-1; i>=0; i--)
    {
        int x = STTop(Empty);
        STPush(NotEmpty, x);
        STPop(Empty);
    }

    //返回队头元素
    return num;
}

bool myQueueEmpty(MyQueue* obj)
{
    assert(obj);
    return STEmpty(&obj->s1) && STEmpty(&obj->s2);
}

void myQueueFree(MyQueue* obj)
{
    assert(obj);
    STDestroy(&obj->s1);
    STDestroy(&obj->s2);
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/
// @lc code=end

//一刷：又是几乎一遍过...震惊！！只在一个小地方出了错，但立刻检查并改正了：
//Empty和NotEmpty的size是独立的，一开始把这两个一起考虑了，在循环中写了size-2。改回size-1就过了ヾ(≧▽≦*)o
