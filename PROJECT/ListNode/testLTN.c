
#include<stdio.h>
#include "ListNode.h"
#include "ListNode.c"

int main()
{
    LTNode* phead = LTInit2(); //创建哨兵位

    LTPushBack(phead, 1);
    LTPushBack(phead, 2);
    LTPushBack(phead, 3);
    LTPushBack(phead, 4);
    LTPushBack(phead, 5);

    LTPushFront(phead, 1);
    LTPushFront(phead, 2);
    LTPushFront(phead, 3);
    LTPushFront(phead, 4);

    LTPopBack(phead);
    LTPopFront(phead);

    LTPrint(phead);

    return 0;
}