/*
 * @lc app=leetcode.cn id=622 lang=c
 *
 * [622] 设计循环队列
 */

// @lc code=start
typedef struct
{
    int* a;
    int head;
    int tail;
    int k;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k)
{
    MyCircularQueue Cirq;
    MyCircularQueue* pq = &Cirq;
    pq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    pq->a = (int*)malloc(sizeof(int)* (k+1));
    pq->head = 0;
    pq->tail = 0;
    pq->k = k;

    return pq;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value)
{
    //满则不能继续插入
    if((obj->tail+1) % (obj->k+1) == obj->head)
    {
        return false;
    }

    obj->a[obj->tail] = value;
    obj->tail = (obj->tail + 1) % (obj->k + 1);
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj)
{
    //空则不能插入
    if(obj->head == obj->tail)
    {
        return false;
    }

    obj->head = obj->head == obj->k ? 0 : obj->head + 1;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj)
{
    if(obj->head == obj->tail)
    {
        return -1;
    }    

    return obj->a[obj->head];
}

int myCircularQueueRear(MyCircularQueue* obj)
{
    //空则不能返回队尾元素
    if(obj->head == obj->tail)
    {
        return -1;
    }

    int tmp = (obj->tail == 0 ? obj->k : obj->tail - 1);
    return obj->a[tmp];
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj)
{
    return obj->head == obj->tail;
}

bool myCircularQueueIsFull(MyCircularQueue* obj)
{
    return (obj->tail+1) % (obj->k+1) == obj->head;

}

void myCircularQueueFree(MyCircularQueue* obj)
{
    free(obj->a);
    obj->a = NULL;
    free(obj);
    obj = NULL;
}



/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/
// @lc code=end

//二刷：没招了，把赋值写成了比较TvT找了好久的bug。为什么没有报错？看来过程还是要严谨！
//一刷：好多需要注意的细节，比如新建的是大小为k+1的数组，但最大下标是k，一不小心就会越界TvT还有取余运算等等，看来画图还是挺重要的
// typedef struct {
//     int* a;
//     int head; //队头元素下标
//     int tail; //队尾元素的下一个位置下标
//     int k;
// } MyCircularQueue;


// MyCircularQueue* myCircularQueueCreate(int k)
// {
//     MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
//     obj->a = (int*)malloc(sizeof(int)*(k+1));
//     obj->head = 0;
//     obj->tail = 0;
//     obj->k = k;
//     return obj;
// }

// bool myCircularQueueEnQueue(MyCircularQueue* obj, int value)
// {
//     if(obj->head == (obj->tail+1) % (obj->k+1))
//     return false;

//     obj->a[obj->tail] = value;
//     obj->tail++;
//     obj->tail = obj->tail % (obj->k + 1);
//     return true;
// }

// bool myCircularQueueDeQueue(MyCircularQueue* obj)
// {
//     if(obj->head == obj->tail)
//     return false;
    
//     obj->head == obj->k ? obj->head = 0 : obj->head++;
//     return true; 
// }

// int myCircularQueueFront(MyCircularQueue* obj)
// {
//     if(obj->head == obj->tail)
//     return -1;

//     return obj->a[obj->head];
// }

// int myCircularQueueRear(MyCircularQueue* obj)
// {
//     if(obj->head == obj->tail)
//     return -1;

//     return obj->tail == 0 ? obj->a[obj->k] : obj->a[obj->tail-1];
// }

// bool myCircularQueueIsEmpty(MyCircularQueue* obj)
// {
//     return obj->head == obj->tail;
// }

// bool myCircularQueueIsFull(MyCircularQueue* obj)
// {
//     return (obj->tail + 1) % (obj->k + 1) == obj->head;    
// }

// void myCircularQueueFree(MyCircularQueue* obj)
// {
//     free(obj->a);
//     obj->a = NULL;
//     free(obj);
//     obj = NULL;
// }

