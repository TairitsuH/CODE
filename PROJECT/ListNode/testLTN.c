
#include<stdio.h>
#include "ListNode.h"
#include "ListNode.c"

int main()
{
    LTNode* phead = LTInit2();

    LTPushBack(phead, 1);
    LTPushBack(phead, 2);
    LTPushBack(phead, 3);
    LTPushBack(phead, 4);
    LTPushBack(phead, 5);

    LTPrint(phead);

    return 0;
}