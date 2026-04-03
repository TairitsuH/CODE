#include "queue.h"
#include "queue.c"

int main()
{
    Queue q;
    QueueInit(&q);

    for(int i=0; i<10; i++)
    {
        QueuePush(&q, i);
        QueuePrint(&q);
    }
    int x = QueueSize(&q);
    int head = QueueFront(&q);
    int tail = QueueBack(&q);
    printf("队列中有%d个数据，其中队头元素为%d，队尾元素为%d。\n", x, head, tail);
    for(int i=0 ;i<5; i++)
    {
        QueuePop(&q);
        QueuePrint(&q); 
    }

    return 0;
}
